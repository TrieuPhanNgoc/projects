#include "UserAuthentication.h"

#define LOG_PASSWORD(msg) \
    std::cout << "Password: " << msg << std::endl; \

Authentication::Authentication()
: m_password(nullptr), m_size(0), m_isAuthen(false)
{
}

Authentication::~Authentication() {}

Authentication::AuthenRetCode Authentication::setPassword(const char* pass, const int size) {
    if (pass == nullptr || size <= 0) {
        setIsAuthen(false);
        return Authentication::AuthenRetCode::FAILED;
    }

    if (m_password == nullptr) {
        m_size = size;
        m_password = new char[m_size];
    }

    memset(m_password, '\0', m_size);
    memcpy(m_password, pass, m_size);
    setIsAuthen(true);
    LOG_PASSWORD(m_password);

    return Authentication::AuthenRetCode::SUCCESS;
}

char* Authentication::getPassword() {
    return m_password;
}

void Authentication::setIsAuthen(const bool status) {
    if (m_isAuthen == status) {
        return;
    }
    m_isAuthen = status;
}

bool Authentication::getIsAuthen() {
    return m_isAuthen;
}

Authentication::AuthenRetCode Authentication::verifyPassword(const char* pass, const int size) {
    if (pass == nullptr || size <= 0 || m_size != size) {
        return Authentication::AuthenRetCode::FAILED;
    }

    if (memcmp(m_password, pass, m_size) == 0) {
        setIsAuthen(false);
        LOG_PASSWORD(m_password);
        return Authentication::AuthenRetCode::SUCCESS;
    }   

    return Authentication::AuthenRetCode::FAILED;
}