#pragma once
#include <ostream>

class Bureaucrat;

class Form {
	const std::string _name;
	bool _signed;
	const int _signGrade;
	const int _execGrade;

	Form();

public:
	explicit Form(std::string name, int signGrade, int execGrade);

	Form(Form const &src);

	~Form();

	Form &operator=(Form const &rhs);

	[[nodiscard]] std::string getName() const;

	[[nodiscard]] bool isSigned() const;

	[[nodiscard]] int getSignGrade() const;

	[[nodiscard]] int getExecGrade() const;

	void beSigned(const Bureaucrat &bureaucrat);

	void signForm(const Bureaucrat &bureaucrat);

	class GradeTooHighException final : public std::exception {
	public:
		[[nodiscard]] const char *what() const noexcept override;
	};

	class GradeTooLowException final : public std::exception {
	public:
		[[nodiscard]] const char *what() const noexcept override;
	};
};

std::ostream &operator<<(std::ostream &os, const Form &form);
