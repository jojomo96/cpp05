#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm("Robotomy Request", 72, 45, target) {
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) = default;

RobotomyRequestForm::~RobotomyRequestForm() = default;

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs) {
	if (this != &rhs) {
		AForm::operator=(rhs);
	}
	return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
	validateExecution(executor);

	std::cout << "Bzzzz... Bzzzz... " << std::endl;
	std::srand(std::time(nullptr));
	if (std::rand() % 2) {
		std::cout << getTarget() << " has been robotomized successfully." << std::endl;
	} else {
		std::cout << "Robotomy failed on " << getTarget() << "." << std::endl;
	}
}
