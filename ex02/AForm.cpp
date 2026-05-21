#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
    : _name("Generic AForm"), _isSigned(false), _signGrade(75), _execGrade(75)
{
}

AForm::AForm(const std::string name, int signGrade, int execGrade)
    : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
    if (_signGrade > 150 || _execGrade > 150)
        throw GradeTooLowException();
    if (_signGrade < 1 || _execGrade < 1)
        throw GradeTooHighException(); 
}

AForm::AForm(const AForm &other)
    : _name(other.getName()), _isSigned(other.getIsSigned()), _signGrade(other.getSignGrade()), _execGrade(other.getExecGrade())
{
}

AForm    &AForm::operator=(const AForm &other)
{
    if (this != &other)
        _isSigned = other.getIsSigned();
    return (*this);
}

AForm::~AForm()
{
}

const std::string   &AForm::getName() const
{
    return (_name);
}

bool    AForm::getIsSigned() const
{
    return (_isSigned);
}

int   AForm::getSignGrade() const
{
    return (_signGrade);
}

int   AForm::getExecGrade() const
{
    return (_execGrade);
}

void    AForm::beSigned(const Bureaucrat &bureau)
{
    if (_signGrade >= bureau.getGrade())
        _isSigned = true;
    else
        throw GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}

std::ostream    &operator<<(std::ostream &o, const AForm &form)
{
    o << form.getName()
        << ", signed: " << (form.getIsSigned() ? "yes" : "no")
        << ", sign grade: " << form.getSignGrade()
        << ", execute grade: " << form.getExecGrade()
        << ".";
    return (o);
}