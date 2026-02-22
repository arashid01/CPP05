#ifndef FORM_HPP
#define FORM_HPP

#include <exception>
#include <iostream>

class Bureaucrat;

class AForm {

	const std::string	_name;
	bool				_signed;
	const int			_sign_grade;
	const int			_execute_grade;
	virtual void		executeAction() const = 0;

public:
	AForm();
	~AForm();

	AForm(const std::string name, const int sign_grade, const int execute_grade);
	AForm(const AForm &other);
	AForm &operator=(const AForm &other);

	std::string getName() const;
	bool getIsSigned() const;
	int getSignGrade() const;
	int getExecuteGrade() const;

	void beSigned(const Bureaucrat &burea);

	void setIsSigned(bool is_signed);
	void execute(const Bureaucrat &executor) const;

	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class IsNotSignedException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

};

std::ostream &operator<<(std::ostream &os, AForm const &form);

#endif