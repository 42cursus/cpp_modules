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

template<class T, class Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin()
{
	return this->c.begin();
}

template<class T, class Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end()
{
	return this->c.end();
}

template<class T, class Container>
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::begin() const
{
	return this->c.begin();
}

template<class T, class Container>
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::end() const
{
	return this->c.end();
}

template<class T, class Container>
typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::rbegin()
{
	return this->c.rbegin();
}

template<class T, class Container>
typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::rend()
{
	return this->c.rend();
}

template<class T, class Container>
typename MutantStack<T, Container>::const_reverse_iterator MutantStack<T, Container>::rbegin() const
{
	return this->c.rbegin();
}

template<class T, class Container>
typename MutantStack<T, Container>::const_reverse_iterator MutantStack<T, Container>::rend() const
{
	return this->c.rend();
}
