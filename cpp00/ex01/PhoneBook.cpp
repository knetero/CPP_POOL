#include "contact_class.hpp"
#include "PhoneBook_class.hpp"

PhoneBook::PhoneBook(){
    len = 0;
}

int    PhoneBook::getindex(){
    return index;
}

void    PhoneBook::setindex(int in){
    index = in;
}

void    PhoneBook::setlen(){
    len = 8;
}

void handle_cin()
{
    std::clearerr(stdin);
    std::cin.clear();
    std::cout << std::endl;
}

int  check_input(std::string input)
{
    int k = 0;
    while(input[k])
    {
        if(!std::isdigit(input[k]))
        {
            std::cout << "Invalid input! Please enter a valid integer." << std::endl;
            return(1);
        }
        k++;
    }
    return(0);
}

void    PhoneBook::search(int i)
{
    std::string input;
    std::cout << std::endl;
    std::cout << "     ******* MY AWESOME PHONEBOOK *******       "<< std::endl;
    std::cout << std::endl;
    std::cout << " -------------------------------------------"<< std::endl;
    std::cout << "|"<< std::setw(10)<<"index "<< "|";
    std::cout << std::setw(10)<<"First Name"<< "|";
    std::cout << std::setw(10)<<"Last Name"<< "|";
    std::cout << std::setw(10)<<"Nickname"<< "|";
    std::cout << std::endl <<" -------------------------------------------"<< std::endl;

    if(len == 8)
        i = len;
    for (int j = 0; j < i; j++) {
        std::string firstName = contacts[j].get_First_name();
        std::string lastName = contacts[j].get_Last_name();
        std::string nickname = contacts[j].get_Nick_name();

        if(firstName.length() > 10)
            firstName = firstName.substr(0, 9) + ".";
        if(lastName.length() > 10)
            lastName = lastName.substr(0, 9) + ".";
        if(nickname.length() > 10)
            nickname = nickname.substr(0, 9) + ".";

        std::cout << "|"<< std::setw(10)<<j<< "|";
        std::cout << std::setw(10) << firstName << "|";
        std::cout << std::setw(10) << lastName << "|";
        std::cout << std::setw(10) << nickname << "|";
        std::cout << std::endl <<" --------------------------------------------"<< std::endl;
    }

    std::cout << "Enter the contact index you wish to display: ";
    std::cin >> input;
    std::cout << std::endl;
    if(std::cin.fail())
        return(handle_cin());
    if (check_input(input) == 1)
        return;
    PhoneBook::setindex(std::atoi(input.c_str()));
    if (PhoneBook::getindex() >= i)
    {
        std::cout << "Contact not found!" <<std::endl;
        return;
    }
    while(i >= 0)
    {
        if(PhoneBook::getindex() == i)
        {
            std::string input;

            int index = PhoneBook::getindex();
            std::string firstName = contacts[index].get_First_name();
            std::string lastName = contacts[index].get_Last_name();
            std::string nickname = contacts[index].get_Nick_name();
            std::string phonenum = contacts[index].get_Phone_number();
            std::string Darkest_sec = contacts[index].get_Drakest_secret();

            std::cout << "          index : " << index<<std::endl;
            std::cout << "          First Name: "<< firstName<<std::endl;
            std::cout << "          Last Name: " << lastName<<std::endl;
            std::cout << "          Nickname: " << nickname<<std::endl;
            std::cout << "          Phone number : " << phonenum<<std::endl;
            std::cout << "          Darkest secret : " << Darkest_sec<<std::endl;
            std::cout << std::endl;
            break;
        }
        i--;      
    }
}

void    PhoneBook::add(int i)
{
    Contact contact;
    std::string input;

    std::cout << "First name: ";
    std::cin >> input;
    if(std::cin.fail())
      return(handle_cin());
    contact.set_Firstname(input);
    std::cout << "Last name: ";
    std::cin >> input;
    if(std::cin.fail())
       return(handle_cin());
    contact.set_Lastname(input);
    std::cout << "Nickname: ";
    std::cin >> input;
    if(std::cin.fail())
       return(handle_cin());
    contact.set_Nickname(input);
    std::cout << "Phone number: ";
    std::cin >> input;
    if(std::cin.fail())
       return(handle_cin());
    contact.set_Phone(input);
    std::cout << "Darkest secret: ";
    std::cin >> input;
    if(std::cin.fail())
        return(handle_cin());
    contact.set_Drakestsecret(input);
    contacts[i].set_Firstname(contact.get_First_name());
    contacts[i].set_Lastname(contact.get_Last_name());
    contacts[i].set_Nickname(contact.get_Nick_name());
    contacts[i].set_Phone(contact.get_Phone_number());
    contacts[i].set_Drakestsecret(contact.get_Drakest_secret());
}

int main()
{
    PhoneBook PhoneBook;
    int i = 0;
    std::cout << std::endl;
    std::cout << "       ******* MY AWESOME PHONEBOOK *******       "<<std::endl;
    std::cout << std::endl;
    while(1)
    {
        std::string command;
        std::cout << "Enter one of those commands (ADD, SEARCH, EXIT): ";
        std::cin >> command;
        if(std::cin.fail())
            handle_cin();
        if (command.compare("EXIT") == 0)
        {
            std::cout << "HAVE A NICE DAY !"<< std::endl;
            break;
        }
        else if (command.compare("ADD") == 0)
        {
            if(i == 8)
            {
                PhoneBook.setlen();
                i = 0;
            }
            PhoneBook.add(i);
            i++;
        }
        else if(command.compare("SEARCH") == 0)
            PhoneBook.search(i);
        else
            std::cout << "Command not found! " << std::endl;
    }
}