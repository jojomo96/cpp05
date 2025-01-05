#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

void testInternMakeForm() {
	Intern intern;
	Bureaucrat bureaucrat("John Doe", 1);

	AForm *form1 = intern.makeForm("robotomy request", "Target1");
	AForm *form2 = intern.makeForm("presidential pardon", "Target2");
	AForm *form3 = intern.makeForm("shrubbery creation", "Target3");
	AForm *form4 = intern.makeForm("unknown form", "Target4");

	if (form1) {
		form1->beSigned(bureaucrat);
		form1->execute(bureaucrat);
		delete form1;
	}

	if (form2) {
		form2->beSigned(bureaucrat);
		form2->execute(bureaucrat);
		delete form2;
	}

	if (form3) {
		form3->beSigned(bureaucrat);
		form3->execute(bureaucrat);
		delete form3;
	}

	if (!form4) {
		std::cout << "Form creation failed as expected for unknown form" << std::endl;
	}
}

int main() {
	testInternMakeForm();
	return 0;
}
