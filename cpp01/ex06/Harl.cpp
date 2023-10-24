#include "Harl.hpp"


void Harl::debug(void){
    std::cout << "[DEBUG]: " << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info(void){
    std::cout << "[INFO]: " << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void){
    std::cout << "[WARNING]: " << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void){
    std::cout << "[ERROR]: " << "This is unacceptable, I want to speak to the manager now." << std::endl;
}


void  Harl::complain(std::string level)
{
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void(Harl::*func_pointer[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    int found = 0;
    int j = -1;
    for (size_t i = 0; i < 4; i++)
    {
        if(levels[i] == level)
        {
            found = 1;
            j = i;
            break;
        }
    }
    switch (j)
    {
        case 0:
            (this->*func_pointer[j++])();
        case 1:
            (this->*func_pointer[j++])();
        case 2:
            (this->*func_pointer[j++])();
        case 3:
            (this->*func_pointer[j])();
            break;
        default:
                std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }   
}