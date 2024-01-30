#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <iomanip>

class ScalarConverter {

    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& src);
        ~ScalarConverter();
    public:

        ScalarConverter& operator=(const ScalarConverter& src);

        static void convert(const std::string& input);
        static bool isChar(const std::string& input);
        static bool isInt(const std::string& input);
        static bool isFloat(const std::string& input);
        static bool isDouble(const std::string& input);
        static bool is_pseudo(const std::string& input);

        static void castToChar(const std::string& input);
        static void castToInt(const std::string& input);
        static void castToFloat(const std::string& input);
        static void castToDouble(const std::string& input);


        static int count_precision(const std::string& input);


};

#endif
