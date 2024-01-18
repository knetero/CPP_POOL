#include "Bureaucrat.hpp"

int main()
{
    try{
        Bureaucrat b0;
        Bureaucrat b1("b1", 1);
        Bureaucrat b2("b2", 150);
        b2.incrementGrade();
        std::cout << b2.get_grade() << std::endl; 
        std::cout << b2 << std::endl;
        b1.decrementGrade();
        std::cout << b1 << std::endl;
    }
    catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }

}