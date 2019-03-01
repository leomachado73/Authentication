# C++ Authentication Server Side

This project was forked from [here](https://github.com/whoshuu/cpr-example/).
It's a login server side strategy. Currently it's authenticating with Auth Service using REST.
The project is using Dependency Injection, so if you want to change auth's behaviour, just implement your own class.

## Building

```
git submodule update --init --recursive
```

Then make a build directory and do a typical CMake build from there:

```
mkdir build
cd build
cmake ..
make
```

## Dependencies
cpr
json
jwt-cpp

## Requirements

The only explicit requirement is a C++11 compatible compiler such as clang or gcc. The minimum required version of gcc is unknown, so if anyone has trouble building this library with a specific version of gcc, do let me know.
