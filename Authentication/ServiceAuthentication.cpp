//
// Created by machado on 28/02/19.
//

#include <string>
#include <exception>
#include <cpr/cpr.h>
#include <json.hpp>
#include <jwt.h>
#include "ServiceAuthentication.h"
#include "AuthenticationResult.h"
#include "AuthenticationException.h"

using namespace std;
using namespace nlohmann;

const std::string ENDPOINT_ACCOUNT_SERVICE = "http://127.0.0.1:3000";

ServiceAuthentication::~ServiceAuthentication()
{
}

AuthenticationResult ServiceAuthentication::authenticate(const std::string &username, const std::string &password)
{
    AuthenticationResult result;

    try
    {
        auto response = cpr::Post(cpr::Url{ ENDPOINT_ACCOUNT_SERVICE + "/account/login" }, // Route to Login
                                  cpr::Timeout{ 2 * 1000 }, // Throw exception if server does not send a response in 2 seconds
                                  cpr::Authentication{ username, password }); // Username and Password to Log In

        // Throw exception if something went wrong with the request. For example: ENDPOINT refused the connection
        if (response.error)
        {
            throw AuthenticationException(response.error.message);
        }
        else
        {
            switch (response.status_code)
            {
                case 200:
                    result.setLogin(LoginResult::SUCCESS);
                    break;
                case 401:
                    result.setLogin(LoginResult::WRONG_USERNAME);
                    break;
                case 500:
                    result.setLogin(LoginResult::FAILED);
                    break;
                default:
                    result.setLogin(LoginResult::FAILED);
                    break;
            }

            auto response_json = json::parse(response.text);

            if (result.getLoginResult() == LoginResult::SUCCESS)
            {
                auto jwt = jwt::decode(response_json["data"]);
                auto payload = json::parse(jwt.get_payload());

                UserResult user(payload["uuid"].get<std::string>(),
                                payload["user"].get<std::string>(),
                                payload["authorizationId"],
                                payload["banned"].get<int>() != 0);

                result.setUser(user);

                // LOG DEBUG
                cout << "Login successfull [ " << username << " ]" << endl;
            }
            else
            {
                // LOG DEBUG
                cout << "Login Failed [ " << username << " ]" << endl;

                result.setError(response_json["message"]);
            }
        }
    }
    catch (std::exception &e)
    {
        result.setLogin(LoginResult::FAILED);
        result.setError(e.what());
    }

    return result;
}
