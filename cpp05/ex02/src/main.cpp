/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 01:28:17 by abelov            #+#    #+#             */
/*   Updated: 2026/01/13 01:28:18 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        std::cout << FT_BOLD "\n--------- Welcome to Time Variance Authority ----------\n" FT_RST << std::endl;

        std::cout << "⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⣿⠟⣿⣿⣿⣿⣿⣿⣿⣿⣿⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⡀⠀⢰⣿⣿⣿⣿⣿⣿⣿⣿⡿⠁⠀⠀⣼⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
                     "⠀⠀⠀⠀⢸⣿⣿⣿⣿⡿⠋⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡄⣿⣿⣿⣿⣿⣿⣿⣿⡟⠀⠀⠀⣼⣿⣿⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
                     "⠀⠀⠀⠀⢸⣿⣿⣿⡟⠁⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣎⢿⣿⣿⣿⣿⣿⡟⠀⠀⠀⣼⣿⣿⣿⣿⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
                     "⠀⠀⠀⠀⢸⣿⣿⠏⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣮⢿⣿⣿⣿⡟⠀⠀⠀⣼⣿⣿⣿⣿⣿⣿⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
                     "⠀⠀⠀⠀⢸⡿⠁⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⣻⣿⠏⠀⠀⠀⣼⣿⣿⣿⣿⣿⣿⣿⣿⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
                     "⠀⠀⠀⠀⠘⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⠉⠀⠀⠀⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
                     "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠏⠀⠀⢀⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
                     "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠏⠀⠀⢀⣎⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
                     "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⢻⣿⣿⣿⣿⣿⣿⣿⣿⠏⠀⠀⢀⣾⣿⣧⡻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
                     "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠈⢿⣿⣿⣿⣿⣿⣿⠏⠀⠀⢀⣾⣿⣿⣿⣷⡹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
                     "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢿⣿⣿⣿⣿⠏⠀⠀⢀⣾⣿⣿⣿⣿⣿⣿⣜⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣆⠀⠀⠀⠀⠀⠀⠀⠀\n"
                     "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢿⣿⣿⠏⠀⠀⢀⣾⣿⣿⣿⣿⣿⣿⣿⣿⡎⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣆⠀⠀⠀⠀⠀⠀⠀\n"
                     "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢿⠏⠀⠀⢀⣾⣿⣿⣿⣿⣿⣿⣿⣿⡿⠁⠀⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣆⠀⠀⠀⠀⠀⠀\n"
                     "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠉⠉⠉⠉⠉⠉⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠀⠀⠀⠈⠉⠉⠉⠉⠉⠉⠉⠉⠉⠁⠀⠀⠀⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠀⠀⠀⠀⠀⠀"
                  << FT_BOLD "\n                 FOR ALL TIME, ALWAYS.                   \n" FT_RST
                  << std::endl;

        Bureaucrat Potts("Mrs. Potts", 30);
        Bureaucrat Wanda("Wanda", 70);
        Bureaucrat TonyStark("TonyStark", 150);
        Bureaucrat HWR("He Who Remains", 1);
        RobotomyRequestForm Repeat("Wanda");
        ShrubberyCreationForm Tree("Wanda");
        RobotomyRequestForm Repeat2("TonyStark");
        PresidentialPardonForm Sorry("Potts");

        std::cout << FT_RST << FT_UND << "See below top level TVA agents:" << FT_RST << std::endl;
        std::cout << Potts;
        std::cout << TonyStark;
        std::cout << Wanda << std::endl;
        std::cout << FT_UND << "The He Who Remains:" << FT_RST
                  << HWR
                  << std::endl;
        std::cout << FT_UND << "The available forms:" << FT_RST << std::endl;
        std::cout << Repeat << std::endl;
        std::cout << Repeat2 << std::endl;
        std::cout << Tree << std::endl;
        std::cout << Sorry << std::endl;

        std::cout << FT_BOLD << "A normal day at TVA...\n"
                  << FT_RST << std::endl;

        std::cout << "Potts wants to Robotomize Wanda. They're too slow." << std::endl;
        try {
            Potts.signForm(Repeat);
        } catch (const AForm::GradeException& ex) {
            std::cout << FT_BOLD_B << Potts.getName() << FT_RST
                      << " couldn't SIGN the form "
                      << FT_BOLD_B << Repeat.getName() << FT_RST
                      << " because " << ex.what() << std::endl;
        }

        if (Repeat.isSigned())
            std::cout << Repeat.getName()
                      << " is now "
                      << FT_BOLD_G << "signed" << FT_RST
                      << std::endl;
        try {
            Potts.executeForm(Repeat);
            std::cout << std::endl;
        } catch (const AForm::GradeTooLowException& ex) {
            std::cout << FT_BOLD_B << Potts.getName() << FT_RST
                      << " couldn't execute the form "
                      << FT_BOLD_B << Repeat.getName() << FT_RST
                      << " because "
                      << ex.what()
                      << std::endl;
        }

        std::cout << "Then Wanda signed the Shrubbery Form and executed it as a Robot." << std::endl;
        try {
            Wanda.signForm(Tree);
        } catch (const AForm::GradeTooLowException& ex) {
            std::cout << FT_BOLD_B << Wanda.getName() << FT_RST
                      << " couldn't SIGN the form "
                      << FT_BOLD_B << Tree.getName() << FT_RST
                      << " because " << ex.what()
                      << std::endl;
        }
        if (Tree.isSigned()) {
            std::cout << Tree.getName()
                      << " is now "
                      << FT_BOLD_G << "signed" << FT_RST
                      << std::endl;
        }
        try {
            Wanda.executeForm(Tree);
            std::cout << std::endl;
        } catch (const AForm::GradeTooLowException& ex) {
            std::cout << FT_BOLD_B << Wanda.getName() << FT_RST
                      << " couldn't execute the form "
                      << FT_BOLD_B << Tree.getName() << FT_RST
                      << " because "
                      << ex.what()
                      << std::endl;
        }

        std::cout << "Wanda wants to optimise TonyStark using the RobotomizeRequestForm" << std::endl;
        try {
            Wanda.signForm(Repeat2);
        } catch (const AForm::GradeTooLowException& ex) {
            std::cout << FT_BOLD_B << Wanda.getName() << FT_RST
                      << " couldn't SIGN the form "
                      << FT_BOLD_B << Repeat2.getName() << FT_RST
                      << " because "
                      << ex.what() << std::endl;
        }

        if (Repeat2.isSigned())
            std::cout << Repeat2.getName() << " is now "
                      << FT_BOLD_G << "signed" << FT_RST
                      << std::endl;
        try {
            Wanda.executeForm(Repeat2);
            std::cout << std::endl;
        } catch (const AForm::GradeException& ex) {
            std::cout << FT_BOLD_B << Wanda.getName() << FT_RST
                      << " couldn't execute the form "
                      << FT_BOLD_B << Repeat2.getName() << FT_RST
                      << " because "
                      << ex.what()
                      << std::endl;
        }

        std::cout << "\nPotts noticed an error in her form and tried to SIGN the Pardon Form for her mistake." << std::endl;
        try {
            Potts.signForm(Sorry);
            std::cout << std::endl;
        } catch (const AForm::GradeException& ex) {
            std::cout << FT_BOLD_B << Potts.getName() << FT_RST
                      << " couldn't SIGN the form "
                      << FT_BOLD_B << Sorry.getName() << FT_RST
                      << " because " << ex.what()
                      << std::endl;
        }
        std::cout << "\nThe HWR decided to use their Presidential Pardon." << std::endl;
        try {
            HWR.signForm(Sorry);
        } catch (const AForm::GradeException& ex) {
            std::cout << FT_BOLD_B << HWR.getName() << FT_RST
                      << " couldn't SIGN the form "
                      << FT_BOLD_B << Sorry.getName() << FT_RST
                      << " because " << ex.what() << std::endl;
        }

        if (Sorry.isSigned())
            std::cout << Sorry.getName() << " is now "
                      << FT_BOLD_G << "signed" << FT_RST
                      << std::endl;
        try {
            HWR.executeForm(Sorry);
        } catch (const AForm::GradeTooLowException& ex) {
            std::cout << FT_BOLD_B << HWR.getName() << FT_RST
                      << " couldn't execute the form "
                      << FT_BOLD_B << Sorry.getName() << FT_RST
                      << " because "
                      << ex.what()
                      << std::endl;
        }

        std::cout << "\nAnd it is another end of day full of adventures at TVA...\n" << std::endl;

    } catch (const Bureaucrat::GradeException& ex) {
        std::cout << "Error: " << ex.what() << std::endl;
    } catch (const AForm::GradeException& ex) {
        std::cout << "Error: " << ex.what() << std::endl;
    }

    return 0;
}
