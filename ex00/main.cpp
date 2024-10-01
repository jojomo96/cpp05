#include <iostream>

#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat b1("Alice", 50);
		std::cout << b1 << std::endl;

		Bureaucrat b2("Bob", 1);
		std::cout << b2 << std::endl;

		// Test assignment operator
		b1 = b2;
		std::cout << "After assignment, b1: " << b1 << std::endl;

		Bureaucrat b3(b2);
		b3.increment_grade(-1);
		std::cout << "After copy, b3: " << b3 << std::endl;

		// Test grade too high exception
		try {
			Bureaucrat b3("Charlie", 0);
		} catch (const Bureaucrat::GradeTooHighException &e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}

		// Test grade too low exception
		try {
			Bureaucrat b4("Dave", 151);
		} catch (const Bureaucrat::GradeTooLowException &e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}

	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
