#ifndef DB_ENGINE_HPP
#define DB_ENGINE_HPP
#include <STDAFX.hpp>
#include <string>
#include "DBInfo.hpp"

class EngineBase;
class ConverterBase;

class DBENGINECLASS DBEngine
{
public:
    DBEngine(void);
    virtual ~DBEngine();

    virtual bool Insert(void* a_pRecord) = 0;
    virtual bool Delete(void* a_pKey, int a_KeyNum) = 0;
    virtual bool Update(void* a_pRecord, void* a_pKey, int a_KeyNum) = 0;
    virtual bool Query(void* a_pKey, int a_KeyNum) = 0;
    virtual std::string GetWhereStatement(void* a_pKey, int a_KeyNum) = 0;

    bool GetRecord(void* a_pRecord /* Output */);

protected:
    bool Execute(std::string a_SqlStatement, DBAction a_DBAction);

    const char* m_pTableName;

private:
    void Init(void);

    DBType m_DBType;
    //Database Object to execute the database operation
    EngineBase* m_pEngine;

    //Convert table data to table struct.
    ConverterBase* m_pConverter;
};

#endif // !DB_ENGINE_HPP
