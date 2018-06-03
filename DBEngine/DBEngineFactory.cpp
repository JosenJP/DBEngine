#include <memory>

#include "DBEngineFactory.hpp"
#include "EngineBase.hpp"
#include "EngineSqlServer.hpp"

EngineBase* DBEngineFactory::GetDBEngine(DBType a_DBType)
{
    EngineBase* l_pEngine = NULL;
    static std::unique_ptr<EngineSqlServer> s_pEngineSqlServer;
    
    switch (a_DBType)
    {
    case DBType::SQL_SERVER:
    {
        if (!s_pEngineSqlServer)
        {
            s_pEngineSqlServer = std::make_unique<EngineSqlServer>();
        }

        l_pEngine = s_pEngineSqlServer.get();
        break;
    }
    case DBType::MYSQL:
    {
        break;
    }
    default:
        break;
    }


    return l_pEngine;
}

