#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

void testFormCreation() {
	try {
		Form f1("Form1", 1, 1);
		std::cout << f1 << std::endl;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Form f2("Form2", 150, 150);
		std::cout << f2 << std::endl;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Form f3("Form3", 0, 1); // Should throw GradeTooHighException
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Form f4("Form4", 1, 151); // Should throw GradeTooLowException
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

void testFormSigning() {
	Bureaucrat b1("Alice", 1);
	Bureaucrat b2("Bob", 150);

	Form f1("Form1toBeSigned", 1, 1);
	Form f2("Form2toBeSigned", 150, 150);

	try {
		f1.beSigned(b1); // Should succeed
		std::cout << f1 << std::endl;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		f1.beSigned(b2); // Should throw GradeTooLowException
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		f2.beSigned(b2); // Should succeed
		std::cout << f2 << std::endl;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		f2.beSigned(b1); // Should succeed
		std::cout << f2 << std::endl;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

void testSignForm() {
	Bureaucrat b1("Alice", 1);
	Bureaucrat b2("Bob", 150);

	Form f1("Form1", 1, 1);
	Form f2("Form2", 150, 150);

	std::cout << std::endl;
	std::cout << "Expected: Alice signs Form1" << std::endl;
	f1.signForm(b1); // Should succeed
	std::cout << std::endl;

	std::cout << "Expected: Bob cannot sign Form1 because Grade is too low!" << std::endl;
	f1.signForm(b2); // Should throw GradeTooLowException
	std::cout << std::endl;

	std::cout << "Expected: Bob signs Form2" << std::endl;
	f2.signForm(b2); // Should succeed
	std::cout << std::endl;

	std::cout << "Expected: Alice signs Form2" << std::endl;
	f2.signForm(b1); // Should succeed
	std::cout << std::endl;
}


int main() {
	testFormCreation();
	testFormSigning();
	testSignForm();
	return 0;
}
