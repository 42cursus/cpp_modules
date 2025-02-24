/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nullptr.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 00:18:40 by abelov            #+#    #+#             */
/*   Updated: 2025/02/24 00:18:40 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FT_NULLPTR_HPP
#define FT_NULLPTR_HPP

// Reference: How to define our own nullptr in c++98?
// 	https://stackoverflow.com/questions/44517556/
//  this version is efficient and more idiomatic in C++98

#if defined(__cplusplus) && __cplusplus < 201103L  // C++98 or older

const                           /* this is a const object...     */
class nullptr_t
{
public:
	template<class T>          	// convertible to any type
	operator T*() const        	// of null non-member
		{ return (NULL); }      // pointer...

	template<class C, class T>	// or any type of null
		operator T C::*() const	// member pointer...
		{ return (NULL); }

private:
	void operator&() const;		// Prevent taking the address
} ft_nullptr = {};

#define nullptr ft_nullptr

#endif

#endif //FT_NULLPTR_HPP
