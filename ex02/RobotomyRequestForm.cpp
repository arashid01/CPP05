#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default") {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other) {
	*this = other;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	if (this != &other) {
		_target = other._target;
		setIsSigned(other.getIsSigned());
	}
	return (*this);
}

void RobotomyRequestForm::executeAction() const {
	int rand_num;

	rand_num = rand() % 2;
	if (rand_num == 1)
		std::cout << "Bzzzzz bzzz " << getName() << " has been robotomized successfully" << std::endl;
	else
		throw(RobotomyFailedException());
}

const char *RobotomyRequestForm::RobotomyFailedException::what() const throw() {
	return ("Robotomy failed");
}