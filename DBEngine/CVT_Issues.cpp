#include "CVT_Issues.hpp"
#include "TBL_Issues.hpp"
#include <iostream>

void CVTIssues::Convert(void* a_Record, SQLHENV a_hSTMT)
{
    Issues* l_pIssue = (Issues*)a_Record;
    memset(l_pIssue, 0, sizeof(Issues));
    SQLLEN l_Len = 0;

    SQLGetData(a_hSTMT, 1, SQL_C_ULONG, &l_pIssue->ID, 0, &l_Len);
    SQLGetData(a_hSTMT, 2, SQL_C_CHAR, &l_pIssue->Desc, MAX_DESC_LEN, &l_Len);

}
