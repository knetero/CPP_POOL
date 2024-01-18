#include "Form.hpp"

Form::Form() : name("default"), grade_to_sign(1), grade_to_execute(1){
    this->is_signed = false;
}

Form::Form(const std::string& name, int grade_to_sign) : name(name), grade_to_sign(grade_to_sign), grade_to_execute(0){
    if (grade_to_sign < MIN_GRADE)
        throw Form::GradeTooHighException();
    else if (grade_to_sign > MAX_GRADE)
        throw Form::GradeTooLowException();
    this->is_signed = false;
}

Form::Form(const Form& other) : name(other.get_name()), grade_to_sign(other.get_grade_to_sign()), grade_to_execute( other.get_grade_to_execute()) {}


Form& Form::operator=(const Form &other){
    if (this != &other)
        this->is_signed = other.is_signed;
    return (*this);
}

int Form::get_grade_to_sign() const{
    return (this->grade_to_sign);
}

int Form::get_grade_to_execute() const{
    return (this->grade_to_execute);
}

bool Form::get_is_signed() const{
    return (this->is_signed);
}

void Form::beSigned(const Bureaucrat &bureaucrat){
    if (bureaucrat.get_grade() > this->grade_to_sign)
        throw Form::GradeTooLowException();
    this->is_signed = true;
}


std::string Form::get_name() const{
    return (this->name);
}

const char* Form::GradeTooHighException::what() const throw(){
    return "Grade is too high !!";
}

const char* Form::GradeTooLowException::what() const throw(){
    return "Grade is too low !!";
}

std::ostream & operator<<( std::ostream &os, Form const &b ){
    os << "Form name: " << b.get_name() << std::endl;
    os << "Grade to sign: " << b.get_grade_to_sign() << std::endl;
    return os;
}

Form::~Form(){}