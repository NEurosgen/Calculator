#include <iostream>

#include "Calculator.h"

Calculator::Calculator() = default;
void Input(std::string& expr, ExpressionParser& parser, Processor& processor) {
    std::cout << "Input: ";
    while (getline(std::cin, expr)) {
        double result;
        try {
            result = parser.parse(expr, processor);
            std::cout << "Answer: " << result << "\n";
            std::cout << "Input math expresion: ";
        }
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
}

void Calculator::start() {
    std::string input;
    Input(input, parser, processor);
}