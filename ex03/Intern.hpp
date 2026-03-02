#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include <exception>

class Intern {
public:
	Intern();
	~Intern();

	Intern(const Intern &other);
	Intern &operator=(const Intern &other);

	AForm *makeForm(const std::string formName, const std::string formTarget);

	class FormDoesNotExistException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
};

#endif