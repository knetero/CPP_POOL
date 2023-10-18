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
        void set_Firstname(std::string f_name);
        void set_Lastname(std::string l_name);
        void set_Nickname(std::string N_name);
        void set_Phone(std::string P_number);
        void set_Drakestsecret(std::string D_secret);
        
        std::string get_First_name();
        std::string get_Last_name();
        std::string get_Nick_name();
        std::string get_Phone_number();
        std::string get_Drakest_secret();
};

#endif