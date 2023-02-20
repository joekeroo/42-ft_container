/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testStack.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 14:08:18 by jhii              #+#    #+#             */
/*   Updated: 2023/02/20 16:41:47 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack>
#include <vector>
#include "Stack.hpp"
#include "Vector.hpp"

void	testStack(void)
{
	// testStackAll();
}

void	testStackAll(void)
{
	testStackConstructor();
	testStackEmpty();
	testStackSize();
	testStackTop();
	testStackPush();
	testStackPop();
	testStackSwap();
}

void	testStackConstructor(void)
{
	std::cout << GREEN "Testing stack constructor" RESET << std::endl;
	std::vector<int>	v1(2,200);
	ft::vector<int>		v2(2,200);

	std::stack<int, std::vector<int> > s1;
	std::stack<int, std::vector<int> > s2(v1);

	ft::stack<int, ft::vector<int> > s3;
	ft::stack<int, ft::vector<int> > s4(v2);

	std::cout << CYAN "s1.size() : " << s1.size() << std::endl;
	std::cout << CYAN "s2.size() : " << s2.size() << std::endl;
	std::cout << RESET;

	std::cout << BLUE "s3.size() : " << s3.size() << std::endl;
	std::cout << BLUE "s4.size() : " << s4.size() << std::endl;
	std::cout << RESET << std::endl;
}

void	testStackEmpty(void)
{
	std::cout << GREEN "Testing stack.empty()" RESET << std::endl;
	int	sum1 = 0;
	std::stack<int>	s1;

	for (int i = 1; i <= 10; i++)
		s1.push(i);
	while (!s1.empty())
	{
		sum1 += s1.top();
		s1.pop();
	}
	std::cout << CYAN "s1 total  : " << sum1 << std::endl;
	std::cout << RESET;

	int	sum2 = 0;
	ft::stack<int>	s2;

	for (int i = 1; i <= 10; i++)
		s2.push(i);

	while (!s2.empty())
	{
		sum2 += s2.top();
		s2.pop();
	}
	std::cout << BLUE "s2 total  : " << sum2 << std::endl;
	std::cout << RESET << std::endl;
}

void	testStackSize(void)
{
	std::cout << GREEN "Testing stack.size()" RESET << std::endl;
	std::stack<int> s1;
	std::cout << CYAN "s1.size() : " << s1.size() << std::endl;
	for (int i = 0; i < 5; i++) s1.push(i);
		std::cout << CYAN "s1.size() : " << s1.size() << std::endl;
	s1.pop();
	std::cout << CYAN "s1.size() : " << s1.size() << std::endl;
	std::cout << RESET;

	ft::stack<int> s2;
	std::cout << BLUE "s2.size() : " << s2.size() << std::endl;
	for (int i = 0; i < 5; i++) s2.push(i);
		std::cout << BLUE "s2.size() : " << s2.size() << std::endl;
	s2.pop();
	std::cout << BLUE "s2.size() : " << s2.size() << std::endl;
	std::cout << RESET << std::endl;
}

void	testStackTop(void)
{
	std::cout << GREEN "Testing stack.top()" RESET << std::endl;
	std::stack<int> v1;

	v1.push(10);
	v1.push(20);
	v1.top() -= 5;

	std::cout << CYAN "v1.top()  : " << v1.top() << std::endl;
	std::cout << RESET;

	ft::stack<int> v2;

	v2.push(10);
	v2.push(20);
	v2.top() -= 5;

	std::cout << BLUE "v2.top()  : " << v2.top() << std::endl;
	std::cout << RESET << std::endl;
}

void	testStackPush(void)
{
	std::cout << GREEN "Testing stack.push()" RESET << std::endl;
	std::stack<int>	s1;

	for (int i = 0; i < 5; ++i)
		s1.push(i);
	std::cout << CYAN "s1.top()  :";
	while (!s1.empty())
	{
		std::cout << CYAN " " << s1.top();
		s1.pop();
	}
	std::cout << RESET << std::endl;

	ft::stack<int>	s2;

	for (int i = 0; i < 5; ++i)
		s2.push(i);
	std::cout << BLUE "s2.top()  :";
	while (!s2.empty())
	{
		std::cout << BLUE " " << s2.top();
		s2.pop();
	}
	std::cout << RESET << std::endl << std::endl;
}

void	testStackPop(void)
{
	std::cout << GREEN "Testing stack.pop()" RESET << std::endl;
	std::stack<int>	s1;

	for (int i = 0; i < 5; ++i)
		s1.push(i);
	std::cout << CYAN "s1.top()  :";
	while (!s1.empty())
	{
		std::cout << CYAN " " << s1.top();
		s1.pop();
	}
	std::cout << RESET << std::endl;

	ft::stack<int>	s2;

	for (int i = 0; i < 5; ++i)
		s2.push(i);
	std::cout << BLUE "s2.top()  :";
	while (!s2.empty())
	{
		std::cout << BLUE " " << s2.top();
		s2.pop();
	}
	std::cout << RESET << std::endl << std::endl;
}

void	testStackSwap(void)
{
	std::cout << GREEN "Testing stack.swap()" RESET << std::endl;
	std::stack<int>	s1;
	std::stack<int>	s2;

	s1.push(10);
	s1.push(20);
	s1.push(30);

	s2.push(111);
	s2.push(222);

	s1.swap(s2);

	std::cout << CYAN "s1.size() : " << s1.size() << std::endl;
	std::cout << CYAN "s2.size() : " << s2.size() << std::endl;
	std::cout << RESET;

	ft::stack<int>	s3;
	ft::stack<int>	s4;

	s3.push(10);
	s3.push(20);
	s3.push(30);

	s4.push(111);
	s4.push(222);

	s3.swap(s4);

	std::cout << BLUE "s3.size() : " << s3.size() << std::endl;
	std::cout << BLUE "s4.size() : " << s4.size() << std::endl;
	std::cout << RESET;
}
