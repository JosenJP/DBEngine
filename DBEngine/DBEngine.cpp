#include "DBEngine.hpp"
#include "ConverterFactory.hpp"
#include "DBEngineFactory.hpp"
#include "EngineBase.hpp"

DBEngine::DBEngine(void)
{
    Init();
}

DBEngine::~DBEngine()
{
}

void DBEngine::Init()
{
    m_DBType        = DBType::SQL_SERVER;
    m_pEngine       = NULL;
    m_pConverter    = NULL;
}

bool DBEngine::Execute(std::string a_SqlStatement, DBAction a_DBAction)
{
    bool l_IsOK = true;

    m_pEngine = DBEngineFactory::GetDBEngine(m_DBType);
    if (NULL != m_pEngine)
    {
        l_IsOK = m_pEngine->Execute(a_SqlStatement, a_DBAction);
    }

    return l_IsOK;
}

bool DBEngine::GetRecord(void* a_pRecord /* Output */)
{
    if (NULL == m_pEngine)
    {
        return false;
    }

    m_pConverter = ConverterFactory::GetConverter(m_pTableName);
    if (NULL == m_pConverter)
    {
        return false;
    }

    return m_pEngine->GetRecord(a_pRecord, m_pConverter);
}

