#ifndef CONVERTER_FACTORY_HPP
#define CONVERTER_FACTORY_HPP

#include <map>

#include "ConverterBase.hpp"

class ConverterFactory
{
public:
    static ConverterBase* GetConverter(const char* a_pTableName);
    static void ReleaseMemory(void);

private:
    static std::map<std::string, ConverterBase*> s_CoverterMap;
};


#endif // !CONVERTER_FACTORY_HPP

