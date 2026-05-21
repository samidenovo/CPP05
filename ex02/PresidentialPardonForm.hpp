#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

class   PresidentialPardonForm : public AForm
{
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string target);
        PresidentialPardonForm(const PresidentialPardonForm &other);
        PresidentialPardonForm  &operator=(const PresidentialPardonForm &other);
        ~PresidentialPardonForm();

        const std::string       &getTarget() const;

        void                    execute(Bureaucrat const &executor) const;

    private:
        std::string _target;
};

#endif