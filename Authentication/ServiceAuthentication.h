//
// Created by machado on 28/02/19.
//

#ifndef SERVICE_AUTHENTICATION_H
#define SERVICE_AUTHENTICATION_H

#include "BaseAuthentication.h"
#include "AuthenticationResult.h"

class ServiceAuthentication : public BaseAuthentication
{
public:
    ~ServiceAuthentication() override;

    AuthenticationResult authenticate(const std::string &username, const std::string &password) override;


};


#endif //SERVICE_AUTHENTICATION_H
