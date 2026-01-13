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
        Bureaucrat Poppy("Poppy", 42);
        Bureaucrat Vendy("Vendy", 1);
        Bureaucrat Ronnie("Ronnie", 149);

        try {
            Bureaucrat Lika("Lika", 0);
        } catch (Bureaucrat::GradeTooHighException &tooHight) {
            std::cout << "Error: " << tooHight.what() << std::endl;
        } catch (Bureaucrat::GradeTooLowException &tooLow) {
            std::cout << "Error: " << tooLow.what() << std::endl;
        }

        try {
            Bureaucrat Theon("Theon", 151);
        } catch (Bureaucrat::GradeException &ex) {
            std::cout << "Error: " << ex.what() << std::endl;
        }

        std::cout << std::endl;
        std::cout << FT_BOLD "Bureaucrats:" FT_RST << std::endl;
        std::cout << Poppy;
        std::cout << Vendy;
        std::cout << Ronnie;
        std::cout << std::endl;

        std::cout << FT_BOLD "Decrementing Grades\n" FT_RST << std::endl;
        std::cout << "Demoting Poppy's grade by 4:" << std::endl;
        try {
            Poppy.decrementGrade(4);
        } catch (Bureaucrat::GradeTooLowException &ex) {
            std::cout << "Error: " << ex.what() << std::endl;
        }
        std::cout << Poppy << std::endl;

        std::cout << "Demoting Vendy's grade by 3:" << std::endl;
        try {
            Vendy.decrementGrade(3);
        } catch (Bureaucrat::GradeTooLowException &ex) {
            std::cout << "Error: " << ex.what() << std::endl;
        }
        std::cout << Vendy << std::endl;

        std::cout << "Demoting Ronnie's grade by 14:" << std::endl;
        try {
            Ronnie.decrementGrade(14);
        } catch (Bureaucrat::GradeTooLowException &ex) {
            std::cout << "Error: " << ex.what() << std::endl;
        }
        std::cout << Ronnie << std::endl;

        std::cout << FT_BOLD "\nIncrementting Grades\n" FT_RST << std::endl;
        std::cout << "Promoting Poppy's grade by 14:" << std::endl;
        try {
            Poppy.incrementGrade(14);
        } catch (Bureaucrat::GradeTooHighException &ex) {
            std::cout << "Error: " << ex.what() << std::endl;
        }
        std::cout << Poppy << std::endl;

        std::cout << "Promoting Vendy's grade by -1:" << std::endl;
        try {
            Vendy.incrementGrade(-1);
        } catch (Bureaucrat::GradeException &ex) {
            std::cout << "Error: " << ex.what() << std::endl;
        }

        std::cout << "Promoting Vendy's grade by 4:" << std::endl;
        try {
            Vendy.incrementGrade();
            Vendy.incrementGrade();
            Vendy.incrementGrade();
            Vendy.incrementGrade();
        } catch (Bureaucrat::GradeTooHighException &ex) {
            std::cout << "Error: " << ex.what() << std::endl;
        }

        std::cout << Vendy << std::endl;
        std::cout << "Promoting Ronnie's grade by 20:" << std::endl;
        try {
            Ronnie.incrementGrade(20);
        } catch (Bureaucrat::GradeTooHighException &ex) {
            std::cout << "Error: " << ex.what() << std::endl;
        }
        std::cout << Ronnie << std::endl;

    } catch (Bureaucrat::GradeException &ex) {
        std::cout << "Error: " << ex.what() << std::endl;
    }
    return 0;
}
