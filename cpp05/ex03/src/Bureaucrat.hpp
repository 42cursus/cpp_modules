/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 21:16:47 by abelov            #+#    #+#             */
/*   Updated: 2025/07/25 21:16:48 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>

/**
 * https://www.ditig.com/256-colors-cheat-sheet
 * List of ansi color escape sequences:
 * 	https://stackoverflow.com/questions/4842424/
 * 	https://en.wikipedia.org/wiki/ANSI_escape_code
 */
#define FT_DIM  	"\033[2m"       // Dim
#define FT_BOLD  	"\033[1m"       // Bold
#define FT_UND   	"\033[4m"       // Underline
#define FT_RED   	"\033[0;31m"
#define FT_GREEN 	"\033[0;32m"    // Green
#define FT_BLUE 	"\033[0;32m"    // Blue
#define FT_CYAN  	"\033[36m"
#define FT_WHITE_B 	"\033[1;38;5;15m"
#define FT_PINK		"\033[1;95m"    // Pink (Bright Magenta)
#define FT_SALMON	"\033[38;5;210m"
#define FT_SALMON_B	"\033[1;38;5;210m"
#define FT_ORANGE	"\033[38;5;202m"
#define FT_PUMPKIN	"\033[38;5;202m"
#define FT_PUMPKIN2		"\033[38;5;208m"
#define FT_SAND_TAN		"\033[38;5;180m"  // sandy beige
#define FT_LIGHT_BROWN	"\033[38;5;137m"  // more subdued brown-orange
#define FT_ASH_ORANGE	"\033[38;5;130m"  // dark muted orange
#define FT_STEEL_BLUE	"\033[38;5;67m"
#define FT_STEEL_BLUE_B	"\033[1;38;5;67m"
#define FT_SKY_BLUE		"\033[38;5;117m"
#define FT_CADET_BLUE	"\033[38;5;72m"
#define FT_CADET_BLUE_B	"\033[1;38;5;72m"
#define FT_BRIGHT_RED2	"\033[38;5;196m"
#define FT_BRIGHT_RED3	"\033[38;5;160m"
#define FT_LIME_GREEN	"\033[1;38;5;10m"
#define FT_LIGHT_PURPLE	"\033[38;5;135m"
#define FT_HOT_PINK	"\033[38;5;197m"
#define FT_PALE_GREEN	"\033[38;5;114m"
#define FT_PALE_BLUE	"\033[38;5;111m"
#define FT_PALE_TURQUOISE4	"\033[38;5;66m"
#define FT_PALE_TURQUOISE4_B	"\033[1;38;5;66m"
#define FT_CHARTREUSE3	"\033[38;5;70m"
#define FT_CHARTREUSE4	"\033[38;5;64m"
#define FT_CHARTREUSE4_B	"\033[1;38;5;64m"
#define FT_SEA_GREEN2	"\033[38;5;83m"
#define FT_SEA_GREEN2_B	"\033[1;38;5;83m"
#define FT_DARK_SEA_GREEN4	"\033[38;5;71m"
#define FT_DARK_SEA_GREEN4_B	"\033[1;38;5;71m"
#define FT_SOFT_GREEN "\033[38;5;108m"   // muted green (greenish gray)
#define FT_OLIVE_GREEN "\033[38;5;100m"  // olive tone
#define FT_DIM_GREEN   "\033[38;5;65m"   // darker, dull green
#define FT_BOLD_R	"\033[1;31m"    // Bold red
#define FT_BOLD_G	"\033[1;32m"    // Bold green
#define FT_BOLD_B	"\033[1;34m"    // Bold blue
#define FT_BOLD_Y	"\033[1;33m"    // Bold yellow
#define FT_BOLD_M	"\033[1;35m"    // Bold magenta
#define FT_BOLD_C	"\033[1;36m"    // Bold cyan
#define FT_BOLD_W	"\033[1;37m"    // Bold white
#define FT_RST		"\033[0m"       // Reset to default color

class AForm;

class Bureaucrat
{
private:

    std::string         _name;
    int                 _grade;
    static const int    GRADE_RANGE_MAX;
    static const int    GRADE_RANGE_MIN;
    static const        std::string &DEFAULT_NAME;

public:

    Bureaucrat();
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    void incrementGrade(int);
    void incrementGrade();
    void decrementGrade(int);
    void decrementGrade();

    void signForm(AForm &form);
    void executeForm(AForm const &form) const;

    class GradeException : public std::exception {
    public:
        virtual const char* what() const throw();
    protected:
        virtual const char* msg() const throw() = 0;
    };

    class GradeGenericException : public GradeException {
    public:
        explicit GradeGenericException(const std::string &msg);
        GradeGenericException();
        GradeGenericException(const GradeGenericException& other);
        GradeGenericException& operator=(const GradeGenericException& other);
        ~GradeGenericException() throw ();
    protected:
        virtual const char* msg() const throw();
    private:
        std::string _msg;
        static const std::string DEFAULT_MESSAGE;
    };

    class GradeTooLowException : public GradeException {
    public:
        GradeTooLowException();
    protected:
        virtual const char* msg() const throw();
    private:
        static const std::string _msg;
        static std::string build_msg();
    };

    class GradeTooHighException : public GradeException {
    public:
        GradeTooHighException();
    protected:
        virtual const char* msg() const throw();
    private:
        static const std::string _msg;
        static std::string build_msg();
    };

    std::string getName() const;
    int getGrade() const;

};

std::ostream& operator<<(std::ostream& oss, const Bureaucrat& bureaucrat);

#endif //BUREAUCRAT_HPP
