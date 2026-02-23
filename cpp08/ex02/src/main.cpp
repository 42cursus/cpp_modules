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
#include <ctime>
#include <iostream>
#include <sstream> // for std::ostringstream
#include <stack>
#include <string>

#define TEST_DATA_SIZE 5

static void title(const std::string &name)
{
	std::cout << "\n============================================================================\n";
	std::cout << "\t" << name;
	std::cout << "\n============================================================================\n";
}

static void check(bool ok, const std::string &what)
{
	std::cout << (ok ? "[OK]\t" : "[FAIL]\t") << what << "\n";
}

static void printIntStack(const MutantStack<int> &mutantStack, const std::string &label)
{
	std::cout << label << ": size=" << mutantStack.size();
	if (!mutantStack.empty())
		std::cout << ", top=" << mutantStack.top();
	std::cout << "\n";

	std::cout << "\tvalues: ";
	MutantStack<int>::const_iterator iter = mutantStack.begin();
	for (; iter != mutantStack.end(); ++iter)
		std::cout << *iter << " ";
	std::cout << std::endl;
}

__attribute__((used)) std::string serializeArray(const int *data, std::size_t n)
{
	std::ostringstream oss;
	oss << "[";
	if (n > 0) {
		oss << data[0];
		for (std::size_t i = 1; i < n; ++i)
			oss << " " << data[i];
	}
	oss << "]";
	return oss.str();
}

int main()
{
	MutantStack<int> testStack;
	int data[TEST_DATA_SIZE];

	std::srand(time(NULL));
	for (int i = 0; i < TEST_DATA_SIZE; ++i)
		data[i] = std::rand() % 4097;

	title("MutantStack - basic behavior (push/top/pop/size)");
	{
		check(testStack.empty(), "new stack is empty");
		check(testStack.size() == 0, "new stack size == 0");

		for (int i = 0; i < TEST_DATA_SIZE; ++i)
			testStack.push(data[i]);

		std::cout << "\n\tAfter pushing: " << std::endl;
		std::string what;
		{
			std::ostringstream oss;
			oss << "size == " << testStack.size()
				<< " after " << TEST_DATA_SIZE << " pushes";
			what = oss.str();
		}

		check(testStack.size() == TEST_DATA_SIZE, what);
		check(
			testStack.top() == data[4], "top() is last pushed element: " + serializeArray(&data[4], 1));

		std::cout << "\tContent of the mutant stack (iterated):" << std::endl;
		{
			MutantStack<int>::iterator iter = testStack.begin();
			MutantStack<int>::iterator end = testStack.end();

			std::ostringstream oss;
			oss << "[";
			oss << *iter++;
			for (; iter != end; ++iter)
				oss << " " << *iter;
			oss << "]";
			std::cout << "\t" << oss.str() << std::endl;
		}

		std::stack<int> stck(testStack);
		std::cout << "\tContents of the copied stack:" << std::endl;
		{
			std::ostringstream oss;
			oss << "[";
			oss << stck.top();
			stck.pop();
			while (!stck.empty()) {
				oss << " " << stck.top();
				stck.pop();
			}

			oss << "]";
			std::cout << "\t" << oss.str() << std::endl;
		}

		std::cout << "\n\tAfter pop(): " << std::endl;
		testStack.pop();
		check(testStack.size() == TEST_DATA_SIZE - 1, "size == 4 after pop()");
		check(testStack.top() == data[3], "top() updated after pop(): " + serializeArray(&data[3], 1));

		std::cout << "\tRestoring the stack..." << std::endl;
		testStack.push(data[4]);
	}

	title("MutantStack - iteration order (begin/end)");
	{
		std::cout << "\tIterating (bottom -> top):\n  ";

		MutantStack<int>::iterator iter = testStack.begin();
		MutantStack<int>::iterator end = testStack.end();
		{
			std::ostringstream oss;
			oss << "[";
			oss << *iter++;
			for (; iter != end; ++iter)
				oss << " " << *iter;
			oss << "]";
			std::cout << "\t" << oss.str() << std::endl;
		}

		check(*testStack.begin() == data[0],
			  "begin() points to bottom element: " + serializeArray(&data[0], 1));
		MutantStack<int>::iterator last = testStack.end();
		--last;
		check(*last == data[4],
			  "end()-1 points to top element: " + serializeArray(&data[4], 1));
	}

	title("MutantStack - const iteration (begin/end const)");
	{
		const MutantStack<int> &mutantStack = testStack;
		
		int sum = 0;

		MutantStack<int>::const_iterator iter = mutantStack.begin();
		MutantStack<int>::const_iterator end = mutantStack.end();

		for (; iter != end; ++iter)
			sum += *iter;

		std::cout << "\tsum over const iteration: " << sum << "\n";
		int testSum = data[0] + data[1] + data[2] + data[3] + data[4];
		check(sum == testSum, "const iteration works and visits all elements");
	}

	title("MutantStack - reverse iteration (rbegin/rend)");
	{
		std::cout << "\tIterating (top -> bottom):\n  ";
		MutantStack<int>::reverse_iterator revit = testStack.rbegin();
		MutantStack<int>::reverse_iterator rend	 = testStack.rend();
		{
			std::ostringstream oss;
			oss << "[";
			oss << *revit++;
			for (; revit != rend; ++revit)
				oss << " " << *revit;
			oss << "]";
			std::cout << "\t" << oss.str() << std::endl;
		}
		check(*testStack.rbegin() == data[4],
			  "rbegin() points to top element: " + serializeArray(&data[4], 1));
	}

	title("MutantStack - copy behavior (copy-construct and std::stack adapter)");
	{
		MutantStack<int> copy(testStack);
		printIntStack(copy, "\tcopy constructed from testStack");
		check(copy.size() == testStack.size(), "copy has same size");
		check(copy.top() == testStack.top(), "copy has same top");

		copy.push(999);
		check(copy.top() == 999, "modifying copy doesn't change original (copy.top == 999)");
		check(testStack.top() == data[4],
			  "original unchanged (m.top == " + serializeArray(&data[4], 1) +")");

		std::stack<int> asStack(testStack);
		std::cout << "\tDraining std::stack<int> constructed from MutantStack:\n";
		{
			std::ostringstream oss;
			oss << "[";
			oss << asStack.top();
			asStack.pop();
			while (!asStack.empty()) {
				oss << " " << asStack.top();
				asStack.pop();
			}

			oss << "]";
			std::cout << "\t" << oss.str() << std::endl;
		}
		check(true, "std::stack can be constructed from MutantStack");
	}

	title("MutantStack - small randomized demo (repeatable seed)");
	{
		std::srand(42); // deterministic output
		MutantStack<int> rnd;

		for (int i = 0; i < 6; ++i)
			rnd.push(std::rand() % 100);

		printIntStack(rnd, "\tRandom stack");
		check(rnd.size() == 6, "random stack size == 6");
	}

	title("Done");
	return 0;
}
