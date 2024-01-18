#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <iomanip>

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string name;
        bool is_signed;
        const int grade_to_sign;
        const int grade_to_execute;
    public:
        AForm();
        AForm(const std::string& name, int grade_to_sign, int grade_to_execute);
        AForm(const AForm &other);
        AForm& operator=(const AForm &other);
        virtual ~AForm();

        std::string get_name() const;
        bool get_is_signed() const;
        int get_grade_to_sign() const;
        int get_grade_to_execute() const;

        void beSigned(const Bureaucrat &bureaucrat);
        virtual void execute(const Bureaucrat& executor) const = 0;


        class GradeTooHighException : public std::exception 
        {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception 
        {
            public:
                virtual const char* what() const throw();
        };

        class FormNotSignedException : public std::exception 
        {
            public:
                virtual const char* what() const throw();
        };
};
std::ostream & operator<<( std::ostream &os, AForm const &b);


#endif