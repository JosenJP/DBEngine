#include "EngineSqlServer.hpp"

EngineSqlServer::EngineSqlServer()
{
    Init();
}

EngineSqlServer::~EngineSqlServer()
{
}

void EngineSqlServer::Init()
{
    m_pConnectStr = "SERVER=JOSEN;UID=Josen;PWD=jiang891203;DATABASE=issuelog;DRIVER={SQL Server Native Client 11.0};";
}

void EngineSqlServer::BeginTransaction()
{
}

void EngineSqlServer::EndTransaction()
{
}

void EngineSqlServer::AboutTransaction()
{
}

bool EngineSqlServer::Execute(string a_SqlStatement, DBAction a_DBAction)
{
    bool l_IsOK = true;

    //Connect to the database.
    SQLCHAR* l_pConnectionStr = (SQLCHAR*)m_pConnectStr;
    l_IsOK = Connect(l_pConnectionStr);

    //Execute the sql statement
    if (l_IsOK)
    {
        l_IsOK = EngineBase::Execute(a_SqlStatement, a_DBAction);
    }

    return l_IsOK;
}
