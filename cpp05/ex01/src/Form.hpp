/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 21:25:44 by abelov            #+#    #+#             */
/*   Updated: 2025/07/25 21:25:45 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FORM_HPP
#define FORM_HPP

#include <stdbool.h>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
public:
    Form(const std::string& name, int gradeToSign, int gradeToExecute);
    Form(const Form& other);

    Form(const int gradeToExecute, const int gradeToSign);

    Form& operator=(const Form& other);
    ~Form();

    const std::string &getName() const;

    void beSigned(const Bureaucrat& bureaucrat);

    bool isSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    class GradeException : public std::exception {
    public:
        virtual const char* what() const throw() = 0;
    };

    class GradeTooHighException : public GradeException {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public GradeException {
    public:
        const char* what() const throw();
    };

private:
    const std::string   _name;
    const int           _gradeToSign;
    const int           _gradeToExecute;
    bool                _isSigned;
    static const std::string &DEFAULT_NAME;
};

std::ostream& operator<<(std::ostream& oss, const Form& other);

#endif //FORM_HPP
