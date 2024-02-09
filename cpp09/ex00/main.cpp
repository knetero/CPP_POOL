#include "BitcoinExchange.hpp"


int main(int argc, char **argv)
{
    BitcoinExchange btc;
    
    if (argc != 2) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }
    else {
        btc.readData();
        btc.fill_input(argv[1]);

    }
    return 0;
}