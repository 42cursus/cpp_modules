/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 21:30:13 by abelov            #+#    #+#             */
/*   Updated: 2025/07/25 21:30:14 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <string>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm
{
private:
    static const AForm::RequiredGrades REQUIRED_GRADES;
    std::string	_target;
public:
    PresidentialPardonForm(const PresidentialPardonForm& other);
    explicit PresidentialPardonForm(const std::string& target);
    virtual ~PresidentialPardonForm();

    void    execute(Bureaucrat const &bureaucrat) const;

    PresidentialPardonForm& operator=(const PresidentialPardonForm& other);

};

std::ostream& operator<<(std::ostream& oss, const PresidentialPardonForm& other);

#endif //PRESIDENTIALPARDONFORM_HPP
