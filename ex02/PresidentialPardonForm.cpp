#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: AForm("Presidential Pardon", 25, 5, target) {
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) = default;

PresidentialPardonForm::~PresidentialPardonForm() = default;

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs) {
	if (this != &rhs) {
		AForm::operator=(rhs);
	}
	return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
	validateExecution(executor);

	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
