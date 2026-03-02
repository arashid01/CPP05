#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {
        Bureaucrat John("John", 1);
        Bureaucrat Bob("Bob", 140);

        ShrubberyCreationForm shrub("home");
        RobotomyRequestForm robot("Bill");
        PresidentialPardonForm pardon("Alice");

        Bob.signAForm(shrub);
        Bob.executeForm(shrub);

        John.executeForm(shrub);

        John.signAForm(robot);
        John.executeForm(robot);

        John.signAForm(pardon);
        John.executeForm(pardon);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}