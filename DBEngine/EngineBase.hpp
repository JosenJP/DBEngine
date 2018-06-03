#ifndef ENGINE_BASE_HPP
#define ENGINE_BASE_HPP

#include <STDAFX.hpp>
#include <windows.h>
#include <sql.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <string>

#include "Healthy.hpp"
#include "DBInfo.hpp"

using namespace std;
class ConverterBase;

class EngineBase : public Healthy
{
public:
    EngineBase();
    virtual ~EngineBase();

    bool Connect(SQLCHAR* a_pConnStr);
    virtual void BeginTransaction() {}
    virtual void EndTransaction() {}
    virtual void AboutTransaction() {}
    virtual bool Execute(string a_SqlStatement, DBAction a_DBAction);
    virtual bool GetRecord(void* a_pRecord /* output */, ConverterBase* a_pConverter);

private:
    void Init();
    bool IsOK(SQLRETURN a_Rc);
    void PrintError(void);
    void FreeSTMT(void);

    //ODBC handles
    SQLHENV m_hEnv;
    SQLHDBC m_hDBC;
    SQLHSTMT m_hSTMT;

    bool m_IsConnected;
};

#endif
