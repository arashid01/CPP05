#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat John("John", 1);
        Bureaucrat Bob("Bob", 150);

        Form contract("Contract", 50, 25);

        std::cout << contract << std::endl;

        Bob.signForm(contract);
        John.signForm(contract);

        std::cout << contract << std::endl;
    }

    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return (0);
}