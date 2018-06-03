#ifndef DB_ENGINE_FACTORY_HPP
#define DB_ENGINE_FACTORY_HPP

#include "DBInfo.hpp"
class EngineBase;

class DBEngineFactory
{
public:
    static EngineBase* GetDBEngine(DBType a_DBType);
};

#endif // !DB_ENGINE_FACTORY_HPP

