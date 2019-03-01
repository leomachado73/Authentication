//
// Created by machado on 28/02/19.
//

#ifndef BASE_AUTHENTICATION_H
#define BASE_AUTHENTICATION_H

#include <string>

#include "AuthenticationResult.h"

class BaseAuthentication
{
private:
    // Logger logger = Logger.factory("BaseAuthentication"); -- To be implemented in the future

public:
    virtual ~BaseAuthentication()
    {};

    virtual AuthenticationResult authenticate(const std::string &username, const std::string &password) = 0;
};

#endif //BASE_AUTHENTICATION_H
