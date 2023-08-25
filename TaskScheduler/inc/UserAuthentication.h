#ifndef __USER_AUTHENTICATION_H__
#define __USER_AUTHENTICATION_H__

#include "common.h"

class Authentication {
    public:
        enum AuthenRetCode {
            FAILED  =   0,
            SUCCESS
        };

    public:
        Authentication();
        ~Authentication();
        AuthenRetCode setPassword(const char*, const int);
        char* getPassword();
        void setIsAuthen(const bool);
        bool getIsAuthen();
        AuthenRetCode verifyPassword(const char*, const int);
    private:
        char* m_password;
        int m_size;
        bool m_isAuthen;
};

#endif /* __USER_AUTHENTICATION_H__ */