#pragma once
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	RobotomyRequestForm();

public:
	explicit RobotomyRequestForm(const std::string &target);

	RobotomyRequestForm(RobotomyRequestForm const &src);

	~RobotomyRequestForm() override;

	RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);

	void execute(const Bureaucrat &executor) const override;
};
