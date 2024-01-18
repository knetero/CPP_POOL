#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(){
    std::cout << "Default Constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name), grade(grade) {

    if (this->grade < MIN_GRADE)
        throw Bureaucrat::GradeTooHighException();
    else if (this->grade > MAX_GRADE)
        throw Bureaucrat::GradeTooLowException();
    std::cout << "Parameterized Constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
    *this = other;
    std::cout << "Copy Constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        grade = other.get_grade();
    return *this;
}

void Bureaucrat::incrementGrade(){
    if (grade - 1 < MIN_GRADE) {
        throw GradeTooHighException();
    }
    grade--;
}

void Bureaucrat::decrementGrade(){
    if (grade + 1 > MAX_GRADE) {
        throw GradeTooLowException();
    }
    grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw(){
    return "Grade is too high !!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
    return "Grade is too low !!";
}

void Bureaucrat::set_grade(int new_grade){
    this->grade = new_grade;
}

std::string Bureaucrat::get_name() const{
    return name;
}

int Bureaucrat::get_grade() const{
    return grade;
}

std::ostream & operator<<( std::ostream &os, Bureaucrat const &b ){
    os << b.get_name() << ", bureaucrat grade " << b.get_grade() << std::endl;
    return os;
}

Bureaucrat::~Bureaucrat(){
    std::cout << "Bureaucrat Destructor called" << std::endl;
}