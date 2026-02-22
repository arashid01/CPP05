#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <exception>

class RobotomyRequestForm : public AForm
{
	std::string	_target;
	void executeAction() const;

public:
	RobotomyRequestForm();
	~RobotomyRequestForm();

	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &other);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

	class RobotomyFailedException : public std::exception {
	public:
		virtual const char *what() const throw();
	};
};

#endif