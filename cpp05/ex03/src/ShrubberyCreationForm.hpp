/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 21:28:30 by abelov            #+#    #+#             */
/*   Updated: 2025/07/25 21:28:30 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
    static const AForm::RequiredGrades REQUIRED_GRADES;
    std::string	_target;
public:
    ShrubberyCreationForm(const ShrubberyCreationForm& other);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
    explicit ShrubberyCreationForm(const std::string& target);
    virtual ~ShrubberyCreationForm(){};
    void	execute(Bureaucrat const &bureaucrat) const;
};


#endif //SHRUBBERYCREATIONFORM_HPP
