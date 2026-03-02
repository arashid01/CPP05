#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>
#include <exception>

class ShrubberyCreationForm : public AForm
{
	std::string _target;
	void executeAction() const;

public:
	ShrubberyCreationForm();
	~ShrubberyCreationForm();

	ShrubberyCreationForm(const std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

	class OpenFileException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

};

#endif