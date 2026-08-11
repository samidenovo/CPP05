#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
    try
    {
        Bureaucrat high("High", 1);
        Bureaucrat mid("Mid", 50);
        Bureaucrat low("Low", 150);

        ShrubberyCreationForm shrub("home");
        RobotomyRequestForm robot("C3PO");
        PresidentialPardonForm pardon("Lula");

        std::cout << "Initial forms:" << std::endl;
        std::cout << shrub << std::endl;
        std::cout << robot << std::endl;
        std::cout << pardon << std::endl;

        std::cout << "\nSigning attempts:" << std::endl;
        low.signForm(shrub);   // fail
        mid.signForm(shrub);   // success
        high.signForm(robot);  // success
        high.signForm(pardon); // success

        std::cout << "\nExecution attempts:" << std::endl;
        low.executeForm(shrub);   // fail grade too low
        mid.executeForm(shrub);   // success writes file
        high.executeForm(robot);  // success or report robotomy failure
        high.executeForm(pardon); // success pardon message
    }
    catch (std::exception &e)
    {
        std::cout << "Unhandled exception: " << e.what() << std::endl;
    }

    return 0;
}