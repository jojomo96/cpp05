#pragma once
#include "AForm.hpp"

class PresidentialPardonForm final : public AForm {
	PresidentialPardonForm();

public:
	explicit PresidentialPardonForm(const std::string &target);

	PresidentialPardonForm(PresidentialPardonForm const &src);

	~PresidentialPardonForm() override;

	PresidentialPardonForm &operator=(PresidentialPardonForm const &rhs);

	void execute(const Bureaucrat &executor) const override;
};
