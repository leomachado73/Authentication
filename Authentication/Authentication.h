//
// Created by machado on 01/03/19.
//

#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H

#include <string>
#include "BaseAuthentication.h"


class Authentication
{
private:
    BaseAuthentication *authenticationService;


public:
    Authentication(BaseAuthentication *authenticationService);
    virtual ~Authentication();

    AuthenticationResult authenticate(const std::string &username, const std::string &password);
};


#endif // AUTHENTICATION_H
