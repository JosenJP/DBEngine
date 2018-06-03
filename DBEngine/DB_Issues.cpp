#include <assert.h>

#include "DB_Issues.hpp"
#include "TableNames.hpp"

DBIssues::DBIssues()
{
    m_pTableName = TableNames::ISSUES;
}

DBIssues::~DBIssues()
{
}

bool DBIssues::Insert(void* a_pRecord)
{
    Issues* l_pIssue = (Issues*)a_pRecord;

    std::string l_Statement = "";

    l_Statement.append("insert into ").append(TableNames::ISSUES).append(" ");
    l_Statement.append("values(");
    l_Statement.append(std::to_string(l_pIssue->ID));
    l_Statement.append(",");
    l_Statement.append("\'").append(l_pIssue->Desc).append("\'");
    l_Statement.append(")");

    return Execute(l_Statement, DBAction::Insert);
}

bool DBIssues::Delete(void* a_pKey, int a_KeyNum)
{
    std::string l_Statement = "";

    l_Statement.append("delete from ").append(TableNames::ISSUES);

    //Stop deleting all the table records.
    if (0 == a_KeyNum)
    {
        return false;
    }

    if (a_KeyNum > 0)
    {
        std::string l_WhereStatement = GetWhereStatement(a_pKey, a_KeyNum);
        l_Statement.append(" ").append(l_WhereStatement);
    }

    return Execute(l_Statement, DBAction::Delete);
}

bool DBIssues::Update(void* a_pRecord, void* a_pKey, int a_KeyNum)
{
    std::string l_Statement = "";
    Issues* l_pIssue = (Issues*)a_pRecord;

    l_Statement.append("update ").append(TableNames::ISSUES).append(" ");
    l_Statement.append("set issueDesc = ");
    l_Statement.append("\'").append(l_pIssue->Desc).append("\'");

    //Stop updating all the table records.
    if (0 == a_KeyNum)
    {
        return false;
    }

    if (a_KeyNum > 0)
    {
        std::string l_WhereStatement = GetWhereStatement(a_pKey, a_KeyNum);
        l_Statement.append(" ").append(l_WhereStatement);
    }

    return Execute(l_Statement, DBAction::Update);
}


bool DBIssues::Query(void* a_pKey, int a_KeyNum)
{
    std::string l_Statement = "";

    l_Statement.append("select * from ").append(TableNames::ISSUES);

    if (a_KeyNum > 0)
    {
        std::string l_WhereStatement = GetWhereStatement(a_pKey, a_KeyNum);
        l_Statement.append(" ").append(l_WhereStatement);
    }

    return Execute(l_Statement, DBAction::Query);
}

std::string DBIssues::GetWhereStatement(void* a_pKey, int a_KeyNum)
{
    std::string l_WhereStatement = "where ";

    switch (a_KeyNum)
    {
    case 1:
    {
        l_WhereStatement.append("idIssue = ").append(std::to_string(*((int*)a_pKey)));
        break;
    }
    default:
        break;
    }

    return l_WhereStatement;
}
