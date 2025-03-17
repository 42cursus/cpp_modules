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

#include "Fixed.hpp"

/**
 * https://www.felixcloutier.com/x86/divps
 * @param a
 * @param b
 * @return
 */
void Fixed::floatBatchDivSSE(const float *a, const float *b, float *result)
{
	__m128 vecA = _mm_loadu_ps(a);  // Load 4 floats from a
	__m128 vecB = _mm_loadu_ps(b);  // Load 4 floats from b
	__m128 vecRes = _mm_div_ps(vecA, vecB); // Perform element-wise division
	_mm_storeu_ps(result, vecRes);  // Store result back to memory
}

float Fixed::floatDivSSE(const float &a, const float &b)
{
	float result;
	__asm__ __volatile__ (
		"movss %1, %%xmm0\n\t"
		"movss %2, %%xmm1\n\t"
		"divss %%xmm1, %%xmm0\n\t"
		"movss %%xmm0, %0"
		: "=m"(result)
		: "m"(a), "m"(b)
		: "xmm0", "xmm1"
		);
	return result;
}

float Fixed::intToFloatSSE(int x)
{
	register float f;

	/**
	 * CVTSI2SS — Convert Doubleword Integer to Scalar
	 * 	Single Precision Floating-Point Value
	 * https://www.felixcloutier.com/x86/cvtsi2ss
	 */
	__asm__ volatile ("cvtsi2ss %1, %0" : "=x"(f) : "r"(x));
	return (f);
}

int Fixed::floatToIntSSE(register float f)
{
	int i;

	__asm__ volatile ("cvttss2si %1, %0" : "=r"(i) : "x"(f));
	return (i);
}

int Fixed::floatToIntSSE2(float f)
{
	return _mm_cvtss_si32(_mm_set_ss(f)); // Convert float to int using SSE
}

float Fixed::intToFloatSSE2(int x)
{
	return _mm_cvtss_f32(_mm_cvtsi32_ss(_mm_setzero_ps(), x));
}
