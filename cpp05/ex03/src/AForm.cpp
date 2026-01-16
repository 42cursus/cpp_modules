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
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

/*
** -------------------------------- STATIC VARS -------------------------------
*/

const int AForm::GRADE_RANGE_MAX = 1;
const int AForm::GRADE_RANGE_MIN = 150;
const   std::string& AForm::DEFAULT_NAME = "default";

const AForm::CommandMap AForm::_commandMap = {
        .size = 3,
        .map = {
                {.key = std::string("presidential"), .value = PPF},
                {.key = std::string("robotomy"), .value = RRF},
                {.key = std::string("shrubbery"), .value = SCF},
        }
};

/*
** ------------------------------- CONSTRUCTORS -------------------------------
*/

// NOLINTNEXTLINE(bugprone-easily-swappable-parameters)
AForm::AForm(const int gradeToExecute, const int gradeToSign)
        : _name(DEFAULT_NAME)
        , _gradeToSign(gradeToSign)
        , _gradeToExecute(gradeToExecute)
        , _isSigned(false)
{
    if (gradeToSign > GRADE_RANGE_MIN || gradeToExecute > GRADE_RANGE_MIN)
        throw AForm::GradeTooHighException();
    if (gradeToSign < GRADE_RANGE_MAX || gradeToExecute < GRADE_RANGE_MAX)
        throw AForm::GradeTooLowException();
}

// NOLINTNEXTLINE(bugprone-easily-swappable-parameters)
AForm::AForm(const std::string& name, const int gradeToSign, const int gradeToExecute)
        : _name(name)
        , _gradeToSign(gradeToSign)
        , _gradeToExecute(gradeToExecute)
        , _isSigned(false)
{
    if (gradeToSign > GRADE_RANGE_MIN || gradeToExecute > GRADE_RANGE_MIN)
        throw AForm::GradeTooHighException();
    if (gradeToSign < GRADE_RANGE_MAX || gradeToExecute < GRADE_RANGE_MAX)
        throw AForm::GradeTooLowException();
}

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

AForm::Command AForm::getCommand(const std::string &input)
{
    Command command = NOT_FOUND;
    for (int i = 0; i < _commandMap.size; i++)
    {
        const CommandMap::CommandMapEntry &cmd = _commandMap.map[i];
        if (cmd.key == input)
            command = cmd.value;
    }
    return (command);
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

AForm *AForm::makeForm(std::string form_name, std::string target_name) {
    AForm* form = NULL;

    Command cmd = getCommand(form_name);

    switch (cmd) {

        case PPF:
            form = new PresidentialPardonForm(target_name);
            break;
        case RRF:
            form = new RobotomyRequestForm(target_name);
            break;
        case SCF:
            form = new ShrubberyCreationForm(target_name);
            break;
        case NOT_FOUND:
        default:
            break;
    }

    return (form);
}
