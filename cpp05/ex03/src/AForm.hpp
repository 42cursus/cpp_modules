/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
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

class AForm
{
public:
    struct RequiredGrades {
        int SIGN;
        int EXEC;
    };

    enum Command { PPF, RRF, SCF, NOT_FOUND };

    struct CommandMap
    {
        const int	size;
        const struct CommandMapEntry
        {
            const std::string	key;
            const Command		value;
        }					map[3];
    };
    static const CommandMap	_commandMap;

    AForm(const std::string& name, int gradeToSign, int gradeToExecute);
    AForm(const AForm& other);

    AForm(const int gradeToExecute, const int gradeToSign);

    AForm& operator=(const AForm& other);
    virtual ~AForm();

    const std::string &getName() const;

    void beSigned(const Bureaucrat& bureaucrat);
    virtual void	execute(Bureaucrat const &bureaucrat) const = 0;
    static AForm*	makeForm(std::string form_name, std::string target_name);

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

    class FormIsNotSignedException : public std::exception
    {
    public:
        const char* what() const throw();
    };

private:
    // NOLINTBEGIN(*-avoid-const-or-ref-data-members); explicit design choice
    const std::string   _name;
    const int           _gradeToSign;
    const int           _gradeToExecute;
    bool                _isSigned;
    static const std::string &DEFAULT_NAME;
    // NOLINTEND(*-avoid-const-or-ref-data-members); explicit design choice
    static Command getCommand(const std::string &input);
};

std::ostream& operator<<(std::ostream& oss, const AForm& other);

#endif //FORM_HPP
