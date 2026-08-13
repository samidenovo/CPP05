#include <iostream>
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main()
{
    Intern someRandomIntern;
    Bureaucrat boss("Boss", 1);
    Bureaucrat rookie("Rookie", 150);

    AForm *f1 = someRandomIntern.makeForm("robotomy request", "Bender");
    AForm *f2 = someRandomIntern.makeForm("shrubbery creation", "home");
    AForm *f3 = someRandomIntern.makeForm("presidential pardon", "Arthur");
    AForm *f4 = someRandomIntern.makeForm("not a form", "nobody"); // should fail

    std::cout << std::endl << "Signing and executing" << std::endl;

    if (f1)
    {
        boss.signForm(*f1);
        boss.executeForm(*f1);
        delete f1;
    }

    if (f2)
    {
        rookie.signForm(*f2); // likely fail
        boss.signForm(*f2);
        boss.executeForm(*f2);
        delete f2;
    }

    if (f3)
    {
        boss.signForm(*f3);
        boss.executeForm(*f3);
        delete f3;
    }

    if (f4)
    {
        delete f4;
    }

    return 0;
}