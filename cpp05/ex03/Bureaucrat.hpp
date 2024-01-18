#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <iomanip>
#include "AForm.hpp"

class AForm;

# define MIN_GRADE 1
# define MAX_GRADE 150


class Bureaucrat
{
    private:
        const std::string name;
        int grade;
    public:
        Bureaucrat();
        Bureaucrat(const std::string& name, int grade);
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat& operator=(const Bureaucrat &other);
        ~Bureaucrat();

        int get_grade() const;
        std::string get_name() const;
        void set_grade(int new_grade);
        void incrementGrade();
        void decrementGrade();
 
        void signForm(AForm &aform);

        void executeForm(AForm const & form);

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
std::ostream & operator<<( std::ostream &os, Bureaucrat const &b);


#endif