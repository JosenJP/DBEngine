#ifndef CVT_ISSUES_HPP
#define CVT_ISSUES_HPP

#include "ConverterBase.hpp"

class CVTIssues : public ConverterBase
{
public:
    void Convert(void* a_pRecord, SQLHENV a_hSTMT) override;
};

#endif // !CVT_ISSUES_HPP

