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

#ifndef NULLPTR_HPP
#define NULLPTR_HPP

// Reference: How to define our own nullptr in c++98?
// 	https://stackoverflow.com/questions/44517556/
//  this version is efficient and more idiomatic in C++98

const                           /* this is a const object...     */
class nullptr_t
{
public:
	template<class T>          	// convertible to any type
	operator T*() const        	// of null non-member
		{ return 0; }           // pointer...

	template<class C, class T>	// or any type of null
		operator T C::*() const	// member pointer...
		{ return 0; }

private:
	void operator&() const;		// Prevent taking the address
} nullptr = {};

#endif //NULLPTR_HPP
