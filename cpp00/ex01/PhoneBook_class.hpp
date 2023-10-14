#ifndef PHONEBOOK_CLASS
#define PHONEBOOK_CLASS

#include "contact_class.hpp"

class PhoneBook{
    private:
        Contact contacts[8];
        int len;
        int index;
    public:
        PhoneBook(){
            len = 0;
        }
        void add(int i);
        void search(int i);
        void handle_cin();
        int check_input(std::string input);
        void    setlen(){
            len = 8;
        }
        void    setindex(int in){
            index = in;
        }
        int    getindex(){
            return index;
        }
};

#endif