#ifndef ENGINE_MYSQL_HPP
#define ENGINE_MYSQL_HPP

#include <STDAFX.hpp>
#include <atomic>
#include <mysql_connection.h>
#include <cppconn\driver.h>
#include <cppconn\exception.h>
#include <cppconn\resultset.h>
#include <cppconn\statement.h>
#include <memory>
#include "EngineBase.hpp"
using namespace std;

class EngineMySql : public EngineBase
{
public:
    EngineMySql();
    ~EngineMySql();

//    virtual void BeginTransaction();
//    virtual void EndTransaction();
//    virtual void AboutTransaction();
//    virtual bool Execute(string a_SqlStatement);
//
//    //static void InitSource();
//    static void ReleaseSource();
//
//private:
//    //The DB object should be initialized only once, as they should be shared all the time of the programming.
//    static sql::Driver*         m_pDriver;
//    static sql::Connection*     m_pConnection;
//    static sql::Statement*      m_pStatment;
//    static sql::ResultSet*      m_pResult;

    //static atomic_flag m_DBInitFlag; //This flag is to make sure the Db objects are not initialized repeatly.
};

#endif // !ENGINE_MYSQL_HPP

