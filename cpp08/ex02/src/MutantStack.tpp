/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 22:59:09 by abelov            #+#    #+#             */
/*   Updated: 2025/07/25 22:59:10 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <class T, class Container>
MutantStack<T, Container>::MutantStack() {}

template <class T, class Container>
MutantStack<T, Container>::~MutantStack() {}

template <class T, class Container>
MutantStack<T, Container>::MutantStack(const MutantStack &other) : std::stack<T, Container>(other) {}

template <class T, class Container>
MutantStack<T, Container>& MutantStack<T, Container>::operator=(const MutantStack &other)
{
	if (this != &other)
		std::stack<T, Container>::operator=(other); // calling the assignment operator from the base class
	return (*this);
}
