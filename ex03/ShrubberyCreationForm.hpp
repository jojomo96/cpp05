#pragma once
#include "AForm.hpp"

class ShrubberyCreationForm final : public AForm {
public:
	explicit ShrubberyCreationForm(const std::string &target);

	ShrubberyCreationForm(ShrubberyCreationForm const &src);

	~ShrubberyCreationForm() override;

	ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);

	void execute(const Bureaucrat &executor) const override;
};
