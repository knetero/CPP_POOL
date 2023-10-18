#include "contact_class.hpp"
#include "PhoneBook_class.hpp"

void Contact::set_Firstname(std::string f_name){
    FirstName = f_name;
}

void Contact::set_Lastname(std::string l_name){
    LastName = l_name;
}

void Contact::set_Nickname(std::string N_name){
    Nickname = N_name;
}
void Contact::set_Phone(std::string P_number){
    Phonenumber = P_number;
}
void Contact::set_Drakestsecret(std::string D_secret){
    Darkest_secret = D_secret;
}

std::string Contact::get_First_name(){
    return FirstName;
}
std::string Contact::get_Last_name(){
    return LastName;
}
std::string Contact::get_Nick_name(){
    return Nickname;
}
std::string Contact::get_Phone_number(){
    return Phonenumber;
}
std::string Contact::get_Drakest_secret(){
    return Darkest_secret;
}