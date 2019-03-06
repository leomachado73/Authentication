//
// Created by machado on 28/02/19.
//

#ifndef AUTHENTICATION_RESULT_H
#define AUTHENTICATION_RESULT_H

#include <string>
#include <ostream>

/*

LOGIN RESULT DOMAIN

-6 = Tempo limite excedido
-5 = Tempo limite excedido
-4 = Conta já está logada.
-3 = Conta bloqueada.
-2 = Senha incorreta.
-1 = Conta incorreta.
0 = Não foi possível conectar
1 = Logado com sucesso

*/

enum LoginResult
{
    TIME_LIMIT_EXCEED = -5,
    ACCOUNT_LOGGED = -4,
    ACCOUNT_BLOCKED = -3,
    WRONG_PASSWORD = -2,
    WRONG_USERNAME = -1,
    FAILED = 0,
    SUCCESS = 1
};

class UserResult
{
private:
    std::string uuid;
    std::string username;
    int authorizationId;
    bool banned;

public:
    UserResult()
    {
    }

    UserResult(const std::string &uuid, const std::string &username, int authorizationId, bool banned)
    {
        this->uuid = uuid;
        this->username = username;
        this->authorizationId = authorizationId;
        this->banned = banned;
    }

    const std::string &getUuid() const
    {
        return uuid;
    }

    void setUuid(const std::string &uuid)
    {
        UserResult::uuid = uuid;
    }

    const std::string &getUsername() const
    {
        return username;
    }

    void setUsername(const std::string &username)
    {
        UserResult::username = username;
    }

    int getAuthorizationId() const
    {
        return authorizationId;
    }

    void setAuthorizationId(int authorizationId)
    {
        UserResult::authorizationId = authorizationId;
    }

    bool getBanned() const
    {
        return banned;
    }

    void setBanned(bool banned)
    {
        UserResult::banned = banned;
    }

    friend std::ostream &operator<<(std::ostream &os, const UserResult &result)
    {
        os << "uuid: " << result.uuid << std::endl
           << "username: " << result.username << std::endl
           << "authorizationId: " << result.authorizationId << std::endl
           << "banned: " << result.banned << std::endl;
        return os;
    }


};

class AuthenticationResult
{
private:
    LoginResult login;
    UserResult user;
    std::string error;

public:
    AuthenticationResult()
    {
        this->login = LoginResult::FAILED;
        this->error = "";
    }

    LoginResult getLoginResult() const
    {
        return login;
    }

    void setLogin(LoginResult login)
    {
        AuthenticationResult::login = login;
    }

    const UserResult &getUser() const
    {
        return user;
    }

    void setUser(const UserResult &user)
    {
        AuthenticationResult::user = user;
    }

    const std::string &getError() const
    {
        return error;
    }

    void setError(const std::string &error)
    {
        AuthenticationResult::error = error;
    }
};


#endif //AUTHENTICATION_RESULT_H
