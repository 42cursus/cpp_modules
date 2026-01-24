/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 21:45:23 by abelov            #+#    #+#             */
/*   Updated: 2025/07/25 21:45:23 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "formatting.h"

/*
** -------------------------------- STATIC VARS -------------------------------
*/

/*
** ------------------------------- CONSTRUCTORS -------------------------------
*/

/*
** ------------------------------- DESTRUCTORS --------------------------------
*/


/*
** -------------------------------- OPERATORS ---------------------------------
*/

/*
** -------------------------------- OVERLOADS ---------------------------------
*/

/*
** --------------------------------- METHODS ----------------------------------
*/

/*
** -------------------------------- ACCESSORS ---------------------------------
*/

/*
** -------------------------------- EXCEPTIONS --------------------------------
*/

/*
** -------------------------------- MISCELLANEOUS --------------------------------
*/

Base *generate(void) {
    Base	*baseptr = NULL;
    int rnd = std::rand() % 3;
    std::cout << "rnd = " << rnd << "  rnd % 3 = " << (rnd % 3) << std::endl;
    if (rnd == 0)
    {
        std::cout << "A has been generated" << std::endl;
        baseptr = new A;
    }
    else if (rnd == 1)
    {
        std::cout << "B has been generated" << std::endl;
        baseptr = new B;
    }
    else
    {
        std::cout << "C has been generated" << std::endl;
        baseptr = new C;
    }
    return (baseptr);
}

void identify(Base *ptr) {

    enum Type { TYPE_A=0, TYPE_B, TYPE_C, TYPE_UNKNOWN };
    Type type = TYPE_UNKNOWN;

    if (ptr == NULL) {
        std::cout << "null\n";
        return;
    }

    (void)(
    (dynamic_cast<A*>(ptr) && (type = TYPE_A, true)) ||
    (dynamic_cast<B*>(ptr) && (type = TYPE_B, true)) ||
    (dynamic_cast<C*>(ptr) && (type = TYPE_C, true)));

    switch (type) {
        case TYPE_A:
            std::cout << "A has been identified\n";
            break;
        case TYPE_B:
            std::cout << "B has been identified\n";
            break;
        case TYPE_C:
            std::cout << "C has been identified\n";
            break;
        default:
            std::cout << "Unknown\n";
            break;
    }
}

void identify(Base &ref)
{
    try {
        A &aref = dynamic_cast<A&>(ref);
        std::cout << "A has been identified" << std::endl;
        (void)aref;
        return;
    } catch (const std::exception &) {}

    try {
        B &bref = dynamic_cast<B&>(ref);
        std::cout << "B has been identified" << std::endl;
        (void)bref;
        return;
    } catch (const std::exception &) {}

    try {
        C &cref = dynamic_cast<C&>(ref);
        std::cout << "C has been identified" << std::endl;
        (void)cref;
        return;
    } catch (const std::exception &) {}

    std::cout << "Unknown\n";
}

/*
void	identify(Base &ref)
{
    try
    {
        A &aref = dynamic_cast <A&> (ref);
        std::cout << "A has been identified" << std::endl;
        (void) aref;
    }
    catch (const std::exception){ (void)ref; }
    try
    {
        B &bref = (dynamic_cast <B&> (ref));
        std::cout << "B has been identified" << std::endl;
        (void) bref;
    }
    catch (const std::exception){ (void)ref; }
    try
    {
        C &cref = (dynamic_cast <C&> (ref));
        std::cout << "C has been identified" << std::endl;
        (void) cref;
    }
    catch (const std::exception){ (void)ref; }
}
*/