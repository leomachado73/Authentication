//
// Created by machado on 28/02/19.
//

#ifndef AUTHENTICATION_EXCEPTION_H
#define AUTHENTICATION_EXCEPTION_H

#include <exception>
#include <string>


class AuthenticationException : public std::exception
{
private:
    std::string err;

public:
    AuthenticationException(const std::string &err)
    {
        this->err = err;
    }

    const char *what() const throw()
    {
        return err.c_str();
    }
};

#endif //AUTHENTICATION_EXCEPTION_H
