/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 00:10:32 by abelov            #+#    #+#             */
/*   Updated: 2025/03/10 00:07:32 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits>
#include "Fixed.hpp"

/**
 * https://docs.oracle.com/cd/E19120-01/open.solaris/817-5477/eoizy/index.html
 * @param x
 * @return
 */
float Fixed::intToFloatX87(int x)
{
	float f;

	/**
	 * FILD — Load Integer
	 * https://www.felixcloutier.com/x86/fild
	 *
	 * FST/FSTP — Store Floating-Point Value
	 * https://www.felixcloutier.com/x86/fst:fstp
	 *
	 * filds  short   # Load 16-bit integer
	 * fildl  long    # Load 32-bit integer (in AT&T syntax, l refers to 32-bit integers)
	 * fildq  quad    # Load 64-bit integer
	 *
	 * fstps	32-bit float	s	Store as 32-bit float
	 * fstpl	64-bit double	l	Store as 64-bit double
	 * fstpq	80-bit float	q	Store as 80-bit extended float
	 */
	__asm__ volatile (
		"fildl %1\n"  // Load the integer onto the FPU stack.
		"fstps %0"    // Store the float back to memory.
		: "=m"(f)
		: "m"(x));
	return (f);
}

/**
 * https://www.flipcode.com/archives/floattoint.txt
 * @param f
 * @return
 */
int Fixed::floatToIntX87(float f)
{
	int i;
	/**
	 * FLD — Load Floating-Point Value
	 * https://www.felixcloutier.com/x86/fild
	 *
	 * FIST/FISTP — Integer Store and Pop
	 * https://www.felixcloutier.com/x86/fist:fistp
	 */
	__asm__ __volatile__ (
		"fldl %1\n"  // Load 32-bit float onto FPU stack
		/* fistps Converts ST0 to integer by rounding it to the closest to ST0
		 * integer, writes it back to a and pops ST0 from the FP-stack. */
		"fistps %0"  // Store as 32-bit integer (truncating)
		: "=m"(i)
		: "m"(f)
		: 	// The clobber list is empty because we do not explicitly
		);	// modify general-purpose registers—only the x87 FPU stack
	return (i);
}
