#include "RobotomyRequestForm.hpp"



RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("Default"){}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other.get_name(), other.get_grade_to_sign(), other.get_grade_to_execute()), target(other.target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other){
    (void)other;
    return (*this);
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
    if (executor.get_grade() > this->get_grade_to_execute())
        throw AForm::GradeTooLowException();
    else
    {
        static int i = 0;
        if (i % 2 == 0)
            std::cout << "Bzzzzz " << this->target << " has been robotomized successfully" << std::endl;
        else
            std::cout << this->target << " robotomization failed" << std::endl;
        i++;
    }
}

RobotomyRequestForm::~RobotomyRequestForm(){}