#ifndef CONVERTER_BASE_HPP
#define CONVERTER_BASE_HPP

#include <windows.h>
#include <sql.h>
#include <sqlext.h>
#include <sqltypes.h>

class ConverterBase
{
public:
    virtual void Convert(void* a_pRecord, SQLHENV a_hSTMT) = 0;
};

#endif // !CONVERTER_BASE_HPP

