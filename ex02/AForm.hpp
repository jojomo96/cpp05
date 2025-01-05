#pragma once
#include <ostream>

class Bureaucrat;

class AForm {
	const std::string _name;
	const std::string _target;
	bool _signed;
	const int _signGrade;
	const int _execGrade;
public:
	explicit AForm(std::string name, int signGrade, int execGrade, std::string target);

	AForm(AForm const &src);

	virtual ~AForm();

	AForm &operator=(AForm const &rhs);

	[[nodiscard]] std::string getName() const;

	[[nodiscard]] std::string getTarget() const;

	[[nodiscard]] bool isSigned() const;

	[[nodiscard]] int getSignGrade() const;

	[[nodiscard]] int getExecGrade() const;

	void beSigned(const Bureaucrat &bureaucrat);

	void signForm(const Bureaucrat &bureaucrat);

	virtual void execute(const Bureaucrat &executor) const = 0;

	void validateExecution(const Bureaucrat &executor) const;

	class FormNotSignedException final : public std::exception {
	public:
		[[nodiscard]] const char *what() const noexcept override;
	};

	class GradeTooHighException final : public std::exception {
	public:
		[[nodiscard]] const char *what() const noexcept override;
	};

	class GradeTooLowException final : public std::exception {
	public:
		[[nodiscard]] const char *what() const noexcept override;
	};
};

std::ostream &operator<<(std::ostream &os, const AForm &form);
