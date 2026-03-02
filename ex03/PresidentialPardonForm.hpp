#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <fstream>
#include <string>

class PresidentialPardonForm : public AForm
{
	std::string _target;
	void executeAction() const;

public:
	PresidentialPardonForm();
	~PresidentialPardonForm();

	PresidentialPardonForm(const std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &other);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
};

#endif