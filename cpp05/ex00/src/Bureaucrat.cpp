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

/*
** -------------------------------- STATIC VARS -------------------------------
*/

const int           Bureaucrat::GRADE_RANGE_MAX = 1;
const int           Bureaucrat::GRADE_RANGE_MIN = 150;
const               std::string& Bureaucrat::DEFAULT_NAME = "default";

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

Bureaucrat::GradeTooHighException::GradeTooHighException() : GradeException() {}
Bureaucrat::GradeTooLowException::GradeTooLowException() : GradeException()  {}
/*
** --------------------------------- METHODS ----------------------------------
*/

void Bureaucrat::incrementGrade(const int inc) {

    int target = _grade - inc;
    if (target <= GRADE_RANGE_MAX)
        throw GradeTooHighException();
    _grade = target;
}

void  Bureaucrat::incrementGrade()
{
    incrementGrade(1);
}

void Bureaucrat::decrementGrade(const int dec)
{
    int target = _grade + dec;
    if (target >= GRADE_RANGE_MIN)
        throw GradeTooLowException();
    _grade = target;
}

void Bureaucrat::decrementGrade()
{
    decrementGrade(1);
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
    if (this != &other) {
        _name = other._name;
        _grade = other._grade;
    }
    return *this;
}

/*
** ------------------------------- DESTRUCTORS ---------------------------------
*/

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const {
    return _name;
}

int Bureaucrat::getGrade() const {
    return _grade;
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

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return _msg.c_str();
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
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
