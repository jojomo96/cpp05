#pragma once
#include <ostream>

class Bureaucrat {
	const std::string _name;
	int _grade = 0;

	Bureaucrat();

public:
	explicit Bureaucrat(std::string name, int grade);

	Bureaucrat(Bureaucrat const &src);

	~Bureaucrat();

	Bureaucrat &operator=(Bureaucrat const &rhs);

	[[nodiscard]] std::string getName() const;

	[[nodiscard]] int getGrade() const;

	void incrementGrade(int amount);

	void decrementGrade(int amount);

	class GradeTooHighException final : public std::exception {
	public:
		[[nodiscard]] const char *what() const noexcept override;
	};

	class GradeTooLowException final : public std::exception {
	public:
		[[nodiscard]] const char *what() const noexcept override;
	};
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);
