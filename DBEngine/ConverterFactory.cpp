#include <memory>

#include "ConverterFactory.hpp"
#include "TableNames.hpp"
#include "CVT_Issues.hpp"

typedef std::map<std::string, ConverterBase*>::iterator CVTIt;
typedef std::pair<std::string, ConverterBase*> CVTPair;

std::map<std::string, ConverterBase*> ConverterFactory::s_CoverterMap = {};

ConverterBase* ConverterFactory::GetConverter(const char* a_pTableName) /* static */
{
    ConverterBase* l_pConverter = NULL;

    //Try to get the converter from the converter cache
    CVTIt l_It = s_CoverterMap.find(a_pTableName);
    if (s_CoverterMap.end() != l_It)
    {
        return l_It->second;
    }

    if (0 == memcmp(a_pTableName, TableNames::ISSUES, strlen(TableNames::ISSUES)))
    {
        l_pConverter = new CVTIssues();
    }

    if (NULL != l_pConverter) //Make sure there is a converter existed.
    {
        s_CoverterMap.insert(CVTPair(a_pTableName, l_pConverter));
    }

    return l_pConverter;
}

void ConverterFactory::ReleaseMemory(void) /* static */
{
    for (CVTPair l_Pair : s_CoverterMap)
    {
        if (NULL != l_Pair.second)
        {
            delete l_Pair.second;
            l_Pair.second = NULL;
        }
    }
}
