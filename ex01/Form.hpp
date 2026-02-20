#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form {

	const std::string	_name;
	bool				_signed;
	const int			_sign_grade;
	const int			_execute_grade;

public:
	Form();
	~Form();

	Form(const std::string name, const int sign_grade, const int execute_grade);
	Form(const Form &other);
	Form &operator=(const Form &other);

	std::string getName() const;
	bool getIsSigned() const;
	int getSignGrade() const;
	int getExecuteGrade() const;

	void beSigned(Bureaucrat const &burea);

	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

};

std::ostream &os(std::ostream &os, Form const &form);

#endif