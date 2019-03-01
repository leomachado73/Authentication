//
// Created by machado on 01/03/19.
//

#ifndef DEV_AUTHENTICATION_H
#define DEV_AUTHENTICATION_H

#include "BaseAuthentication.h"
#include "AuthenticationResult.h"

class DevAuthentication : public BaseAuthentication
{
public:
    ~DevAuthentication() override;

    AuthenticationResult authenticate(const std::string &username, const std::string &password) override;

};


#endif //DEV_AUTHENTICATION_H