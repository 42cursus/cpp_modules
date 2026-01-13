/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 21:26:50 by abelov            #+#    #+#             */
/*   Updated: 2025/07/25 21:26:51 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

/*
** -------------------------------- STATIC VARS -------------------------------
*/

const   std::string& Form::DEFAULT_NAME = "default";

/*
** ------------------------------- CONSTRUCTORS -------------------------------
*/

// NOLINTNEXTLINE(bugprone-easily-swappable-parameters)
Form::Form(const int gradeToExecute, const int gradeToSign)
        : _name(DEFAULT_NAME)
        , _gradeToSign(gradeToSign)
        , _gradeToExecute(gradeToExecute)
        , _isSigned(false)
{}

// NOLINTNEXTLINE(bugprone-easily-swappable-parameters)
Form::Form(const std::string& name, const int gradeToSign, const int gradeToExecute)
        : _name(name)
        , _gradeToSign(gradeToSign)
        , _gradeToExecute(gradeToExecute)
        , _isSigned(false)
{}

Form::Form(const Form &other)
        : _name(other._name)
        , _gradeToSign(other._gradeToSign)
        , _gradeToExecute(other._gradeToExecute)
        , _isSigned(other._isSigned) {}

/*
** ------------------------------- DESTRUCTORS --------------------------------
*/

Form::~Form() {}

/*
** -------------------------------- OPERATORS ---------------------------------
*/

/**
 * For completeness: using `placement new` to replace object with const class members;
 * // Explicitly destroy the current object
 * this->~Form();
 *
 * // Reconstruct in the same memory location
 * new (this) Form(other);
 */
Form &Form::operator=(const Form &other) {
    if (this != &other) {
        _isSigned = other._isSigned;
    }
    return *this;
}

/*
** -------------------------------- OVERLOADS ---------------------------------
*/

std::ostream& operator<<(std::ostream& oss, const Form& other)
{
    oss << std::boolalpha;
    oss << "Form name ";
    oss << other.getName() << " with sign " ;
    oss << other.isSigned() << " and Grade to Sign: ";
    oss << other.getGradeToSign() << " and grade to Execute: " ;
    oss << other.getGradeToExecute() << std::endl;
    return oss;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() <= this->getGradeToSign())
        this->_isSigned = true;
    else
        throw Form::GradeTooLowException();
}

/*
** -------------------------------- ACCESSORS ---------------------------------
*/

const std::string &Form::getName() const {
    return _name;
}

bool Form::isSigned() const {
    return _isSigned;
}

int Form::getGradeToSign() const {
    return _gradeToSign;
}

int Form::getGradeToExecute() const {
    return _gradeToExecute;
}

/*
** -------------------------------- EXCEPTIONS --------------------------------
*/

const char *Form::GradeTooHighException::what() const throw() {
    return "Grade is too High";
}

const char *Form::GradeTooLowException::what() const throw() {
    return "Grade is too Low";
}

/*
** -------------------------------- MISCELLANEOUS --------------------------------
*/


