#include "AForm.hpp"

#include <iostream>

#include "Bureaucrat.hpp"

AForm::AForm() : _name("default"), _target("default"), _signed(false), _signGrade(150), _execGrade(150) {
}

AForm::AForm(std::string name, const int signGrade, const int execGrade, std::string target)
	: _name(std::move(name)), _target(std::move(target)), _signed(false), _signGrade(signGrade), _execGrade(execGrade) {
	if (signGrade < 1 || execGrade < 1) {
		throw GradeTooHighException();
	}
	if (signGrade > 150 || execGrade > 150) {
		throw GradeTooLowException();
	}
}

AForm::AForm(AForm const &src) = default;

AForm::~AForm() = default;

AForm &AForm::operator=(AForm const &rhs) {
	if (this != &rhs) {
		_signed = rhs._signed;
	}
	return *this;
}

std::string AForm::getName() const {
	return _name;
}

std::string AForm::getTarget() const {
	return _target;
}

bool AForm::isSigned() const {
	return _signed;
}

int AForm::getSignGrade() const {
	return _signGrade;
}

int AForm::getExecGrade() const {
	return _execGrade;
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > _signGrade) {
		throw GradeTooLowException();
	}
	_signed = true;
}

void AForm::signForm(const Bureaucrat &bureaucrat) {
	try {
		beSigned(bureaucrat);
		std::cout << bureaucrat.getName() << " signs " << _name << std::endl;
	} catch (const GradeTooLowException &e) {
		std::cerr << bureaucrat.getName() << " cannot sign " << _name << " because " << e.what() << std::endl;
	}
}

void AForm::validateExecution(const Bureaucrat &executor) const {
	if (!isSigned()) {
		throw FormNotSignedException();
	}
	if (executor.getGrade() > getExecGrade()) {
		throw GradeTooLowException();
	}
}

const char *AForm::FormNotSignedException::what() const noexcept {
	return "Form is not signed!";
}

const char *AForm::GradeTooHighException::what() const noexcept {
	return "Grade is too high!";
}

const char *AForm::GradeTooLowException::what() const noexcept {
	return "Grade is too low!";
}

std::ostream &operator<<(std::ostream &os, const AForm &form) {
	os << "AForm " << form.getName() << ", sign grade " << form.getSignGrade()
			<< ", execution grade " << form.getExecGrade() << ", signed: " << (form.isSigned() ? "yes" : "no");
	return os;
}
