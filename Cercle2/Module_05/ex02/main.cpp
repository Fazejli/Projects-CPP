#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <cstdlib>
#include <ctime>

int main(){
    std::srand(std::time(NULL));
    // Test ShrubberyCreationForm
    try {
        ShrubberyCreationForm shrub("home");
        Bureaucrat gardener("Gardener", 136);
        gardener.signForm(shrub);
        gardener.executeForm(shrub);
    }
    catch (const std::exception &e){
        std::cerr << e.what() << std::endl;
    }

    std::cout << "---" << std::endl;

    // Test RobotomyRequestForm
    try {
        RobotomyRequestForm robot("Alice");
        Bureaucrat surgeon("Surgeon", 45);
        surgeon.signForm(robot);
        surgeon.executeForm(robot);
        surgeon.executeForm(robot);
        surgeon.executeForm(robot);
    }
    catch (const std::exception &e){
        std::cerr << e.what() << std::endl;
    }

    std::cout << "---" << std::endl;

    // Test PresidentialPardonForm
    try {
        PresidentialPardonForm pardon("Bob");
        Bureaucrat president("President", 5);
        president.signForm(pardon);
        president.executeForm(pardon);
    }
    catch (const std::exception &e){
        std::cerr << e.what() << std::endl;
    }

    std::cout << "---" << std::endl;

    // Test form non signée
    try {
        ShrubberyCreationForm shrub2("garden");
        Bureaucrat lazy("Lazy", 1);
        lazy.executeForm(shrub2);  // pas signée → erreur
    }
    catch (const std::exception &e){
        std::cerr << e.what() << std::endl;
    }

    std::cout << "---" << std::endl;

    // Test grade insuffisant pour executer
    try {
        PresidentialPardonForm pardon2("Charlie");
        Bureaucrat lowGrade("LowGrade", 1);
        lowGrade.signForm(pardon2);
        Bureaucrat tooLow("TooLow", 100);
        tooLow.executeForm(pardon2);  // grade trop bas pour exec
    }
    catch (const std::exception &e){
        std::cerr << e.what() << std::endl;
    }

    return (0);
}