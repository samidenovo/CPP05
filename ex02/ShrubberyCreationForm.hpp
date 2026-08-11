#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

class   ShrubberyCreationForm : public AForm
{
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm &other);
        ShrubberyCreationForm  &operator=(const ShrubberyCreationForm &other);
        ~ShrubberyCreationForm();

        const std::string       &getTarget() const;

        void                    executeAction() const;

    private:
        std::string _target;
};

#endif