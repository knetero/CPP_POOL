#ifndef PHONEBOOK_CLASS
#define PHONEBOOK_CLASS

#include "contact_class.hpp"

class PhoneBook{
    private:
        Contact contacts[8];
        int len;
        int index;
    public:
        PhoneBook();
        void add(int i);
        void search(int i);
        void setlen();
        void setindex(int in);
        int getindex();
};
void handle_cin();
int check_input(std::string input);

#endif