#include "EngineMySql.hpp"

//sql::Driver*         EngineMySql::m_pDriver = NULL;
//sql::Connection*     EngineMySql::m_pConnection = NULL;
//sql::Statement*      EngineMySql::m_pStatment = NULL;
//sql::ResultSet*      EngineMySql::m_pResult = NULL;

EngineMySql::EngineMySql()
{
}

EngineMySql::~EngineMySql()
{
}
//
//void EngineMySql::BeginTransaction()
//{
//}
//
//void EngineMySql::EndTransaction()
//{
//
//}
//
//void EngineMySql::AboutTransaction()
//{
//
//}
//
//bool EngineMySql::Execute(string a_SqlStatement)
//{
//    bool l_IsSuccess = false;
//    bool l_IsQuery = false;
//
//    try
//    {
//        if (!m_pDriver)
//        {
//            m_pDriver = get_driver_instance();
//        }
//
//        if (NULL == m_pConnection)
//        {
//            m_pConnection = m_pDriver->connect("tcp://127.0.0.1:3306", "Jiang", "Josen1203");
//            m_pConnection->setSchema("issuelog");
//        }
//
//        if (NULL == m_pStatment)
//        {
//            m_pStatment = m_pConnection->createStatement();
//        }
//
//        l_IsQuery = m_pStatment->executeQuery(a_SqlStatement);
//
//        if (l_IsQuery)
//        {
//            m_pResult = m_pStatment->getResultSet();
//        }
//        else
//        {
//            uint64_t l_Count = m_pStatment->getUpdateCount();
//            if (l_Count > 0)
//            {
//                l_IsSuccess = true;
//            }
//        }
//    }
//    catch (const sql::SQLException& ex)
//    {
//        cout << "SQL Exception: " << ex.what() << endl;
//    }
//
//    return l_IsSuccess;
//}
//
//void EngineMySql::ReleaseSource()
//{
//    if (NULL != m_pConnection)
//    {
//        if (false == m_pConnection->isClosed())
//        {
//            m_pConnection->close();
//        }
//        delete m_pConnection;
//        m_pConnection = NULL;
//    }
//
//    if (NULL != m_pStatment)
//    {
//        delete m_pStatment;
//        m_pStatment = NULL;
//    }
//
//    if (NULL != m_pResult)
//    {
//        delete m_pStatment;
//        m_pStatment = NULL;
//    }
//}
