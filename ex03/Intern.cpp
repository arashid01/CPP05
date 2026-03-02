#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}
Intern::~Intern() {}

Intern::Intern(const Intern &other) {
	*this = other;
}

Intern &Intern::operator=(const Intern &other) {
	(void) other;
	return (*this);
}

AForm* Intern::makeForm(const std::string formName, const std::string formTarget) {
	std::string availableForms[3] = {
		"ShrubberyCreationForm",
		"RobotomyRequestForm",
		"PresidentialPardonForm"
	};

	for (int i = 0; i < 3; i++)
	{
		if (formName == availableForms[i])
		{
			std::cout << "Intern creates " << formName << std::endl;

			switch (i)
			{
				case 0:
					return (new ShrubberyCreationForm(formTarget));
				case 1:
					return (new RobotomyRequestForm(formTarget));
				case 2:
					return (new PresidentialPardonForm(formTarget));
			}
		}
	}

	std::cout << "The form " << formName << " does not exist" << std::endl;
	throw (FormDoesNotExistException());
}

const char* Intern::FormDoesNotExistException::what() const throw() {
	return ("Intern can't create this form: unknown form name");
}