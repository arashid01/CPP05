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

AForm *Intern::makeForm(const std::string formName, const std::string formTarget) {
	std::string availableForms[] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};

	for (int i = 0; i < 3 && formName != availableForms[i]; i++)
	{
		switch (i) {
		case 0:
			std::cout << "Intern creates " << formName << std::endl;
			return (new ShrubberyCreationForm(formTarget));
		case 1:
			std::cout << "Intern creates " << formName << std::endl;
			return (new RobotomyRequestForm(formTarget));
		case 2:
			std::cout << "Intern creates " << formName << std::endl;
			return (new PresidentialPardonForm (formTarget));
		default:
			std::cout << "The Form " << formName << " does not exist" << std::endl;
		}
	}
	return (NULL);
}