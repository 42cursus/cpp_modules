/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 21:30:22 by abelov            #+#    #+#             */
/*   Updated: 2025/07/25 21:30:23 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/*
** -------------------------------- STATIC VARS -------------------------------
*/
const AForm::RequiredGrades PresidentialPardonForm::REQUIRED_GRADES = {
        .SIGN = 25,
        .EXEC = 5
};

/*
** ------------------------------- CONSTRUCTORS -------------------------------
*/

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm("PresidentialPardonForm", REQUIRED_GRADES.SIGN, REQUIRED_GRADES.EXEC)
    , _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
    : AForm(other)
    , _target(other._target)
{}

/*
** ------------------------------- DESTRUCTORS --------------------------------
*/

PresidentialPardonForm::~PresidentialPardonForm() {}

/*
** -------------------------------- OPERATORS ---------------------------------
*/

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}


/*
** -------------------------------- OVERLOADS ---------------------------------
*/

std::ostream& operator<<(std::ostream& oss, const PresidentialPardonForm& form)
{
    oss << std::boolalpha
        << "PresidentialPardonForm name "
        << form.getName()
        << (form.isSigned() ? " is signed" : " is awaiting signature")
        << " and Grade to Sign: "
        << form.getGradeToSign()
        << " and grade to Execute: "
        << form.getGradeToExecute()
        << std::endl;
    return oss;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void PresidentialPardonForm::execute(const Bureaucrat &bureaucrat) const {
    if (!isSigned())
        throw PresidentialPardonForm::FormIsNotSignedException();
    if (bureaucrat.getGrade() > getGradeToExecute())
        throw PresidentialPardonForm::GradeTooLowException();
    if (bureaucrat.getGrade() <= getGradeToExecute())
    {
        std::cout << _target
                  << " has been pardoned by Zaphod Beeblebrox"
                  << std::endl;
    }
}

/*
** -------------------------------- ACCESSORS ---------------------------------
*/

/*
** -------------------------------- EXCEPTIONS --------------------------------
*/

/*
** -------------------------------- MISCELLANEOUS --------------------------------
*/


