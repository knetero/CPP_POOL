#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <iomanip>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string name;
        bool is_signed;
        const int grade_to_sign;
        const int grade_to_execute;
    public:
        Form();
        Form(const std::string& name, int grade_to_sign);
        Form(const Form &other);
        Form& operator=(const Form &other);
        ~Form();

        std::string get_name() const;
        bool get_is_signed() const;
        int get_grade_to_sign() const;
        int get_grade_to_execute() const;

        void beSigned(const Bureaucrat &bureaucrat);


        class GradeTooHighException : public std::exception 
        {
            public:
                const char* what() const throw();
        };

        class GradeTooLowException : public std::exception 
        {
            public:
                const char* what() const throw();
        };
};
std::ostream & operator<<( std::ostream &os, Form const &b);


#endif