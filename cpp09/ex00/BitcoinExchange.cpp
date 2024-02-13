#include "BitcoinExchange.hpp"
#include <cstddef>
#include <fstream>
#include <iostream>

BitcoinExchange::BitcoinExchange()
{
    readData();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    this->data = other.data;
    this->key = other.key;
    this->value = other.value;
    return *this;
}

void BitcoinExchange::printData()
{
    for (std::map<std::string, double>::iterator itr = data.begin(); itr != data.end(); itr++){
        std::cout<< itr->first << "|" << itr->second <<  std::endl;
    }
}

void BitcoinExchange::readData()
{
    std::ifstream Data_file("data.csv");
    std:: string s;
    size_t index;

    if (!Data_file.is_open())
    {
        std::cerr << "Error: file not found" << std::endl;
        return;
    }

    std::getline(Data_file, s);
    while (std::getline(Data_file, s))
    { 
        index = s.find(",");
        if (index == std::string::npos)
            return;
        this->key = s.substr(0, index);
        this->value = s.substr(index + 1, s.length() - index);
        data[this->key] = std::atof(this->value.c_str());
    }
    Data_file.close();
}

void   trim_spaces(std::string &s)
{
    size_t start = s.find_first_not_of(" \t");
    size_t end = s.find_last_not_of(" \t");
    if (start == std::string::npos || end == std::string::npos)
        s = "";
    else
        s = s.substr(start, end - start + 1);
}

bool parse_key_value(std::string &key, std::string &value)
{
    if (key.empty() || value.empty())
    {
        std::cerr << "Error: bad input => empty line" << std::endl;
        return false;
    }
    if (key.length() != 10)
    {
        std::cerr << "Error: bad input => " << key << std::endl;
        return false;
    }
    if (key.find_first_not_of("0123456789-") != std::string::npos)
    {
        std::cerr << "Error: bad input => " << key << std::endl;
        return false;
    }
    int counter = std::count(key.begin(), key.end(), '-');
    if (counter != 2)
    {
        std::cerr << "Error: bad input => " << key << std::endl;
        return false;
    }
    if (value.find_first_not_of("0123456789.") != std::string::npos)
    {
        if(!is_negative(value))
            return false;
        std::cerr << "Error: bad input => " << value << std::endl;
        return false;
    }
    int dot = std::count(value.begin(), value.end(), '.');
    if (dot > 1)
    {
        std::cerr << "Error: bad input => " << key << std::endl;
        return false;
    }
    return true;
}

bool is_date_valid(int year, int month, int day)
{
    if (month == 2)
    {
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        {
            if (day > 29)
                return false;
        }
        else
        {
            if (day > 28)
                return false;
        }
    }
    if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        if (day > 30)
            return false;
    }
    if(day > 31 || day < 1)
        return false;
    return true;
}

bool parse_date(std::string &date)
{
    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());
    if (year < 2000 || year > 2021)
    {
        std::cerr << "Error: bad input => " << date << std::endl;
        return false;
    }
    if (month < 1 || month > 12)
    {
        std::cerr << "Error: bad input => " << date << std::endl;
        return false;
    }
    if (day < 1 || day > 31)
    {
        std::cerr << "Error: bad input => " << date << std::endl;
        return false;
    }
    if(!is_date_valid(year, month, day))
    {
        std::cerr << "Error: bad input => " << date << std::endl;
        return false;
    }
    return true;
}

bool is_negative(std::string &value)
{
    double val = std::atof(value.c_str());
    if (val < 0)
    {
        std::cerr << "Error: not a positive number. " << std::endl;
        return false;
    }
    return true;
}

bool is_large(std::string &value)
{
    double val = std::atof(value.c_str());
    if (val > 1000)
    {
        std::cerr << "Error: too large a number. " << std::endl;
        return false;
    }
    return true;
}

double BitcoinExchange::get_date(std::string &date, const double &value)
{
    std::map<std::string, double>::iterator itr = data.lower_bound(date);
    if (itr != data.begin() && itr->first != date)
    {
        itr--;
    }
    return itr->second * value;
}

void BitcoinExchange::fill_input(char *input_file)
{
    std::ifstream file(input_file);
    std::string line;
    std::stringstream ss;
    std::string key;
    std::string value;
    size_t index;
    bool valid_first_line = false;

    if (file.is_open())
    {
        while(std::getline(file, line))
        {
            index = line.find("|");
            if (index == std::string::npos)
            {
                std::cerr << "Error: bad input => " << line << std::endl;
                continue;
            }
            key = line.substr(0, index);
            value = line.substr(index + 1, line.length() - index);
            trim_spaces(key);
            trim_spaces(value);
            if (!valid_first_line && (key != "date" && value != "value"))
            {
                std::cout << "Error: invalid input should be : date | value" << std::endl;
                exit(1);
            }
            else if (!valid_first_line){
                valid_first_line = true;
                continue;
            }
            if (!parse_key_value(key, value))
                continue;
            if(!parse_date(key))
                continue;
            if(!is_large(value))
                continue;
            std::cout << key << " => " << value << " = " << get_date(key, std::atof(value.c_str())) << std::endl;
        }
    }
}


BitcoinExchange::~BitcoinExchange(){}