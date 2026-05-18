#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat a("Jao", 3);

        std::cout << "Bureaucrat 'a' created\n" << a << std::endl;
        while (true)
        {
            a.incrementGrade();
            std::cout << "Bureaucrat 'a' incremented\n" << a << std::endl;
        }
    }
    catch (std::exception &e)
    {
        std::cout << "Unable to increment 'a': " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat b;
        Bureaucrat c("Zeh", 51);

        std::cout << "Bureaucrat 'b' created\n" << b << std::endl;
        std::cout << "Bureaucrat 'c' created\n" << c << std::endl;

        c = b;
        std::cout << "Bureaucrat 'c' after operator=\n" << c << std::endl;

        while (true)
        {
            c.decrementGrade();
            std::cout << "Bureaucrat 'c' decremented\n" << c << std::endl;
        }
    }
    catch (std::exception &e)
    {
        std::cout << "Unable to decrement 'c': " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat d("BadLow", 151);
        std::cout << d << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Unable to create bureaucrat 'd': " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat f("BadHigh", 0);
        std::cout << f << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Unable to create bureaucrat 'f': " << e.what() << std::endl;
    }

    return (0);
}