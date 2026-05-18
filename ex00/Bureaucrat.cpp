#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
    : _name("JonDoe"), _grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string name, int grade)
    : _name(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    else
        _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
    : _name(other.getName()), _grade(other.getGrade())
{
}

Bureaucrat  &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
        _grade = other.getGrade();
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
}

const std::string   &Bureaucrat::getName() const
{
    return (_name);
}

int Bureaucrat::getGrade() const
{
    return (_grade);
}

void    Bureaucrat::incrementGrade()
{
    if (_grade == 1)
        throw GradeTooHighException();
    else
        _grade -= 1;
}

void    Bureaucrat::decrementGrade()
{
    if (_grade == 150)
        throw GradeTooLowException();
    else
        _grade += 1;
}

const char  *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char  *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}

std::ostream    &operator<<(std::ostream &o, const Bureaucrat &bureaucrat)
{
    o << bureaucrat.getName()
        << ", bureaucrat grade "
        << bureaucrat.getGrade()
        << ".";
    return (o);
}