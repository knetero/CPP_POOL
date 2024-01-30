#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("Default"){}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other.get_name(), other.get_grade_to_sign(), other.get_grade_to_execute()), target(other.target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other){
   (void)other;
    return (*this);
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
    if (!this->get_is_signed())
        throw AForm::FormNotSignedException();
    else if (executor.get_grade() > this->get_grade_to_execute())
        throw AForm::GradeTooLowException();
    std::ofstream file;
    std::string filename = this->target + "_shrubbery";
    file.open(filename.c_str());
    if (file.is_open())
    {
        file << "                                                         .\n"
            "                                              .         ;  \n"
            "                 .              .              ;%     ;;   \n"
            "                   ,           ,                :;%  %;   \n"
            "                    :         ;                   :;%;'     .,   \n"
            "           ,.        %;     %;            ;        %;'    ,;\n"
            "             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n"
            "              %;       %;%;      ,  ;       %;  ;%;   ,%;' \n"
            "               ;%;      %;        ;%;        % ;%;  ,%;'\n"
            "                `%;.     ;%;     %;'         `;%%;.%;'\n"
            "                 `:;%.    ;%%. %@;        %; ;@%;%'\n"
            "                    `:%;.  :;bd%;          %;@%;'\n"
            "                      `@%:.  :;%.         ;@@%;'   \n"
            "                        `@%.  `;@%.      ;@@%;         \n"
            "                          `@%%. `@%%    ;@@%;        \n"
            "                            ;@%. :@%%  %@@%;       \n"
            "                              %@bd%%%bd%%:;     \n"
            "                                #@%%%%%:;;\n"
            "                                %@@%%%::;\n"
            "                                %@@@%(o);  . '         \n"
            "                                %@@@o%;:(.,'         \n"
            "                            `.. %@@@o%::;         \n"
            "                               `)@@@o%::;         \n"
            "                                %@@(o)::;        \n"
            "                               .%@@@@%::;         \n"
            "                               ;%@@@@%::;.          \n"
            "                              ;%@@@@%%:;;;. \n"
            "                          ...;%@@@@@%%:;;;;,..";
        file.close();
    }
    else
        std::cout << "Error opening file" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}