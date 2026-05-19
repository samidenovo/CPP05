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
        Form(const std::string name, int signGrade, int execGrade);
        Form(const Form &other);
        Form    &operator=(const Form &other);
        ~Form();

        const std::string   &getName() const;
        bool                getIsSigned() const;
        int                 getSignGrade() const;
        int                 getExecGrade() const;

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
        const int           _signGrade;
        const int           _execGrade;
};

std::ostream    &operator<<(std::ostream &o, const Form &form);

#endif