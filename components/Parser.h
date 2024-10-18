#pragma once
#include <string>
#include <set>
#include "Parser.h"
#include "Evalue.h"

class ExpressionParser {
public:
    double parse(std::string& expression, Processor& processor);
private:
    std::set<std::string> validFunctions = {"sin", "cos", "tg", "ctg", "ln"};
    std::set<std::string> validSimpleFunctions = {"+", "-", "*", "/", "^"};
    double readNumber(std::string &expression, size_t &i);
    std::string readFunction(std::string &expression, size_t &i);
    int getPriority(std::string &operator2);
};
#pragma once
