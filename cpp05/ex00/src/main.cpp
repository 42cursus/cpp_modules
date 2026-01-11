/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 21:16:15 by abelov            #+#    #+#             */
/*   Updated: 2025/07/25 21:16:16 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int main(){
    try {
        Bureaucrat Bobby("Bobby", 30);
        Bureaucrat Mandy("Mandy", 1);
        Bureaucrat Tonny("Tonny", 150);

        try {
            Bureaucrat Victoria("Victoria", 0);
        } catch (Bureaucrat::GradeTooHighException &tooHight) {
            std::cout << "Error: " << tooHight.what() << std::endl;
        } catch (Bureaucrat::GradeTooLowException &tooLow) {
            std::cout << "Error: " << tooLow.what() << std::endl;
        }

        try {
            Bureaucrat Leon("Leon", 151);
        } catch (Bureaucrat::GradeException &ex) {
            std::cout << "Error: " << ex.what() << std::endl;
        }

        std::cout << std::endl;
        std::cout << FT_UND "Bureaucrats:" FT_RST << std::endl;
        std::cout << Bobby;
        std::cout << Mandy;
        std::cout << Tonny;
        std::cout << std::endl;

        std::cout << FT_UND "Decrementing Grades\n" FT_RST << std::endl;
        std::cout << "Demoting Bobby's grade by 4:" << std::endl;
        try {
            Bobby.decrementGrade(4);
        } catch (Bureaucrat::GradeTooLowException &ex) {
            std::cout << "Error: " << ex.what() << std::endl;
        }
        std::cout << Bobby << std::endl;

        std::cout << "Demoting Mandy's grade by 3:" << std::endl;
        try {
            Mandy.decrementGrade(3);
        } catch (Bureaucrat::GradeTooLowException &ex) {
            std::cout << "Error: " << ex.what() << std::endl;
        }
        std::cout << Mandy << std::endl;

        std::cout << "Demoting Tonny's grade by 14:" << std::endl;
        try {
            Tonny.decrementGrade(14);
        } catch (Bureaucrat::GradeTooLowException &ex) {
            std::cout << "Error: " << ex.what() << std::endl;
        }
        std::cout << Tonny << std::endl;

        std::cout << FT_UND "\nIncrementting Grades\n" FT_RST << std::endl;
        std::cout << "Promoting Bobby's grade by 14:" << std::endl;
        try {
            Bobby.incrementGrade(14);
        } catch (Bureaucrat::GradeTooHighException &ex) {
            std::cout << "Error: " << ex.what() << std::endl;
        }
        std::cout << Bobby << std::endl;

        std::cout << "Promoting Mandy's grade by 4:" << std::endl;
        try {
            Mandy.incrementGrade(4);
        } catch (Bureaucrat::GradeTooHighException &ex) {
            std::cout << "Error: " << ex.what() << std::endl;
        }

        std::cout << Mandy << std::endl;
        std::cout << "Promoting Tonny's grade by 20:" << std::endl;
        try {
            Tonny.incrementGrade(20);
        } catch (Bureaucrat::GradeTooHighException &ex) {
            std::cout << "Error: " << ex.what() << std::endl;
        }
        std::cout << Tonny << std::endl;

    } catch (Bureaucrat::GradeException &ex) {
        std::cout << "Error: " << ex.what() << std::endl;
    }
    return 0;
};
