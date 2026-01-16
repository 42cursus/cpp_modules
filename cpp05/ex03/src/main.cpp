/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 21:31:00 by abelov            #+#    #+#             */
/*   Updated: 2026/01/13 15:54:35 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"

int main() {
    try {

        std::cout << FT_BOLD "\n--------- Welcome to Time Variance Authority ----------\n" FT_RST << std::endl;

        std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡀⠠⠤⠀⠀⠀⠤⠤⢄⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
                     "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡀⠔⠈⠁⠀⠀⠀⠀⣤⠀⠀⠀⠀⠀⠉⠓⢆⢄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
                     "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡠⠊⠀⠀⠀⠘⡀⠀⠀⠀⠾⠀⡿⠀⡐⠀⠀⠀⠀⠈⠪⡢⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
                     "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⠊⠀⠠⡀⠀⠀⠀⠁⠀⠀⠀⠀⢰⡇⠀⠀⠀⠀⠀⡠⠂⠀⠈⢐⢄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
                     "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⠁⠀⠀⠀⠈⠀⡀⠤⠄⡀⠀⠀⠀⣸⠁⠀⡀⠤⠄⡈⠀⠀⠀⠀⠀⢂⢆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
                     "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠃⠀⣀⠀⠀⠀⠜⠀⢀⠀⠘⡄⠀⠀⡿⠀⠌⠀⢀⠀⠈⡄⠀⡀⠄⠀⠀⠆⠆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
                     "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡈⠀⠀⠀⠈⠀⠸⠀⢰⣟⣇⠀⢰⠀⢰⡇⢸⠀⢰⡿⣇⠀⢰⠀⠀⠀⠀⠀⠘⠒⡰⠉⡄⡠⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
                     "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀⢀⠀⠀⠀⢈⠀⢸⡯⣿⠀⢸⢀⣼⡀⢠⠀⢸⡿⣽⠀⢸⠀⠀⢀⠀⠀⠈⡣⡘⠅⠰⠃⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
                     "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠔⡇⠈⠉⠉⠁⠀⠸⠀⠈⠛⠃⠀⡘⠈⠫⡇⠸⠀⠈⠛⠃⠀⡘⠀⠈⠉⠉⠁⠣⠐⠇⠀⠀⠀⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
                     "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡠⠂⠁⢀⢠⠀⠀⠀⠀⠀⠀⠑⠂⠀⠀⠒⠁⠀⠀⢻⡀⠑⠂⠀⠀⠒⠁⠀⠀⠀⠀⠀⠸⠁⢄⡀⠀⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
                     "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⢀⠰⡪⣀⠈⡄⠀⠐⠂⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠃⠀⠀⠀⠀⠀⠀⠀⠈⠑⠂⠀⢆⠂⢌⢰⡄⢷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
                     "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠑⠜⡪⠉⠙⡄⠀⠀⠀⠀⡀⠀⠀⠈⠣⢥⣡⣡⡡⠥⠃⠀⠀⠀⠀⡀⠀⠀⠀⢀⢌⠊⠀⠀⠑⡬⠑⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
                     "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠣⡀⠀⠈⢄⠀⠠⠊⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠀⠀⠀⠈⠂⠀⠠⡢⠂⠀⠀⠀⠀⠀⠊⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
                     "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⣈⡠⠔⠁⠑⢄⠀⠀⠀⠀⠎⠀⠀⠀⢴⠀⠀⠀⠀⠆⠀⠀⠀⡠⡰⠊⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
                     "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠂⠄⡀⠀⠀⠀⠀⠹⠀⠀⠀⠀⢀⣠⠴⠚⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
                     "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣿⣒⠒⠒⠒⢲⣺⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
                     "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢳⣻⠀⠀⠀⣾⢽⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
                     "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣟⠀⠀⠀⣯⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
                     "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣽⡀⠀⠀⣯⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
                     "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠞⠚⠲⠀⡖⠋⢓⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
                     "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡔⠉⠈⠈⢀⢘⠀⡇⠀⠀⠁⠉⠢⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
                     "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠈⠈⠈⠈⠈⠈⠈⠈⠈⠈⠈⠈⠈⠈⠁⠁⠁⠉⠈⠁⠉⠈⠈⠈⠈⠈⠈⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
                  << FT_BOLD "\n                       HELLO, VARIANT!                   \n" FT_RST
                  << FT_BOLD "\n           LET'S WALK THROUGH WHAT YOU DID WRONG.                   \n" FT_RST
                  << std::endl;

        Bureaucrat Potts("Mrs. Potts", 30);
        Bureaucrat Wanda("Wanda", 70);
        Bureaucrat HWR("He Who Remains", 1);
        Intern RandomIntern1;

        std::cout << FT_BOLD << "\n--------- Welcome to TVA ----------\n\n"
                  << FT_RST << FT_UND << "See below our top level TVA agents:" << FT_RST << std::endl;
        std::cout << Potts;
        std::cout << Wanda << std::endl;
        std::cout << FT_UND << "The He Who Remains:" << FT_RST << std::endl;
        std::cout << HWR << std::endl;
        std::cout << "and some intern apparently..." << std::endl;
        std::cout << std::endl;
        AForm *Repeat = NULL;
        AForm *Repeat2 = NULL;
        AForm *Sorry = NULL;
        AForm *WhoCares = NULL;
        AForm *Tree = NULL;

        std::cout << FT_BOLD << "A normal day at TVA...\n" << FT_RST << std::endl;
        try {
            std::cout << "--6am--\nthe Intern making some form for the day:" << std::endl;
            Sorry = RandomIntern1.makeForm("presidential", "Potts");
            Repeat = RandomIntern1.makeForm("robotomy", "Wanda");
            Repeat2 = RandomIntern1.makeForm("robotomy", "Tonny");
            Tree = RandomIntern1.makeForm("shrubbery", "Wanda");

            try {
                WhoCares = RandomIntern1.makeForm("Make coffee", "All Bureaucrats");
            } catch (const Intern::FormNotFoundException &ex) {
                std::cout << "Error: Intern failed to create the form -- " << ex.what() << std::endl;
            }

            std::cout << "--6:30am--\nThe forms are now available thanks to ... what's his name again?...\n" << std::endl;
            std::cout << FT_UND "Available forms:\n" FT_RST;
            std::cout << *Repeat << std::endl;
            std::cout << *Tree << std::endl;
            std::cout << *Sorry << std::endl;

            std::cout << "--10am--\nBureaucrats arrive and start doing stuff\n" << std::endl;
            std::cout << "Potts wants to Robotomy Wanda. They're too slow." << std::endl;
            try {
                Potts.signForm(*Repeat);
            } catch (const AForm::GradeException& ex) {
                std::cout << FT_BOLD_B << Potts.getName() << FT_RST
                          << " couldn't sign the form "
                          << FT_BOLD_B << Repeat->getName() << FT_RST
                          << " because "
                          << ex.what()
                          << std::endl;
            }

            if (Repeat->isSigned()) {
                std::cout << Repeat->getName()
                          << " is now "
                          << FT_BOLD_G << "signed" << FT_RST
                          << std::endl;
            }

            try {
                Potts.executeForm(*Repeat);
                std::cout << std::endl;
            } catch (const AForm::GradeException& ex) {
                std::cout << FT_BOLD_B << Potts.getName() << FT_RST
                          << " couldn't execute the form "
                          << FT_BOLD_B << Repeat->getName() << FT_RST
                          << " because "
                          << ex.what()
                          << std::endl;
            }

            std::cout << "Then Wanda signed the Shrubbery Form and executed it as a Robot." << std::endl;
            try {
                Wanda.signForm(*Tree);
            } catch (const AForm::GradeException& ex) {
                std::cout << FT_BOLD_B << Wanda.getName() << FT_RST
                          << " couldn't sign the form "
                          << FT_BOLD_B << Tree->getName() << FT_RST
                          << " because "
                          << ex.what()
                          << std::endl;
            }
            if (Tree->isSigned())
                std::cout << Tree->getName()
                          << " is now "
                          << FT_BOLD_G << "signed" << FT_RST
                          << std::endl;
            try {
                Wanda.executeForm(*Tree);
                std::cout << std::endl;
            } catch (const AForm::GradeException& ex) {
                std::cout << FT_BOLD_B << Wanda.getName() << FT_RST
                          << " couldn't execute the form "
                          << FT_BOLD_B << Tree->getName() << FT_RST
                          << " because "
                          << ex.what()
                          << std::endl;
            }

            std::cout << "Wanda wants to optimise Tonny using the RobotomizeRequestForm" << std::endl;
            try {
                Wanda.signForm(*Repeat2);
            } catch (const AForm::GradeException& ex) {
                std::cout << FT_BOLD_B << Wanda.getName() << FT_RST
                          << " couldn't sign the form "
                          << FT_BOLD_B << Repeat2->getName() << FT_RST
                          << " because "
                          << ex.what()
                          << std::endl;
            }

            if (Repeat2->isSigned())
                std::cout << Repeat2->getName()
                          << " is now "
                          << FT_BOLD_G << "signed" << FT_RST
                          << std::endl;
            try {
                Wanda.executeForm(*Repeat2);
                std::cout << std::endl;
            } catch (const AForm::GradeException& ex) {
                std::cout << FT_BOLD_B << Wanda.getName() << FT_RST
                          << " couldn't execute the form "
                          << FT_BOLD_B << Repeat2->getName() << FT_RST
                          << " because "
                          << ex.what()
                          << std::endl;
            }

            std::cout << "\nPotts noticed an error in his form and tried to sign the Pardon Form for his mistake." << std::endl;
            try {
                Potts.signForm(*Sorry);
                std::cout << std::endl;
            } catch (const AForm::GradeException& ex) {
                std::cout << FT_BOLD_B << Potts.getName() << FT_RST
                          << " couldn't sign the form "
                          << FT_BOLD_B << Sorry->getName() << FT_RST
                          << " because "
                          << ex.what()
                          << std::endl;
            }
            std::cout << "\nThe HWR decided to use their Presidential Pardon." << std::endl;
            try {
                HWR.signForm(*Sorry);
            } catch (const AForm::GradeException& ex) {
                std::cout << FT_BOLD_B << HWR.getName() << FT_RST
                          << " couldn't sign the form "
                          << FT_BOLD_B << Sorry->getName() << FT_RST
                          << " because "
                          << ex.what()
                          << std::endl;
            }
            if (Sorry->isSigned())
                std::cout << Sorry->getName()
                          << " is now "
                          << FT_BOLD_G << "signed" << FT_RST
                          << std::endl;
            try {
                HWR.executeForm(*Sorry);
            } catch (const AForm::GradeException& ex) {
                std::cout << FT_BOLD_B << HWR.getName() << FT_RST
                          << " couldn't execute the form "
                          << FT_BOLD_B << Sorry->getName() << FT_RST
                          << " because "
                          << ex.what()
                          << std::endl;
            }
        } catch (const Intern::FormNotFoundException &ex) {
            std::cout << "Error: " << ex.what() << std::endl;
        }

        delete Repeat;
        delete Repeat2;
        delete Tree;
        delete Sorry;
        delete WhoCares;

        std::cout 	<< "\n--4pm--\nEnd of day (except for intern that needs to clean the HWR' office)\n"
                     << FT_BOLD << "\n--------- Goodbye ----------\n\n" << FT_RST;

    } catch (const Bureaucrat::GradeException &ex) {
        std::cout << "Error: " << ex.what() << std::endl;
    } catch (const AForm::GradeException &ex) {
        std::cout << "Error: " << ex.what() << std::endl;
    }

    return 0;
}
