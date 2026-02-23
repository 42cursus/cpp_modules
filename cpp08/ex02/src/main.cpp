/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 22:58:23 by abelov            #+#    #+#             */
/*   Updated: 2026/02/22 18:25:45 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <cstdlib>

int main()
{
	MutantStack<int> mstack;

	std::srand(time(NULL));
	for (int i = 0; i < 2; ++i)
		mstack.push(std::rand() % 4097);

	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;

	for (int i = 0; i < 4; ++i) {
		const int val = rand();
		mstack.push(val);
	}

	MutantStack<int>::iterator iter = mstack.begin();
	++iter;
	--iter;
	for (; iter != mstack.end(); ++iter)
		std::cout << *iter << std::endl;

	std::stack<int> stck(mstack);
	std::cout << "\nContents of the copied stack:" << std::endl;

	while (!stck.empty()) {
		std::cout << stck.top() << std::endl;
		stck.pop();
	}

	return 0;
}
