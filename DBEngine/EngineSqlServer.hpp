#ifndef ENGINE_SQL_SERVER_HPP
#define ENGINE_SQL_SERVER_HPP
#include "EngineBase.hpp"

class EngineSqlServer : public EngineBase
{
public:
    EngineSqlServer();
    ~EngineSqlServer();

    void BeginTransaction() override;
    void EndTransaction() override;
    void AboutTransaction() override;
    bool Execute(string a_SqlStatement, DBAction a_DBAction) override;

private:
    void Init();

    char* m_pConnectStr;
};

#endif // !ENGINE_SQL_SERVER_HPP
