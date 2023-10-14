#ifndef CONTACT_CLASS
#define CONTACT_CLASS

#include <iostream>
#include <iomanip>

class Contact{
    private:
        std::string FirstName;
        std::string LastName;
        std::string Nickname;
        std::string Phonenumber;
        std::string Darkest_secret;
    public:
        void set_Firstname(std::string f_name){
            Contact::FirstName = f_name;
        }
        void set_Lastname(std::string l_name){
            Contact::LastName = l_name;
        }
        void set_Nickname(std::string N_name){
            Contact::Nickname = N_name;
        }
        void set_Phone(std::string P_number){
            Contact::Phonenumber = P_number;
        }
        void set_Drakestsecret(std::string D_secret){
            Contact::Darkest_secret = D_secret;
        }
        
        std::string get_First_name(){
            return Contact::FirstName;
        }
        std::string get_Last_name(){
            return Contact::LastName;
        }
        std::string get_Nick_name(){
            return Contact::Nickname;
        }
        std::string get_Phone_number(){
            return Contact::Phonenumber;
        }
        std::string get_Drakest_secret(){
            return Contact::Darkest_secret;
        }
};

#endif