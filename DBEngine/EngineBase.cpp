#include <iostream>

#include "EngineBase.hpp"
#include "ConverterBase.hpp"

const int MAX_OUT_CONN_STR_LEN = 255;

EngineBase::EngineBase()
{
    Init();
}

EngineBase::~EngineBase()
{
    FreeSTMT();

    if (NULL != m_hDBC)
    {
        SQLDisconnect(m_hDBC);
        SQLFreeHandle(SQL_HANDLE_DBC, m_hDBC);
        m_hDBC = NULL;
    }

    if (NULL != m_hEnv)
    {
        SQLFreeHandle(SQL_HANDLE_ENV, m_hEnv);
        m_hEnv = NULL;
    }
}

void EngineBase::Init()
{
    m_hEnv  = NULL;
    m_hDBC  = NULL;
    m_hSTMT = NULL;

    m_IsConnected = false;
}

bool EngineBase::IsOK(SQLRETURN a_Rc)
{
    return ((SQL_SUCCESS == a_Rc) || (SQL_SUCCESS_WITH_INFO == a_Rc));
}

bool EngineBase::Connect(SQLCHAR* a_pConnStr)
{
    SQLCHAR     l_OutConnStr[MAX_OUT_CONN_STR_LEN];
    SQLSMALLINT l_OutConnStrLen = 0;
    SQLRETURN   l_Rc = SQL_SUCCESS;

    memset(l_OutConnStr, 0, MAX_OUT_CONN_STR_LEN);

    if (m_IsConnected)
    {
        return true;
    }

    // Allocate environment handle
    l_Rc = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &m_hEnv);

    // Set the ODBC version environment attribute
    if (IsOK(l_Rc))
    {
        l_Rc = SQLSetEnvAttr(m_hEnv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0);

        // Allocate connection handle
        if (IsOK(l_Rc))
        {
            l_Rc = SQLAllocHandle(SQL_HANDLE_DBC, m_hEnv, &m_hDBC);

            // Set login timeout to 5 seconds
            if (IsOK(l_Rc))
            {
                SQLSetConnectAttr(m_hDBC, SQL_LOGIN_TIMEOUT, (SQLPOINTER)5, 0);

                // Connect to data source
                l_Rc = SQLDriverConnect(m_hDBC,                       //ConnectionHandle
                                        NULL,                         //WindowHandle
                                        a_pConnStr,                   //InConnectionString
                                        strlen((char *)a_pConnStr),   //StringLength1
                                        l_OutConnStr,                 //OutConnectionString
                                        MAX_OUT_CONN_STR_LEN,         //BufferLength
                                        &l_OutConnStrLen,             //StringLength2Ptr
                                        SQL_DRIVER_COMPLETE);         //DriverCompletion
            }
        }
    }

    m_IsConnected = IsOK(l_Rc);

    return m_IsConnected;
}

bool EngineBase::Execute(string a_SqlStatement, DBAction a_DBAction)
{
    SQLRETURN l_Rc = SQL_SUCCESS;

    if (!m_IsConnected)
    {
        return false;
    }

    l_Rc = SQLAllocHandle(SQL_HANDLE_STMT, m_hDBC, &m_hSTMT);
    if (!IsOK(l_Rc))
    {
        PrintError();
    }

    l_Rc = SQLExecDirect(m_hSTMT, (SQLCHAR*)a_SqlStatement.c_str(), SQL_NTS);
    if (SQL_SUCCESS != l_Rc)
    {
        PrintError();
    }

    if (DBAction::Query != a_DBAction)
    {
        FreeSTMT();
    }

    return (SQL_SUCCESS == l_Rc);
}

bool EngineBase::GetRecord(void* a_pRecord, ConverterBase* a_pConverter)
{
    SQLRETURN l_Rc = SQL_SUCCESS;

    l_Rc = SQLFetch(m_hSTMT);

    if ((SQL_SUCCESS == l_Rc) && (NULL != a_pConverter))
    {
        a_pConverter->Convert(a_pRecord, m_hSTMT);
    }

    if (SQL_NO_DATA == l_Rc)
    {
        FreeSTMT(); //Free the STMT after all the data loaded.
    }

    return (SQL_SUCCESS == l_Rc);
}

void EngineBase::PrintError(void)
{
    SQLCHAR       l_SqlState[6];
    memset(l_SqlState, 0, sizeof(l_SqlState));
    SQLCHAR       l_Msg[SQL_MAX_MESSAGE_LENGTH];
    memset(l_Msg, 0, sizeof(l_Msg));
    SQLINTEGER    l_NativeError     = 0;
    SQLSMALLINT   l_MsgLen          = 0;
    SQLRETURN     l_Rc              = SQL_SUCCESS;
    SQLLEN        l_NumRecs         = 0;

    SQLGetDiagField(SQL_HANDLE_STMT, m_hSTMT, 0, SQL_DIAG_NUMBER, &l_NumRecs, 0, 0);
    for (SQLSMALLINT i = 1;  i <= l_NumRecs && ((l_Rc = SQLGetDiagRec(SQL_HANDLE_STMT, m_hSTMT, i, l_SqlState, &l_NativeError, l_Msg, sizeof(l_Msg), &l_MsgLen)) != SQL_NO_DATA); i++)
    {
        std::cout << l_Msg << std::endl;
    }
}

void EngineBase::FreeSTMT(void)
{
    if (NULL != m_hSTMT)
    {
        SQLFreeHandle(SQL_HANDLE_STMT, m_hSTMT);
        m_hSTMT = NULL;
    }
}
