#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, const int grade) : _name(std::move(name)), _grade(grade) {
	if (grade < 1) {
		throw GradeTooHighException();
	}
	if (grade > 150) {
		throw GradeTooLowException();
	}
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) = default;

Bureaucrat::~Bureaucrat() = default;

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs) {
	if (this != &rhs) {
		_grade = rhs._grade;
	}
	return *this;
}

std::string Bureaucrat::get_name() const {
	return _name;
}

int Bureaucrat::get_grade() const {
	return _grade;
}

void Bureaucrat::increment_grade(const int amount) {
	if (_grade - amount < 1) {
		throw GradeTooHighException();
	}
	if (_grade - amount > 150) {
		throw GradeTooLowException();
	}
	_grade -= amount;
}

void Bureaucrat::decrement_grade(const int amount) {
	if (_grade + amount > 150) {
		throw GradeTooLowException();
	}
	if (_grade + amount < 1) {
		throw GradeTooHighException();
	}
	_grade += amount;
}

const char *Bureaucrat::GradeTooHighException::what() const noexcept {
	return "Grade is too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const noexcept {
	return "Grade is too low!";
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &bureaucrat) {
	os << bureaucrat.get_name() << ", bureaucrat grade " << bureaucrat.get_grade() << ".";
	return os;
}
