#include <iostream>

#include <EngineSqlServer.hpp>
#include <DB_Issues.hpp>
using namespace std;

//void TestDBEngine();
void TestTableIssueQuery();
void TestTableIssueInsert();
void TestTableIssueUpdate();
void TestTableIssueDelete();

int main()
{
    //TestDBEngine();
    TestTableIssueQuery();

    TestTableIssueInsert();
    TestTableIssueQuery();

    TestTableIssueUpdate();
    TestTableIssueQuery();

    TestTableIssueDelete();
    TestTableIssueQuery();

    system("pause");
}

//void TestDBEngine()
//{
//    EngineBase* l_pDBEngine = new EngineSqlServer();
//
//    const string l_SqlStatement = "select * from issues;";
//
//    l_pDBEngine->Execute(l_SqlStatement);
//
//    delete l_pDBEngine;
//}

void TestTableIssueQuery()
{
    bool l_IsOK = 0;
    DBIssues l_DBIssue;
    Issues l_Issue;
    int l_IssueID = 2;

    if (l_DBIssue.Query(&l_IssueID, 0))
    {
        cout << "Current Records: " << endl;

        while (l_DBIssue.GetRecord(&l_Issue))
        {
            cout << "Issue ID: " << l_Issue.ID << " "
                 << "Description: " << l_Issue.Desc << endl;
        }

        cout << endl;
    }
}

void TestTableIssueInsert()
{
    bool l_IsOK = 0;
    DBIssues l_DBIssue;
    Issues l_Issue;
    memset(&l_Issue, 0, sizeof(Issues));

    char* l_pDesc = "Test3";
    l_Issue.ID = 3;
    memcpy_s(l_Issue.Desc, strlen(l_pDesc), l_pDesc, strlen(l_pDesc));

    l_IsOK = l_DBIssue.Insert(&l_Issue);

    if (l_IsOK)
    {
        cout << "Successfully Insert" << endl;

        cout << "Issue ID: " << l_Issue.ID << " "
            << "Description: " << l_Issue.Desc << endl;
    }
    else
    {
        cout << "failed to Insert" << endl;
    }
}

void TestTableIssueUpdate()
{
    bool l_IsOK = 0;
    DBIssues l_DBIssue;
    Issues l_Issue;
    memset(&l_Issue, 0, sizeof(Issues));

    char* l_pDesc = "Test3updated";
    l_Issue.ID = 3;
    memcpy_s(l_Issue.Desc, strlen(l_pDesc), l_pDesc, strlen(l_pDesc));

    l_IsOK = l_DBIssue.Update(&l_Issue, &l_Issue.ID, 1);

    if (l_IsOK)
    {
        cout << "Successfully Update" << endl;

        cout << "Issue ID: " << l_Issue.ID << " "
            << "Description: " << l_Issue.Desc << endl;
    }
    else
    {
        cout << "failed to Update" << endl;
    }
}

void TestTableIssueDelete()
{
    bool l_IsOK = 0;
    DBIssues l_DBIssue;

    int l_IssueID = 3;

    l_IsOK = l_DBIssue.Delete(&l_IssueID, 1);

    if (l_IsOK)
    {
        cout << "Successfully delete" << endl;

        cout << "Issue ID: " << l_IssueID << endl;
    }
    else
    {
        cout << "failed to Update" << endl;
    }
}

