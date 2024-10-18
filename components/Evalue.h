#pragma once
#include "stack"
#include "string"
#include "LoaderLibrary.h"
#include <iostream>
#include <map>


class Processor{
public:
    Processor();
    double process(std::stack<double> &numbers, std::stack<std::string> &operators);
private:
    LoaderLibrary loaderLibrary;
};

