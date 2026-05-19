#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "========================" << std::endl;
    std::cout << "===== Signing Form =====" << std::endl;
    try
    {
        Bureaucrat  high("Zuzu", 1);
        Bureaucrat  low("Mama", 150);
        Form        aForm("A Form", 50, 25);

        std::cout << high << std::endl;
        std::cout << low << std::endl;
        std::cout << aForm << std::endl;

        low.signForm(aForm);
        std::cout << aForm << std::endl;

        high.signForm(aForm);
        std::cout << aForm << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "========================" << std::endl;
    std::cout << "==== Bad Grade Form ====" << std::endl;
    try
    {
        Form    tooHigh("Too High", 0, 50);
        std::cout << tooHigh << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Unable to create form: " << e.what() << std::endl;
    }

    try
    {
        Form    tooLow("Too Low", 50, 151);
        std::cout << tooLow << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Unable to create form: " << e.what() << std::endl;
    }

    return (0);
}