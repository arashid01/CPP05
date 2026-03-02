#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("default"), _signed(false), _sign_grade(150), _execute_grade(150) {}

AForm::~AForm() {}

AForm::AForm(const std::string name, const int sign_grade, const int execute_grade) : _name(name), _signed(false), _sign_grade(sign_grade), _execute_grade(execute_grade) {
	if (_sign_grade < 1 || _execute_grade < 1)
		throw (GradeTooHighException());
	else if (_sign_grade > 150 || _execute_grade > 150)
		throw (GradeTooLowException());
}

AForm::AForm(const AForm &other) : _name(other._name), _signed(other._signed), _sign_grade(other._sign_grade), _execute_grade(other._execute_grade) {}

AForm &AForm::operator=(const AForm &other) {
	if (this != &other)
		_signed = other._signed;
	return (*this);
}

std::string AForm::getName() const {
	return (_name);
}

bool AForm::getIsSigned() const {
	return(_signed);
}

int AForm::getSignGrade() const {
	return (_sign_grade);
}

int AForm::getExecuteGrade() const {
	return (_execute_grade);
}

void AForm::beSigned(const Bureaucrat &bureau) {
	if (bureau.getGrade() <= _sign_grade)
		_signed = true;
	else
		throw (GradeTooLowException());
}

void AForm::setIsSigned(bool is_signed) {
	_signed = is_signed;
}

void AForm::execute(const Bureaucrat &executor) const
{
	if (_signed == false)
		throw IsNotSignedException();
	if (_execute_grade < executor.getGrade())
		throw GradeTooLowException();

	executeAction();
}

const char *AForm::GradeTooHighException::what() const throw() {
	return ("Grade is too high");
}

const char *AForm::GradeTooLowException::what() const throw() {
	return ("Grade is too low");
}

const char *AForm::IsNotSignedException::what() const throw() {
	return ("Form can't be executed because it's not signed");
}

std::ostream &operator<<(std::ostream &os, AForm const &form) {
	os << "Name: " << form.getName()
		<< " Is signed: " << form.getIsSigned()
		<< " Sign grade: " << form.getSignGrade()
		<< " Execute grade: " << form.getExecuteGrade()
		<< std::endl;
	return (os);
}