#include <iostream>
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

void testRobotomyRequestForm() {
	Bureaucrat bob("Bob", 1);
	Bureaucrat lowGrade("LowGrade", 150);
	RobotomyRequestForm form("Target1");

	// Not signed
	try {
		form.execute(bob);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	// Signed but grade too low
	try {
		form.signForm(bob);
		form.execute(lowGrade);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	// Signed and grade sufficient
	try {
		form.execute(bob);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

void testPresidentialPardonForm() {
	Bureaucrat alice("Alice", 1);
	Bureaucrat lowGrade("LowGrade", 150);
	PresidentialPardonForm form("Target2");

	// Not signed
	try {
		form.execute(alice);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	// Signed but grade too low
	try {
		form.signForm(alice);
		form.execute(lowGrade);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	// Signed and grade sufficient
	try {
		form.execute(alice);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

void testShrubberyCreationForm() {
	Bureaucrat charlie("Charlie", 1);
	Bureaucrat lowGrade("LowGrade", 150);
	ShrubberyCreationForm form("Target3");

	// Not signed
	try {
		form.execute(charlie);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	// Signed but grade too low
	try {
		form.signForm(charlie);
		form.execute(lowGrade);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	// Signed and grade sufficient
	try {
		form.execute(charlie);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

int main() {
	testRobotomyRequestForm();
	testPresidentialPardonForm();
	testShrubberyCreationForm();
	return 0;
}
