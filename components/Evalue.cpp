#include "Evalue.h"

Processor::Processor() = default;
bool checkOtherFunc(std::string const&  str) {
     std::vector<std::string> const named = { "sin", "cos", "ln" };
    for (auto& it : named) {
        if (str == it) {
            return true;
        }
    }
    return false;
}
double evaluteExpr(std::string const&  operator_, double num1, double num2) {
    if (operator_ == "+") {
        return num1 + num2;
    }
    else if (operator_ == "-") {
        return num1 - num2;
    }
    else if (operator_ == "*") {
        return num1 * num2;
    }
    else if (operator_ == "/") {
        if (num1 == 0) {
            throw std::runtime_error("Divide by zero");
        }
        return num2 / num1;
    }
}
double Processor::process(std::stack<double>& numbers,
    std::stack<std::string>& operators) {
    double result = 0;
    double num1 = 0;
    double num2 = 0;
    num1 = numbers.top();
    numbers.pop();
    std::string operator_ = operators.top();
    operators.pop();
    if (checkOtherFunc(operator_)) {
        SharedLibrary currentLibrary = loaderLibrary.getLibrary(operator_);
        result = currentLibrary.runFunc(num1);
    }
    else {
        num2 = numbers.top();
        numbers.pop();
        result = evaluteExpr(operator_, num1, num2);
        if (operator_ == "^") {
            SharedLibrary currentLibrary = loaderLibrary.getLibrary("pow");
            result = currentLibrary.runFunc(num2, num1);
        }
    }
    numbers.push(result);
    return result;
}