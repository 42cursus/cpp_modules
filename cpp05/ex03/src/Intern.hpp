/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 21:31:16 by abelov            #+#    #+#             */
/*   Updated: 2026/01/13 15:54:31 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>

class AForm;

class Intern
{
public:
    Intern();
    ~Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);

    AForm*	makeForm(std::string form, const std::string& target);

    class FormNotFoundException : public std::exception {
    public:
        const char* what() const throw();
    };
};


#endif //INTERN_HPP
