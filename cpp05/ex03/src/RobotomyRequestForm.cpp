/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 21:28:51 by abelov            #+#    #+#             */
/*   Updated: 2025/07/25 21:28:52 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/*
** -------------------------------- STATIC VARS -------------------------------
*/

const AForm::RequiredGrades RobotomyRequestForm::REQUIRED_GRADES = {
        .SIGN = 72,
        .EXEC = 45
};

/*
** ------------------------------- CONSTRUCTORS -------------------------------
*/

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
        : AForm("RobotomyRequestForm", REQUIRED_GRADES.SIGN, REQUIRED_GRADES.EXEC)
        , _target(target) {}

/*
** ------------------------------- DESTRUCTORS --------------------------------
*/


/*
** -------------------------------- OPERATORS ---------------------------------
*/

/*
** -------------------------------- OVERLOADS ---------------------------------
*/

/*
** --------------------------------- METHODS ----------------------------------
*/

void	RobotomyRequestForm::execute(Bureaucrat const &bureaucrat) const
{
    if (!isSigned())
        throw RobotomyRequestForm::FormIsNotSignedException();
    if (bureaucrat.getGrade() > getGradeToExecute())
    {
        std::cout << _target << ": robotomy failed" << std::endl;
        throw RobotomyRequestForm::GradeTooLowException();
    }

    if (bureaucrat.getGrade() <= getGradeToExecute())
    {
        std::cout << "MAKING NOISES!!!!" << std::endl;
        std::cout << _target << " has been robotomized successfully 50% of the time" << std::endl;
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

