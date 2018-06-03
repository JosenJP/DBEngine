#ifndef DB_ISSUE_HPP
#define DB_ISSUE_HPP

#include "DBEngine.hpp"
#include "TBL_Issues.hpp"

class DBENGINECLASS DBIssues : public DBEngine
{
public:
    DBIssues();
    ~DBIssues();

    bool Insert(void* a_pRecord) override;
    bool Delete(void* a_pKey, int a_KeyNum) override;
    bool Update(void* a_pRecord, void* a_pKey, int a_KeyNum) override;
    bool Query(void* a_pKey, int a_KeyNum) override;
    std::string GetWhereStatement(void* a_pKey, int a_KeyNum) override;
};

#endif
