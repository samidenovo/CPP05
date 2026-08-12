#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern()
{
}

Intern::Intern(const Intern &other)
{
    (void)other;
}

Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    return (*this);
}

Intern::~Intern()
{
}

static AForm *makeShrubbery(const std::string &target)
{
    return (new ShrubberyCreationForm(target));
}

static AForm *makeRobotomy(const std::string &target)
{
    return (new RobotomyRequestForm(target));
}

static AForm *makePresidential(const std::string &target)
{
    return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) const
{
    const char *names[] = {"shrubbery creation", "robotomy request", "presidential pardon"};

    AForm *(*makers[])(const std::string &) = {&makeShrubbery, &makeRobotomy, &makePresidential};

    for (int i = 0; i < 3; ++i)
    {
        if (formName == names[i])
        {
            std::cout << "Intern creates " << formName << std::endl;
            return (makers[i](target));
        }
    }

    std::cout << "Intern can't create " << formName << std::endl;
    return (NULL);
}

const char *Intern::UnknownFormException::what() const throw()
{
    return ("Intern: Unknown form");
}

std::ostream &operator<<(std::ostream &o, const Intern &intern)
{
    (void)intern;
    o << "Intern";
    return (o);
}