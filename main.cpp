#include <iostream>
#include <exception>
#include <cpr/cpr.h>
#include <json.hpp>

#include "Authentication/Authentication.h"
#include "Authentication/ServiceAuthentication.h"
#include "Authentication/DevAuthentication.h"

using namespace std;


AuthenticationResult login(const std::string &username, const std::string &password)
{
    Authentication authService(new ServiceAuthentication());

    return authService.authenticate(username, password);
}

int main(int argc, char **argv)
{
    AuthenticationResult result = login("admin", "123456");

    if (result.getLoginResult() == LoginResult::SUCCESS)
    {
        cout << result.getUser() << endl;
    }
    else
    {
        cout << "Error: " << result.getError() << endl;
    }

    return 0;
}
