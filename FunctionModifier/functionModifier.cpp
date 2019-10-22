#include <iostream>
#include <fstream>
#include <cstring>

#define EXPRESSION_FILE_PATH "../Expression/Expression.h"
#define PARAMETERS_FILE_PATH "../Expression/parameters.txt"

#define COMPILATION_COMMAND "cd ../Grapher; make; cd ../FunctionModifier"

void recompileFunctionGrapher();

int main()
{
    std::cout << "Function input format:\nexpression\nspacing range\n" << std::endl;
    std::cout << "expression: Actual function expression using variables x and/or y and functions from the standard cmath library" << std::endl;
    std::cout << "spacing (float): Spacing between the points of the rendered grid" << std::endl;
    std::cout << "range (int): Number of rows (and columbs as they are the same) in the rendererd grid" << std::endl << std::endl;

    std::cout << "Examples:" << std::endl;
    std::cout << "sin(x) * cos(y)\n0.2 50" << std::endl;
    std::cout << "pow(x,2) + pow(y,2)\n0.2 25" << std::endl << std::endl;
    std::cout << "New function: ";

    std::string exp;
    float spacing;
    int range;

    std::getline (std::cin, exp);
    std::cin >> spacing >> range;
    std::cout << std::endl;

    std::ofstream expression(EXPRESSION_FILE_PATH);
    if(expression.is_open())
    {
        std::string def = "#define EXPRESSION ";
        expression << def << exp;
        expression.close();
    }
    else std::cout << "Error: Unable to open expression file" << std::endl;

    std::ofstream parameteres(PARAMETERS_FILE_PATH);
    if(parameteres.is_open())
    {
        parameteres << spacing << " " << range;
        parameteres.close();
    }
    else std::cout << "Error: Unable to open parameters file" << std::endl;

    recompileFunctionGrapher();
}

void recompileFunctionGrapher()
{
    std::cout << "Recompiling function grapher with new function" << std::endl << std::endl;

    system(COMPILATION_COMMAND);

    std::cout << std::endl << "Compilation finished" << std::endl;
}