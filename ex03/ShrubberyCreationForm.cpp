#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("Shrubbery Creation", 145, 137, target) {
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) = default;

ShrubberyCreationForm::~ShrubberyCreationForm() = default;

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs) {
	if (this != &rhs) {
		AForm::operator=(rhs);
	}
	return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
	validateExecution(executor);

	std::ofstream ofs(getTarget() + "_shrubbery");
	if (!ofs) {
		std::cerr << "Error: Could not open file." << std::endl;
		return;
	}

	ofs << "       _-_" << std::endl;
	ofs << "    /~~   ~~\\" << std::endl;
	ofs << " /~~         ~~\\" << std::endl;
	ofs << "{               }" << std::endl;
	ofs << " \\  _-     -_  /" << std::endl;
	ofs << "   ~  \\\\ //  ~" << std::endl;
	ofs << "_- -   | | _- _" << std::endl;
	ofs << "  _ -  | |   -_" << std::endl;
	ofs << "      // \\\\" << std::endl;

	ofs.close();
}
