/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 22:40:29 by abelov            #+#    #+#             */
/*   Updated: 2025/07/25 22:40:30 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


template <typename T>
typename T::iterator easyfind(T &container, int val)
{
	typename T::iterator	iter;
	iter = std::find(container.begin(), container.end(), val);
	if (iter == container.end())
		throw std::out_of_range("Container does not contain passed value");
	int index = 0;
	index = std::distance(container.begin(), iter);
	std::cout << "Value [\"" << val << "\"] was successfully found at index: " << index << std::endl;
	return (iter);
}
