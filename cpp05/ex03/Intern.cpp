#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(){}

Intern::Intern(const Intern &other){
    *this = other;
}

Intern& Intern::operator=(const Intern &other){
    (void)other;
    return (*this);
}


AForm *Intern::makeForm(const std::string& form_name, const std::string& target) const
{
    std::string form_names[3] = {"RobotomyRequestForm", "PresidentialPardonForm", "ShrubberyCreationForm"};
    AForm *(Intern::*ptr[3])(std::string) const = {&Intern::getRobotomyRequestForm,&Intern::getPresidentialPardonForm,&Intern::getShrubberyCreationForm};
    int i = 0;
    while (i < 3 && form_names[i] != form_name)
        i++;
    if (i == 3)
    {
        std::cout << "Form name not found" << std::endl;
        return nullptr;
    }
    std::cout << "Intern creates " << form_name << std::endl;
    return ((this->*ptr[i])(target));
}

AForm *Intern::getPresidentialPardonForm(std::string target) const{
    return (new PresidentialPardonForm(target));
}

AForm *Intern::getRobotomyRequestForm(std::string target) const{
    return (new RobotomyRequestForm(target));
}

AForm *Intern::getShrubberyCreationForm(std::string target) const{
    return (new ShrubberyCreationForm(target));
}

Intern::~Intern(){}