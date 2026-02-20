#include "Form.hpp"

Form::Form() : _name("default"), _signed(false), _sign_grade(150), _execute_grade(150) {}

Form::~Form() {}

Form::Form(const std::string name, const int sign_grade, const int execute_grade) : _name(name), _signed(false), _sign_grade(sign_grade), _execute_grade(execute_grade) {}

Form::Form(const Form &other) : _name(other._name), _signed(other._signed), _sign_grade(other._sign_grade), _execute_grade(other._execute_grade) {}

Form &Form::operator=(const Form &other) {
	if (this != &other)
		_signed = other._signed;
	return (*this);
}

std::string Form::getName() const {
	return (_name);
}

bool Form::getIsSigned() const {
	return(_signed);
}

int Form::getSignGrade() const {
	return (_sign_grade);
}

int Form::getExecuteGrade() const {
	return (_execute_grade);
}

void Form::beSigned(Bureaucrat const &bureau) {
	if (bureau.getGrade() <= _sign_grade)
		_signed = true;
	else
		throw (GradeTooLowException());
}

const char *Form::GradeTooHighException::what() const throw() {
	return ("Grade is too high");
}

const char *Form::GradeTooLowException::what() const throw() {
	return ("Grade is too low");
}

std::ostream &os(std::ostream &os, Form const &form) {
	os << "Name: " << form.getName()
		<< " Is signed: " << form.getIsSigned()
		<< " Sign grade: " << form.getSignGrade()
		<< " Execute grade: " << form.getExecuteGrade()
		<< std::endl;
	return (os);
}