//
// Created by machado on 01/03/19.
//

#include "DevAuthentication.h"


DevAuthentication::~DevAuthentication()
{

}

AuthenticationResult DevAuthentication::authenticate(const std::string &username, const std::string &password)
{
    AuthenticationResult result;
    UserResult user;

    user.setUuid("");
    user.setUsername(username);
    user.setAuthorizationId(6);
    user.setBanned(0);

    result.setUser(user);
    result.setError("");
    result.setLogin(LoginResult::SUCCESS);

    return result;
}
