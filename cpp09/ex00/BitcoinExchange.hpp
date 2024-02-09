#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP


#include <algorithm>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <fstream>
#include <sstream>
#include <cstddef>
#include <map>
#include <string>

class BitcoinExchange{

    private:
        std::map<std::string, double> data;
        std::string key;
        std::string value;
    public :
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        ~BitcoinExchange();


        void readData();
        void printData();
        void fill_input(char *input_file);
        double get_date(std::string &date, const double &value);
};

void    trim_spaces(std::string &s);
bool    is_negative(std::string &value);

#endif
