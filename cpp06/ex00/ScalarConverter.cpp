#include "ScalarConverter.hpp"
#include <climits>
#include <cmath>
#include <cstddef>
#include <iomanip>
#include <ios>
#include <sstream>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& src) {
    *this = src;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& src) {
    if (this != &src) {
        *this = src;
    }
    return *this;
}

void    ScalarConverter::castToInt(const std::string &input){
    double i;
    std::istringstream iss(input);
    iss >> i;

    char c = static_cast<char>(i);
    if(c < 32 || c > 126)
        std::cout << "char: " << "Non displayable" << std::endl;
    else
        std::cout << "char: '" << c << "'" << std::endl;
    if (i > INT_MAX || i < INT_MIN)
        std::cout << "int: " << "impossible" << std::endl;
    else
        std::cout << "int: " << i << std::endl;
    if(i > MAXFLOAT)
        std::cout << "float: " << "impossible" << std::endl;
    else
        std::cout << "float: "  << static_cast<float>(i) << ".0f" << std::endl;
    std::cout << "double: "  << static_cast<double>(i) << ".0" << std::endl;
    exit(0);
}

void    ScalarConverter::castToChar(const std::string &input){
    char c = 48;
    c = static_cast<char>(input[0]);
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
    exit(0);
}

void ScalarConverter::castToDouble(const std::string &input){
    double d = 0.0;
    int precision = 0;
    std::stringstream iss(input);
    iss >> d;

    char c = static_cast<char>(d);
    if(c < 32 || c > 126)
        std::cout << "char: " << "Non displayable" << std::endl;
    else
        std::cout << "char: '" << c << "'" << std::endl;
    if (d > INT_MAX || d < INT_MIN)
        std::cout << "int: " << "impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(d) << std::endl;
    precision = count_precision(input);
    std::cout << "float: "  << std::fixed << std::setprecision(precision) << static_cast<float>(d) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(precision) << d << std::endl;
    exit(0);
}

void ScalarConverter::castToFloat(const std::string &input){
    float f = 0.0;
    int precision = 0;

    std::string tmp = input.substr(0, input.length() - 1);
    std::stringstream iss(tmp);
    iss >> f;

    precision = count_precision(input);
    char c = static_cast<char>(f);
    if(c < 32 || c > 126)
        std::cout << "char: " << "Non displayable" << std::endl;
    else
        std::cout << "char: '" << c << "'" << std::endl;
    if (f > MAXFLOAT)
        std::cout << "float: " << "impossible" << std::endl;
    else
        std::cout << "float: "  << std::fixed << std::setprecision(precision) << f << "f" << std::endl;
    if (f > INT_MAX || f < INT_MIN)
        std::cout << "int: " << "impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(f) << std::endl;
    std::cout << "double: "  << static_cast<double>(f) << std::endl;

    exit(0);
}
 
bool ScalarConverter::is_pseudo(const std::string& input){
    if (input == "nan" || input == "+inf" || input == "+inff" || input == "-inf" || input == "-inff")
    {
        std::cout << "char: " << "impossible" << std::endl;
        std::cout << "int: " << "impossible" << std::endl;

        if (input == "+inff" || input == "-inff" || input == "nan"){
            if(input == "nan")
                std::cout << "float: " << "nanf" << std::endl;
            else
                std::cout << "float: " << input.substr(0, input.length() - 1) << "f" << std::endl;
        }
        else
            std::cout << "float: " << input << std::endl;
        std::cout << "double: " << input << std::endl;
        exit(0);
    }
    return false;
}

void ScalarConverter::convert(const std::string& input)
{
    is_pseudo(input);
    if (isChar(input))
        castToChar(input);
    if (isInt(input))
        castToInt(input);
    if (isFloat(input))
        castToFloat(input);
    if (isDouble(input))
        castToDouble(input);
    else
        std::cout << "impossible" << std::endl;
}

int ScalarConverter::count_precision(const std::string& input){
    int i = 0;
    int precision = 0;

    while (input[i] != '.')
        i++;
    i++;
    while (input[i] != '\0'){
        precision++;
        i++;
    }
    return precision;
}

bool ScalarConverter::isChar(const std::string& input){
    if (input.length() == 1 && !isdigit(input[0]))
        return true;
    return false;
}

bool ScalarConverter::isInt(const std::string &input){
    size_t i = 0;

    if (input[i] == '-' || input[i] == '+')
        i++;
    for (; i < input.length(); i++) {
        if (!isdigit(input[i]))
            return false;
    }
    return true;
}

bool ScalarConverter::isDouble(const std::string &input){
    size_t i = 0;
    int flag = 0;

    for (; i < input.length(); i++) {
        if(input[i] == '.'){
            i++;
            flag++;
        }
        if(!isdigit(input[i]) || flag > 1)
            return false;
    }
    if (flag == 1)
        return true;
    return false;
}

bool ScalarConverter::isFloat(const std::string &input){
     if (input[input.length() - 1] == 'f' && isDouble(input.substr(0, input.length() - 1)))
        return true;
    return false;
}


ScalarConverter::~ScalarConverter() {}