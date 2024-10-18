#pragma once
#include "Parser.h"
#include "Evalue.h"
#include "LoaderLibrary.h"

class Calculator final{
private:
    ExpressionParser parser;
    Processor processor;
public:
    Calculator();
    void start();

};


