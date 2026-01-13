/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 21:28:58 by abelov            #+#    #+#             */
/*   Updated: 2025/07/25 21:28:58 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include "ShrubberyCreationForm.hpp"

/*
** -------------------------------- STATIC VARS -------------------------------
*/

const AForm::RequiredGrades ShrubberyCreationForm::REQUIRED_GRADES = {
        .SIGN = 145,
        .EXEC = 137
};

/*
** ------------------------------- CONSTRUCTORS -------------------------------
*/

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", REQUIRED_GRADES.SIGN, REQUIRED_GRADES.EXEC)
    , _target(target) {}


ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other) {
    *this = other;
}
/*
** ------------------------------- DESTRUCTORS --------------------------------
*/


/*
** -------------------------------- OPERATORS ---------------------------------
*/

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

/*
** -------------------------------- OVERLOADS ---------------------------------
*/

/*
** --------------------------------- METHODS ----------------------------------
*/

void ShrubberyCreationForm::execute(const Bureaucrat &bureaucrat) const {
    if (!isSigned())
        throw ShrubberyCreationForm::FormIsNotSignedException();
    else if (bureaucrat.getGrade() > getGradeToExecute())
        throw ShrubberyCreationForm::GradeTooLowException();
    else if (bureaucrat.getGrade() <= getGradeToExecute())
    {
        std::ofstream	ofs((_target + "_shrubbery").c_str());
        if (!ofs.is_open())
        {
            std::cerr << "Error while creating the outfile" << std::endl;
            return ;
        }
        ofs << "   *    *  ()   *   *" << std::endl;
        ofs << "*        * /         *" << std::endl;
        ofs << "      *   /i\\    *  *" << std::endl;
        ofs << "    *     o/\\  *      *" << std::endl;
        ofs << " *       ///    *" << std::endl;
        ofs << "     *   /*/o\\  *    *" << std::endl;
        ofs << "   *    /i//      *" << std::endl;
        ofs << "        /o/*\\i   *" << std::endl;
        ofs << "  *    //i//o\\\\     *" << std::endl;
        ofs << "    * /*////\\\\i" << std::endl;
        ofs << " *    //o//i\\*\\   *" << std::endl;
        ofs << "   * /i///*/\\\\   *" << std::endl;
        ofs << "  *    *   ||     *" << std::endl;
        ofs.close();
        std::cout << "File " << _target << "_shrubbery is created with ASCII tree inside" << std::endl;
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


