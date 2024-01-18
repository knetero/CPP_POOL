#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target("Default"){}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardonForm", 25, 5), target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other.get_name(), other.get_grade_to_sign(), other.get_grade_to_execute()), target(other.target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other){
    (void)other;
    return (*this);
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
    if (executor.get_grade() > this->get_grade_to_execute())
        throw AForm::GradeTooLowException();
    else
        std::cout << this->target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(){}