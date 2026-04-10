#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

static void printSeparator(const std::string &title)
{
    std::cout << "\n========== " << title << " ==========" << std::endl;
}

int main(void)
{
    Intern someIntern;
    AForm *form = NULL;

    // -------------------------------------------------------
    // Test 1 : Intern cree un ShrubberyCreationForm
    // -------------------------------------------------------
    printSeparator("Test 1 : ShrubberyCreationForm");
    form = someIntern.makeForm("shrubbery creation", "garden");
    if (form)
    {
        std::cout << *form << std::endl;
        // Bureaucrat avec grade suffisant pour signer (<=145) et executer (<=137)
        try
        {
            Bureaucrat bob("Bob", 130);
            bob.signForm(*form);
            bob.executeForm(*form);
        }
        catch (std::exception &e)
        {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
        delete form;
        form = NULL;
    }

    // -------------------------------------------------------
    // Test 2 : Intern cree un RobotomyRequestForm
    // -------------------------------------------------------
    printSeparator("Test 2 : RobotomyRequestForm");
    form = someIntern.makeForm("robotomy request", "Bender");
    if (form)
    {
        std::cout << *form << std::endl;
        // Bureaucrat avec grade suffisant pour signer (<=72) et executer (<=45)
        try
        {
            Bureaucrat alice("Alice", 40);
            alice.signForm(*form);
            // On appelle plusieurs fois pour voir le 50/50
            alice.executeForm(*form);
            alice.executeForm(*form);
            alice.executeForm(*form);
            alice.executeForm(*form);
        }
        catch (std::exception &e)
        {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
        delete form;
        form = NULL;
    }

    // -------------------------------------------------------
    // Test 3 : Intern cree un PresidentialPardonForm
    // -------------------------------------------------------
    printSeparator("Test 3 : PresidentialPardonForm");
    form = someIntern.makeForm("presidential pardon", "Zaphod");
    if (form)
    {
        std::cout << *form << std::endl;
        // Bureaucrat avec grade suffisant pour signer (<=25) et executer (<=5)
        try
        {
            Bureaucrat president("President", 1);
            president.signForm(*form);
            president.executeForm(*form);
        }
        catch (std::exception &e)
        {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
        delete form;
        form = NULL;
    }

    // -------------------------------------------------------
    // Test 4 : Formulaire inexistant
    // -------------------------------------------------------
    printSeparator("Test 4 : Formulaire inexistant");
    form = someIntern.makeForm("coffee request", "Nobody");
    if (!form)
        std::cout << "Aucun formulaire cree (attendu)" << std::endl;

    // -------------------------------------------------------
    // Test 5 : Grade trop bas pour signer
    // -------------------------------------------------------
    printSeparator("Test 5 : Grade trop bas pour signer");
    form = someIntern.makeForm("presidential pardon", "Target");
    if (form)
    {
        try
        {
            Bureaucrat weakling("Weakling", 150);
            weakling.signForm(*form);   // doit echouer
            weakling.executeForm(*form); // ne doit pas s'executer
        }
        catch (std::exception &e)
        {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
        delete form;
        form = NULL;
    }

    // -------------------------------------------------------
    // Test 6 : Formulaire non signe, execution refusee
    // -------------------------------------------------------
    printSeparator("Test 6 : Execution sans signature");
    form = someIntern.makeForm("robotomy request", "HAL");
    if (form)
    {
        try
        {
            Bureaucrat exec("Exec", 1);
            exec.executeForm(*form); // non signe -> doit echouer
        }
        catch (std::exception &e)
        {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
        delete form;
        form = NULL;
    }

    std::cout << "\n========== Fin des tests ==========" << std::endl;
    return 0;
}