#include "Intern.hpp"

#include <iostream>

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

const FormType Intern::_formTypes[3] = {
	{"robotomy request", [](const std::string &target) -> AForm* { return new RobotomyRequestForm(target); }},
	{"presidential pardon", [](const std::string &target) -> AForm* { return new PresidentialPardonForm(target); }},
	{"shrubbery creation", [](const std::string &target) -> AForm* { return new ShrubberyCreationForm(target); }}
};

Intern::Intern() = default;

Intern::Intern(Intern const &src) = default;

Intern::~Intern() = default;

Intern &Intern::operator=(Intern const &rhs) = default;

AForm *Intern::makeForm(const std::string &formName, const std::string &target) {
	for (const auto &formType : _formTypes) {
		if (formType.name == formName) {
			std::cout << "Intern creates " << formName << std::endl;
			return formType.creator(target);
		}
	}
	std::cout << "Form name not recognized" << std::endl;
	return nullptr;
}
