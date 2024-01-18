#ifndef ITERN_HPP
# define ITERN_HPP

#include <iostream>
#include <iomanip>

#include "AForm.hpp"

class AForm;

class Intern
{

    public:
        Intern();
        Intern(const Intern &other);
        Intern& operator=(const Intern &other);
        ~Intern();

        AForm *makeForm(const std::string& form_name, const std::string& target) const;
        AForm *getRobotomyRequestForm(std::string target) const;
        AForm *getPresidentialPardonForm(std::string target) const;
        AForm *getShrubberyCreationForm(std::string target) const;
};

#endif