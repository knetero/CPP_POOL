#include "AForm.hpp"

AForm::AForm() : name("default"), grade_to_sign(1), grade_to_execute(1){
    this->is_signed = false;
}

AForm::AForm(const std::string& name, int grade_to_sign, int grade_to_execute) : name(name), grade_to_sign(grade_to_sign), grade_to_execute(grade_to_execute){
    if (grade_to_sign < MIN_GRADE)
        throw AForm::GradeTooHighException();
    else if (grade_to_sign > MAX_GRADE)
        throw AForm::GradeTooLowException();
    this->is_signed = false;
}

AForm::AForm(const AForm& other) : name(other.get_name()), grade_to_sign(other.get_grade_to_sign()), grade_to_execute( other.get_grade_to_execute()) {}


AForm& AForm::operator=(const AForm &other){
    if (this != &other)
        this->is_signed = other.is_signed;
    return (*this);
}

int AForm::get_grade_to_sign() const{
    return (this->grade_to_sign);
}

int AForm::get_grade_to_execute() const{
    return (this->grade_to_execute);
}

bool AForm::get_is_signed() const{
    return (this->is_signed);
}

void AForm::beSigned(const Bureaucrat &bureaucrat){
    std::cout << bureaucrat.get_grade() << " signs " << this->grade_to_sign << std::endl;
    if (bureaucrat.get_grade() > this->grade_to_sign)
        throw AForm::GradeTooLowException();
    this->is_signed = true;
}


std::string AForm::get_name() const{
    return (this->name);
}

const char* AForm::GradeTooHighException::what() const throw(){
    return "Grade is too high !!";
}

const char* AForm::GradeTooLowException::what() const throw(){
    return "Grade is too low !!";
}

const char* AForm::FormNotSignedException::what() const throw(){
    return "Form is not signed !!";
}

std::ostream & operator<<( std::ostream &os, AForm const &b ){
    os << "AForm name: " << b.get_name() << std::endl;
    os << "Grade to sign: " << b.get_grade_to_sign() << std::endl;
    return os;
}

AForm::~AForm(){}