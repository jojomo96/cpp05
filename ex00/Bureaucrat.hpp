#pragma once
#include <ostream>

class Bureaucrat {
	const std::string _name;
	int _grade;

public:
	explicit Bureaucrat(std::string name, int grade);

	Bureaucrat(Bureaucrat const &src);

	~Bureaucrat();

	Bureaucrat &operator=(Bureaucrat const &rhs);

	[[nodiscard]] std::string get_name() const;

	[[nodiscard]] int get_grade() const;

	void increment_grade(int amount);

	void decrement_grade(int amount);

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
