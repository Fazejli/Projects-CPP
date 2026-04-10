#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

static void printSeparator(const std::string &title)
{
    std::cout << "\n========== " << title << " ==========" << std::endl;
}

int main(void)
{
    std::srand(std::time(NULL));

    Intern someIntern;
    AForm *form = NULL;

    // -----------------------------------------------------------
    // Test 1 : ShrubberyCreationForm — signe et execute
    // -----------------------------------------------------------
    printSeparator("Test 1 : ShrubberyCreationForm");
    form = someIntern.makeForm("shrubbery creation", "garden");
    if (form)
    {
        std::cout << *form << std::endl;
        try {
            Bureaucrat bob("Bob", 130);
            bob.signForm(*form);
            bob.executeForm(*form);
        }
        catch (std::exception &e) { std::cerr << "Exception: " << e.what() << std::endl; }
        delete form; form = NULL;
    }

    // -----------------------------------------------------------
    // Test 2 : RobotomyRequestForm — plusieurs executions (50/50)
    // -----------------------------------------------------------
    printSeparator("Test 2 : RobotomyRequestForm");
    form = someIntern.makeForm("robotomy request", "Bender");
    if (form)
    {
        std::cout << *form << std::endl;
        try {
            Bureaucrat alice("Alice", 40);
            alice.signForm(*form);
            alice.executeForm(*form);
            alice.executeForm(*form);
            alice.executeForm(*form);
            alice.executeForm(*form);
        }
        catch (std::exception &e) { std::cerr << "Exception: " << e.what() << std::endl; }
        delete form; form = NULL;
    }

    // -----------------------------------------------------------
    // Test 3 : PresidentialPardonForm — signe et execute
    // -----------------------------------------------------------
    printSeparator("Test 3 : PresidentialPardonForm");
    form = someIntern.makeForm("presidential pardon", "Zaphod");
    if (form)
    {
        std::cout << *form << std::endl;
        try {
            Bureaucrat president("President", 1);
            president.signForm(*form);
            president.executeForm(*form);
        }
        catch (std::exception &e) { std::cerr << "Exception: " << e.what() << std::endl; }
        delete form; form = NULL;
    }

    // -----------------------------------------------------------
    // Test 4 : Formulaire inexistant
    // -----------------------------------------------------------
    printSeparator("Test 4 : Formulaire inexistant");
    form = someIntern.makeForm("coffee request", "Nobody");
    if (!form)
        std::cout << "Aucun formulaire cree (attendu)" << std::endl;

    // -----------------------------------------------------------
    // Test 5 : Grade trop bas pour SIGNER (150 < 25 requis)
    //          executeForm ne doit PAS etre tente si sign a echoue
    // -----------------------------------------------------------
    printSeparator("Test 5 : Grade trop bas pour signer");
    form = someIntern.makeForm("presidential pardon", "Target");
    if (form)
    {
        Bureaucrat weakling("Weakling", 150);
        weakling.signForm(*form);   // echoue : affiche "couldn't sign ... because Grade too low"
        if (form->getSignStatus()) // on n'execute QUE si signe
            weakling.executeForm(*form);
        else
            std::cout << "Form not signed, skipping execution (expected)" << std::endl;
        delete form; form = NULL;
    }

    // -----------------------------------------------------------
    // Test 6 : Formulaire non signe — execution refusee
    //          Message doit etre "Form is not signed"
    // -----------------------------------------------------------
    printSeparator("Test 6 : Execution sans signature");
    form = someIntern.makeForm("robotomy request", "HAL");
    if (form)
    {
        Bureaucrat exec("Exec", 1); // grade suffisant pour tout, mais form non signe
        exec.executeForm(*form);    // doit afficher "couldn't execute ... because Form is not signed"
        delete form; form = NULL;
    }

    // -----------------------------------------------------------
    // Test 7 : Grade trop bas pour EXECUTER (signe, mais grade insuffisant)
    // -----------------------------------------------------------
    printSeparator("Test 7 : Grade trop bas pour executer");
    form = someIntern.makeForm("presidential pardon", "Charlie");
    if (form)
    {
        Bureaucrat signer("Signer", 1);   // peut signer (grade 1 <= 25)
        signer.signForm(*form);            // OK
        Bureaucrat tooLow("TooLow", 100); // ne peut pas executer (100 > 5)
        tooLow.executeForm(*form);         // doit afficher "couldn't execute ... because Grade too low"
        delete form; form = NULL;
    }

    std::cout << "\n========== Fin des tests ==========" << std::endl;
    return 0;
}