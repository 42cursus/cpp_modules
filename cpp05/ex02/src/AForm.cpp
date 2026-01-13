/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 21:26:50 by abelov            #+#    #+#             */
/*   Updated: 2025/07/25 21:26:51 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

/*
** -------------------------------- STATIC VARS -------------------------------
*/

const   std::string& AForm::DEFAULT_NAME = "default";

/*
** ------------------------------- CONSTRUCTORS -------------------------------
*/

// NOLINTNEXTLINE(bugprone-easily-swappable-parameters)
AForm::AForm(const int gradeToExecute, const int gradeToSign)
        : _name(DEFAULT_NAME)
        , _gradeToSign(gradeToSign)
        , _gradeToExecute(gradeToExecute)
        , _isSigned(false)
{}

// NOLINTNEXTLINE(bugprone-easily-swappable-parameters)
AForm::AForm(const std::string& name, const int gradeToSign, const int gradeToExecute)
        : _name(name)
        , _gradeToSign(gradeToSign)
        , _gradeToExecute(gradeToExecute)
        , _isSigned(false)
{}

AForm::AForm(const AForm &other)
        : _name(other._name)
        , _gradeToSign(other._gradeToSign)
        , _gradeToExecute(other._gradeToExecute)
        , _isSigned(other._isSigned) {}

/*
** ------------------------------- DESTRUCTORS --------------------------------
*/

AForm::~AForm() {}

/*
** -------------------------------- OPERATORS ---------------------------------
*/

/**
 * For completeness: using `placement new` to replace object with const class members;
 * // Explicitly destroy the current object
 * this->~AForm();
 *
 * // Reconstruct in the same memory location
 * new (this) AForm(other);
 */
AForm &AForm::operator=(const AForm &other) {
    if (this != &other) {
        _isSigned = other._isSigned;
    }
    return *this;
}

/*
** -------------------------------- OVERLOADS ---------------------------------
*/

std::ostream& operator<<(std::ostream& oss, const AForm& other)
{
    oss << std::boolalpha;
    oss << "AForm name ";
    oss << other.getName() << " with sign " ;
    oss << other.isSigned() << " and Grade to Sign: ";
    oss << other.getGradeToSign() << " and grade to Execute: " ;
    oss << other.getGradeToExecute() << std::endl;
    return oss;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() <= this->getGradeToSign())
        this->_isSigned = true;
    else
        throw AForm::GradeTooLowException();
}

/*
** -------------------------------- ACCESSORS ---------------------------------
*/

const std::string &AForm::getName() const {
    return _name;
}

bool AForm::isSigned() const {
    return _isSigned;
}

int AForm::getGradeToSign() const {
    return _gradeToSign;
}

int AForm::getGradeToExecute() const {
    return _gradeToExecute;
}

/*
** -------------------------------- EXCEPTIONS --------------------------------
*/

const char *AForm::GradeTooHighException::what() const throw() {
    return "Grade is too High";
}

const char *AForm::GradeTooLowException::what() const throw() {
    return "Grade is too Low";
}

const char *AForm::FormIsNotSignedException::what() const throw() {
    return ("The Form has not been signed!");
}


/*
** -------------------------------- MISCELLANEOUS --------------------------------
*/


