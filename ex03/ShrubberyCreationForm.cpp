#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default") {}
ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other) {
	*this = other;
}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	if (this != &other) {
		_target = other._target;
		setIsSigned(other.getIsSigned());
	}
	return (*this);
}

void ShrubberyCreationForm::executeAction() const {
	std::string filename = _target + "_shrubbery";
	std::ofstream outFile(filename.c_str());

	if (outFile) {
		outFile  << "    /\\    \n"
				 << "   /  \\   \n"
				 << "  /    \\  \n"
				 << " /      \\ \n"
				 << "/________\\\n"
				 << "    ||    \n"
				 << "    ||    \n"
				 << "    ||    \n";

		outFile.close();
	}
	else
		throw (ShrubberyCreationForm::OpenFileException());
}

const char *ShrubberyCreationForm::OpenFileException::what() const throw() {
	return ("File error");
}