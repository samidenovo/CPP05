#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
    : _name("Generic Form"), _isSigned(false), _signGrade(75), _execGrade(75)
{
}

Form::Form(const std::string name, int signGrade, int execGrade)
    : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
    if (_signGrade > 150 || _execGrade > 150)
        throw GradeTooLowException();
    if (_signGrade < 1 || _execGrade < 1)
        throw GradeTooHighException(); 
}

Form::Form(const Form &other)
    : _name(other.getName()), _isSigned(other.getIsSigned()), _signGrade(other.getSignGrade()), _execGrade(other.getExecGrade())
{
}

Form    &Form::operator=(const Form &other)
{
    if (this != &other)
        _isSigned = other.getIsSigned();
    return (*this);
}

Form::~Form()
{
}

const std::string   &Form::getName() const
{
    return (_name);
}

bool    Form::getIsSigned() const
{
    return (_isSigned);
}

int   Form::getSignGrade() const
{
    return (_signGrade);
}

int   Form::getExecGrade() const
{
    return (_execGrade);
}

void    Form::beSigned(const Bureaucrat &bureau)
{
    if (_signGrade >= bureau.getGrade())
        _isSigned = true;
    else
        throw GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}

std::ostream    &operator<<(std::ostream &o, const Form &form)
{
    o << form.getName()
        << ", signed: " << (form.getIsSigned() ? "yes" : "no")
        << ", sign grade: " << form.getSignGrade()
        << ", execute grade: " << form.getExecGrade()
        << ".";
    return (o);
}