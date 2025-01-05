#pragma once
#include <string>

class AForm;

struct FormType {
	const char *name;

	AForm * (*creator)(const std::string &);
};

class Intern {
	static const FormType _formTypes[3];

public:
	Intern();

	Intern(Intern const &src);

	~Intern();

	Intern &operator=(Intern const &rhs);

	static AForm *makeForm(const std::string &formName, const std::string &target);
};
