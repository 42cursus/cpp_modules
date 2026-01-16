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

#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    try {

        std::cout << FT_BOLD "\n--------- Welcome to Time Variance Authority ----------\n"
                  << "\n                 Please Remain Calm.                   \n" FT_RST << std::endl;
        std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
                     "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⠤⠤⠒⠒⠒⠀⠂⠒⠒⠒⠤⠤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
                     "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠤⠚⠉⠀⠀⠐⡆⠀⠀⠀⣾⠇⠀⠀⢀⡄⠀⠉⠓⢦⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
                     "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡠⠚⠁⠀⠀⠀⠀⠀⠀⠃⠀⠀⢸⣿⠀⠀⠀⠞⠀⠀⠀⠀⠀⠉⠳⡦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
                     "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠊⠀⠀⠱⠄⠀⡄⢀⠆⠀⠀⠀⠀⠘⠃⠀⠀⠀⠀⡀⠀⠀⠀⠀⢀⡀⠘⢌⢦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
                     "⠀⠀⠀⠀⠀⢠⠖⡄⠀⠀⠀⠀⠀⠀⠀⡔⠁⠀⠀⠀⠀⠀⡧⠓⠘⠢⡃⠀⠀⠀⠀⠀⠀⠀⠐⡤⠧⠼⣰⠀⠘⠉⠀⠀⠈⢢⠱⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
                     "⠀⠀⠀⠀⠀⠸⡀⢣⠀⠀⠀⠀⠀⠀⡜⠀⠀⠀⠀⠀⢠⠎⠀⠀⠀⠀⢱⠀⠀⠀⠀⠀⠀⢀⠎⠀⠀⠀⠈⢣⠀⠀⠀⠀⠀⠀⢇⠱⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
                     "⠀⠀⠀⠀⢠⠮⡉⢺⠤⡀⠀⠀⠀⡜⠀⠐⠲⠄⠀⠀⡎⠀⠀⣴⣶⡆⢸⠀⠀⠀⠀⠀⠀⡎⠀⢀⣤⣀⠀⠘⡄⠀⠀⠀⠀⠀⠘⡄⢱⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
                     "⠀⠀⠀⠀⢧⢴⡈⡾⣄⡸⠀⠀⢠⠁⠀⠀⠀⠀⠀⢸⠀⠀⢸⣿⣿⣿⢸⠀⠀⠀⠀⠀⢸⠀⢀⣾⣿⣣⡆⠀⡇⠀⠀⠊⠉⠁⠀⡇⠈⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
                     "⠀⠀⠀⠀⠘⣄⠀⢀⡰⠁⠀⠀⢸⠀⢶⣶⣶⣶⣦⢸⠀⠀⢸⣿⣿⣿⢸⠀⢠⣴⡄⠀⢸⠀⢸⣿⣿⣿⡇⢠⠁⠀⠀⠀⠀⠀⠀⡇⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
                     "⠀⠀⠀⠀⠀⢸⠿⠿⡇⠀⡠⠔⠂⠀⠀⠀⠀⠀⠀⠀⠑⠒⠸⠿⠿⠗⠃⠀⠈⠛⠁⠀⠸⣀⣸⣿⣿⣿⡠⠊⠘⠛⠿⠿⠿⠇⠀⡇⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
                     "⠀⠀⠀⠀⠀⢸⣉⣉⡷⠋⠀⠀⢸⠀⢀⠤⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⠁⠀⣧⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
                     "⠀⠀⠀⠀⠀⠘⡀⠘⠀⣠⠒⠂⠸⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⣀⣀⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠲⠤⠀⠀⡎⠀⢰⠀⠉⠢⣄⠀⠀⠀⠀⠀⠀⠀\n"
                     "⠀⠀⠀⠀⠀⠀⠑⠒⠊⠀⠀⠀⠀⢣⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠲⢖⣒⣒⣒⣒⣚⠟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡜⠀⢀⠗⠒⣤⠀⠀⠳⡀⠀⠀⠀⠀⠀\n"
                     "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢧⠀⠀⠀⣠⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠎⠀⣀⣮⣴⡊⢣⢑⡤⠜⠀⠀⠀⠀⠀⠀\n"
                     "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢷⡀⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠳⡀⠀⠀⡴⠃⡠⠋⠀⠈⡿⠟⠊⠁⠀⠀⠀⠀⠀⠀⠀⠀\n"
                     "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠫⡢⣀⠀⠀⠀⠀⢀⠆⠀⠀⢸⣿⠀⠀⠀⡄⠀⠀⠀⠀⠀⠀⢀⠴⠋⠀⡜⠁⠀⣀⠼⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
                     "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠪⣑⠤⣀⠀⠊⠀⠀⠀⢸⡟⠀⠀⠀⠹⠀⠀⠀⣀⠤⠊⠁⠀⣠⠔⠱⢄⣢⣘⠽⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
                     "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠑⠢⣉⡓⠒⠤⠤⠤⠤⠤⠤⠤⠤⠒⠊⠉⠀⣀⡠⠔⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
                     "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢹⣷⠢⠤⠤⠤⠤⢴⡦⠤⠒⠒⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
                     "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⡆⠀⠀⠀⠀⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
                     "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⣷⠀⠀⠀⠀⢸⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
                     "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⡇⠀⠀⠀⢸⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
                     "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡸⠿⠒⡄⢀⠼⠿⢄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
                     "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠤⠧⠔⠀⢱⡸⠤⠤⢾⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
                     "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⣁⣀⣀⣀⣤⠬⣇⣀⣀⣀⣘⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
                     "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⠒⠒⠒⠊⠁⠀⠓⠂⠐⠐⠒⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
                  << std::endl;

        try {
            std::cout << "Trying to instantiate Bureaucrat 'Analyst 1182-E' with grade '0'" << std::endl;
            Bureaucrat Analyst1("Analyst 1182-E", 0);
        } catch (Bureaucrat::GradeTooHighException &tooHight) {
            std::cout << "Error: " << tooHight.what() << std::endl;
        } catch (Bureaucrat::GradeTooLowException &tooLow) {
            std::cout << "Error: " << tooLow.what() << std::endl;
        }

        try {
            std::cout << "Trying to instantiate Bureaucrat 'Hunter M-34' with grade '151'" << std::endl;
            Bureaucrat Hunter1("Hunter M-34", 151);
        } catch (Bureaucrat::GradeException &ex) {
            std::cout << "Error: " << ex.what() << std::endl;
        }

        Bureaucrat Ralph("Ralph", 42);
        Bureaucrat Casey("Casey", 1);
        Bureaucrat Ouroboros("Ouroboros", 149);

        std::cout << std::endl;
        std::cout << FT_BOLD "Bureaucrats:" FT_RST << std::endl;
        std::cout << Ralph;
        std::cout << Casey;
        std::cout << Ouroboros;
        std::cout << std::endl;

        std::cout << FT_BOLD "Decrementing Grades\n" FT_RST << std::endl;
        std::cout << "Demoting Ralph's grade by 4:" << std::endl;
        try {
            Ralph.decrementGrade(4);
        } catch (Bureaucrat::GradeTooLowException &ex) {
            std::cout << "Error: " << ex.what() << std::endl;
        }
        std::cout << Ralph << std::endl;

        std::cout << "Demoting Casey's grade by 3:" << std::endl;
        try {
            Casey.decrementGrade(3);
        } catch (Bureaucrat::GradeTooLowException &ex) {
            std::cout << "Error: " << ex.what() << std::endl;
        }
        std::cout << Casey << std::endl;

        std::cout << "Demoting Ouroboros's grade by 14:" << std::endl;
        try {
            Ouroboros.decrementGrade(14);
        } catch (Bureaucrat::GradeTooLowException &ex) {
            std::cout << "Error: " << ex.what() << std::endl;
        }
        std::cout << Ouroboros << std::endl;

        std::cout << FT_BOLD "\nIncrementting Grades\n" FT_RST << std::endl;
        std::cout << "Promoting Ralph's grade by 14:" << std::endl;
        try {
            Ralph.incrementGrade(14);
        } catch (Bureaucrat::GradeTooHighException &ex) {
            std::cout << "Error: " << ex.what() << std::endl;
        }
        std::cout << Ralph << std::endl;

        std::cout << "Promoting Casey's grade by -1:" << std::endl;
        try {
            Casey.incrementGrade(-1);
        } catch (Bureaucrat::GradeException &ex) {
            std::cout << "Error: " << ex.what() << std::endl;
        }

        std::cout << "Promoting Casey's grade by 4:" << std::endl;
        try {
            Casey.incrementGrade();
            Casey.incrementGrade();
            Casey.incrementGrade();
            Casey.incrementGrade();
        } catch (Bureaucrat::GradeTooHighException &ex) {
            std::cout << "Error: " << ex.what() << std::endl;
        }

        std::cout << Casey << std::endl;
        std::cout << "Promoting Ouroboros's grade by 20:" << std::endl;
        try {
            Ouroboros.incrementGrade(20);
        } catch (Bureaucrat::GradeTooHighException &ex) {
            std::cout << "Error: " << ex.what() << std::endl;
        }
        std::cout << Ouroboros << std::endl;

    } catch (Bureaucrat::GradeException &ex) {
        std::cout << "Error: " << ex.what() << std::endl;
    }
    return 0;
}
