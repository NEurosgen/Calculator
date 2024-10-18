#pragma once
#include "dlfcn.h"
#include "iostream"
#include <string>
#include <sstream>

class SharedLibrary {
public:
    void loadLibrary(const std::string &nameLibrary);

    double runFunc(const double &value);

    double runFunc(const double &value1, const double &value2);

    std::string name;

    void closeLib();

private:
    void *handler;

};


