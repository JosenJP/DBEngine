#ifndef HEALTHY_HPP
#define HEALTHY_HPP

#include <string>

class Healthy
{
public:
    Healthy() { m_ErrorCode = 0; m_ErrorMessage = ""; }
    ~Healthy() {}

protected:
    void SetErrorCode(long a_ErrorCode) { m_ErrorCode = a_ErrorCode; }
    long GetErrorCode(void) { return m_ErrorCode; }

    void SetErrorMessage(std::string a_ErrMsg) { m_ErrorMessage.append(a_ErrMsg); }
    std::string GetErrorMessage(void) { return m_ErrorMessage; }

private:
    long m_ErrorCode;
    std::string m_ErrorMessage;
};

#endif // !HEALTHY_HPP

