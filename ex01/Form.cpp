#include "Form.hpp"

#include <iostream>

#include "Bureaucrat.hpp"

Form::Form(std::string name, const int signGrade, const int execGrade)
	: _name(std::move(name)), _signed(false), _signGrade(signGrade), _execGrade(execGrade) {
	if (signGrade < 1 || execGrade < 1) {
		throw GradeTooHighException();
	}
	if (signGrade > 150 || execGrade > 150) {
		throw GradeTooLowException();
	}
}

Form::Form(Form const &src) = default;

Form::~Form() = default;

Form &Form::operator=(Form const &rhs) {
	if (this != &rhs) {
		_signed = rhs._signed;
	}
	return *this;
}

std::string Form::getName() const {
	return _name;
}

bool Form::isSigned() const {
	return _signed;
}

int Form::getSignGrade() const {
	return _signGrade;
}

int Form::getExecGrade() const {
	return _execGrade;
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > _signGrade) {
		throw GradeTooLowException();
	}
	_signed = true;
}

void Form::signForm(const Bureaucrat &bureaucrat) {
	try {
		beSigned(bureaucrat);
		std::cout << bureaucrat.getName() << " signs " << _name << std::endl;
	} catch (const GradeTooLowException &e) {
		std::cerr << bureaucrat.getName() << " cannot sign " << _name << " because " << e.what() << std::endl;
	}
}

const char *Form::GradeTooHighException::what() const noexcept {
	return "Grade is too high!";
}

const char *Form::GradeTooLowException::what() const noexcept {
	return "Grade is too low!";
}

std::ostream &operator<<(std::ostream &os, const Form &form) {
	os << "Form " << form.getName() << ", sign grade " << form.getSignGrade()
	   << ", execution grade " << form.getExecGrade() << ", signed: " << (form.isSigned() ? "yes" : "no");
	return os;
}
