#include "Form.hpp"
#include "Bureaucrat.hpp"


int main() {
   try {
        Bureaucrat bureaucrat("knetero",4);
        Form form("formName", 1);

        bureaucrat.signForm(form);

        std::cout << form << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}