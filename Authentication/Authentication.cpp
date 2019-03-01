//
// Created by machado on 01/03/19.
//

#include "Authentication.h"

Authentication::Authentication(BaseAuthentication *authenticationService)
{
    this->authenticationService = authenticationService;
}

AuthenticationResult Authentication::authenticate(const std::string &username, const std::string &password)
{
    return authenticationService->authenticate(username, password);
}

Authentication::~Authentication()
{
    delete authenticationService;
    authenticationService = nullptr;
}
