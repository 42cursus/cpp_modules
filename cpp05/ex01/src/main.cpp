/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 21:25:19 by abelov            #+#    #+#             */
/*   Updated: 2025/07/25 21:25:20 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat Poppy("Poppy", 30);
        Bureaucrat Vendy("Vendy", 122);

        Form B27("B27", 32, 60);
        Form B28("B28", 100, 80);

        std::cout << std::endl;
        std::cout << FT_BOLD "Bureaucrats:\n" FT_RST;
        std::cout << Poppy
                  << Vendy
                  << std::endl;
        std::cout << FT_BOLD "\nForms:\n" FT_RST;
        std::cout << B27
                  << B28
                  << std::endl;

        std::cout << FT_BOLD "Sign protocol test:" FT_RST << std::endl;

        try {
            Poppy.signForm(B28);
        } catch (Form::GradeTooLowException &ex) {
            std::cout << FT_BOLD_B << Poppy.getName() << FT_RST
                      << " coudn't sign the form "
                      << FT_BOLD_B << B28.getName() << FT_RST
                      << " because "
                      << ex.what()
                      << std::endl;
        }

        if (B28.isSigned()) {
            std::cout << B28.getName()
                      << " is now "
                      << FT_BOLD_G << "signed" << FT_RST
                      << "\n"
                      << std::endl;
        } else {
            std::cout << B28.getName()
                      << " is "
                      << FT_BOLD_R << "not signed" << FT_RST
                      << "\n"
                      << std::endl;
        }

        try {
            Vendy.signForm(B27);
        } catch (Form::GradeException &ex) {
            std::cout << FT_BOLD_B << Vendy.getName() << FT_RST
                      << " coudn't sign the form "
                      << FT_BOLD_B << B27.getName() << FT_RST
                      << " because "
                      << ex.what()
                      << std::endl;
        }

        if (B27.isSigned()) {
            std::cout << B27.getName()
                      << " is now "
                      << FT_BOLD_G << "signed" << FT_RST
                      << "\n"
                      << std::endl;
        } else {
            std::cout << B27.getName()
                      << " is " << FT_BOLD_R << "not signed" << FT_RST
                      << "\n"
                      << std::endl;
        }

        try {
            Poppy.signForm(B27);
        } catch (Form::GradeException &ex) {
            std::cout << FT_BOLD_B << Poppy.getName() << FT_RST
                      << " coudn't sign the form "
                      << FT_BOLD_B << B27.getName() << FT_RST
                      <<" because "
                      << ex.what()
                      << std::endl;
        }
        if (B27.isSigned()) {
            std::cout << B27.getName()
                      << " is now "
                      << FT_BOLD_G << "signed" << FT_RST
                      << std::endl;
        } else {
            std::cout << B27.getName()
                      << " is "
                      << FT_BOLD_R << "not signed" << FT_RST
                      << "\n"
                      << std::endl;
        }

        Bureaucrat Jack("Jack", 0);
    } catch (Bureaucrat::GradeException &ex) {
        std::cout << "Error: " << ex.what() << std::endl;
    } catch (Form::GradeException &ex) {
        std::cout << "Error: " << ex.what() << std::endl;
    }
    return 0;
}
