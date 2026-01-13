/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 21:16:55 by abelov            #+#    #+#             */
/*   Updated: 2025/07/25 21:16:55 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

/*
** -------------------------------- STATIC VARS -------------------------------
*/

const int           Bureaucrat::GRADE_RANGE_MAX = 1;
const int           Bureaucrat::GRADE_RANGE_MIN = 150;
const               std::string& Bureaucrat::DEFAULT_NAME = "default";

const std::string   Bureaucrat::GradeGenericException::DEFAULT_MESSAGE = "GradeGenericException occurred";
const std::string   Bureaucrat::GradeTooHighException::_msg = Bureaucrat::GradeTooHighException::build_msg();
const std::string   Bureaucrat::GradeTooLowException::_msg = Bureaucrat::GradeTooLowException::build_msg();

/*
** ------------------------------- CONSTRUCTORS -------------------------------
*/

Bureaucrat::Bureaucrat() : _name(DEFAULT_NAME), _grade(GRADE_RANGE_MIN) {}

Bureaucrat::Bureaucrat(const std::string& name, const int grade) : _name(name), _grade(grade) {
    if (_grade < GRADE_RANGE_MAX)
        throw GradeTooHighException();
    if (_grade > GRADE_RANGE_MIN)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {}
Bureaucrat::GradeTooLowException::GradeTooLowException() : GradeException()  {}

Bureaucrat::GradeTooHighException::GradeTooHighException() : GradeException() {}

Bureaucrat::GradeGenericException::GradeGenericException() :_msg(DEFAULT_MESSAGE) {}
Bureaucrat::GradeGenericException::GradeGenericException(const std::string &msg) : _msg(msg) {}

/*
** ------------------------------- DESTRUCTORS ---------------------------------
*/

Bureaucrat::~Bureaucrat() {}
Bureaucrat::GradeGenericException::~GradeGenericException() throw() {}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Bureaucrat::incrementGrade(const int inc) {

    if (inc <= 0)
        throw GradeGenericException(FT_RED "incrementGrade expects positive inc" FT_RST); // NOLINT(*-err60-cpp)

    if (inc > _grade - GRADE_RANGE_MAX)
        throw GradeTooHighException();
    _grade -= inc;
}

void  Bureaucrat::incrementGrade()
{
    incrementGrade(1);
}

void Bureaucrat::decrementGrade(const int dec)
{
    if (dec <= 0)
        throw GradeGenericException(FT_RED "decrementGrade expects positive dec" FT_RST); // NOLINT(*-err60-cpp)

    if (dec > GRADE_RANGE_MIN - _grade)
        throw GradeTooLowException();
    _grade += dec;}

void Bureaucrat::decrementGrade()
{
    decrementGrade(1);
}

std::string Bureaucrat::getName() const {
    return _name;
}

int Bureaucrat::getGrade() const {
    return _grade;
}

void Bureaucrat::signForm(AForm &form) {
    try {
        form.beSigned(*this);
        std::cout << _name
                  << " (grade " << _grade << ") signed the form "
                  << form.getName()
                  << " (SIGN grade " << form.getGradeToSign()
                  << ", execute grade "
                  << form.getGradeToExecute()
                  << ")"
                  << std::endl;
    } catch(AForm::GradeException& e) {
        std::cout << _name
                  << " (grade " << _grade << ") couldn't SIGN the form "
                  << form.getName()
                  << " (SIGN grade " << form.getGradeToSign()
                  << ", execute grade "
                  << form.getGradeToExecute()
                  << ") because ->"
                  << std::endl;
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(const AForm &form) const {
    try
    {
        form.execute(*this);
    }
    catch(const std::exception& e)
    {
        std::cout << _name
                  << " (grade " << _grade << ") couldn't execute form "
                  << form.getName()
                  << " (sign grade " << form.getGradeToSign()
                  << ", execute grade " << form.getGradeToExecute()
                  << ") with reason: \n";
        std::cout << "Exception: " << e.what() <<  std::endl;
    }
}

/*
** -------------------------------- OPERATORS ---------------------------------
*/

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
    if (this != &other) {
        _name = other._name;
        _grade = other._grade;
    }
    return *this;
}

/*
** -------------------------------- OVERLOADS ---------------------------------
*/

std::ostream& operator<<(std::ostream& oss, const Bureaucrat& bureaucrat)
{
    oss << bureaucrat.getName();
    oss << ", bureaucrat grade ";
    oss << bureaucrat.getGrade();
    oss << ".\n";
    return oss;
}

/*
** -------------------------------- ACCESSORS ---------------------------------
*/

/*
** -------------------------------- EXCEPTIONS --------------------------------
*/

const char *Bureaucrat::GradeException::what() const throw() {
    return msg();
}

const char *Bureaucrat::GradeGenericException::msg() const throw() {
    return _msg.c_str();
}

Bureaucrat::GradeGenericException::GradeGenericException(const Bureaucrat::GradeGenericException &other) : _msg(other._msg) {}

Bureaucrat::GradeGenericException &
Bureaucrat::GradeGenericException::operator=(const Bureaucrat::GradeGenericException &other) {
    if (this != &other) {
        _msg = other._msg;
    }
    return *this;
}


const char *Bureaucrat::GradeTooLowException::msg() const throw() {
    return _msg.c_str();
}

const char *Bureaucrat::GradeTooHighException::msg() const throw() {
    return _msg.c_str();
}

/*
** ---------------------------------- OTHER -----------------------------------
*/

std::string Bureaucrat::GradeTooLowException::build_msg() {
    std::ostringstream oss;
    oss << FT_RED
        << "The grade is too low. Valid range is ["
        << Bureaucrat::GRADE_RANGE_MAX
        << ".."
        << Bureaucrat::GRADE_RANGE_MIN
        << "]."
        << FT_RST;
    return oss.str();
}

std::string Bureaucrat::GradeTooHighException::build_msg()
{
    std::ostringstream oss;
    oss << FT_RED
        << "The grade is too high. Valid range is ["
        << Bureaucrat::GRADE_RANGE_MAX
        << ".."
        << Bureaucrat::GRADE_RANGE_MIN
        << "]."
        << FT_RST;
    return oss.str();
}
