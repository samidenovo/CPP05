#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <exception>

class   Bureaucrat;

class   Form
{
    public:
        Form();
        Form(const std::string name, int signIt, int execIt);
        Form(const Form &other);
        Form    operator=(Form &other);
        ~Form();

        const std::string   &getName() const;
        std::string         getIsSigned() const;
        const int           getSignIt() const;
        const int           getExecIt() const;

        void                beSigned(const Bureaucrat &bureau);

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char  *what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char  *what() const throw();
        };
    private:
        const std::string   _name;
        bool                _isSigned;
        const int           _signIt;
        const int           _execIt;
};

std::ostream    &operator<<(std::ostream &o, Form &form);

#endif