#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat bob("Bob", 151);
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Bureaucrat joe("Joe", 0);
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Bureaucrat bill("Bill", 1);
		std::cout << bill << std::endl;
		bill.IncrementGrade();
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
