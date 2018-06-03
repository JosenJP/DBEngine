#ifndef DB_INFO_HPP
#define DB_INFO_HPP

enum DBType
{
    SQL_SERVER = 1,
    MYSQL = 2
};

enum DBAction
{
    Insert = 0,
    Delete = 1,
    Update = 2,
    Query = 3
};

const int MAX_TABLE_NAME_LEN = 20;
const int MAX_DESC_LEN = 1000;

#endif // !TABLE_INFO_HPP


