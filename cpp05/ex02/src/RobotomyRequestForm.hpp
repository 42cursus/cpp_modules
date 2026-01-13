/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 21:28:47 by abelov            #+#    #+#             */
/*   Updated: 2025/07/25 21:28:48 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
    static const AForm::RequiredGrades REQUIRED_GRADES;
    std::string	_target;
public:
    RobotomyRequestForm(const RobotomyRequestForm& other);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
    explicit RobotomyRequestForm(const std::string& target);

    virtual ~RobotomyRequestForm(){};

    void	execute(Bureaucrat const &bureaucrat) const;
};


#endif //ROBOTOMYREQUESTFORM_HPP
