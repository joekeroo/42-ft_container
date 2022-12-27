/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testVector.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:42:05 by jhii              #+#    #+#             */
/*   Updated: 2022/12/23 17:30:14 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include "Vector.hpp"

void	testVector(void)
{
	// testVectorAll();
}

void	testVectorAll(void)
{
	testVectorConstructor();
	testVectorRelationalOperator();
	testVectorResize();
	testVectorData();
	testVectorAssign();
	testVectorPushBack();
	testVectorPopBack();
	testVectorSwap();
	testVectorClear();
	testVectorErase();
	testVectorInsert();
}

void	testVectorConstructor(void)
{
	// std::vector<int> v1;
	// std::vector<int> v2 (4,100);
	// std::vector<int> v3 (v2.begin(),v2.end());
	// std::vector<int> v4 (v3);

	// int	int1[] = {16, 2, 77, 29};
	// std::vector<int> v5 (int1, int1 + sizeof(int1) / sizeof(int));

	// std::cout << CYAN "v5.data()     :";
	// for (size_t i = 0; i < v5.size(); i++)
	// 	std::cout << ' ' << v5[i];
	// std::cout << std::endl;
	// std::cout << "v5.size()     : " << v5.size() << std::endl;
	// std::cout << "v5.capacity() : " << v5.capacity() << std::endl;
	// std::cout << RESET << std::endl;

	ft::vector<int> v6;
	ft::vector<int> v7(4,100);
	ft::vector<int> v8(v7.begin(),v7.end());
	ft::vector<int> v9(v8);

	int	int2[] = {16, 2, 77, 29};
	ft::vector<int> v10(int2, int2 + sizeof(int2) / sizeof(int));

	std::cout << BLUE "v10.data()     :";
	for (size_t i = 0; i < v10.size(); i++)
		std::cout << ' ' << v10[i];
	std::cout << std::endl;
	std::cout << "v10.size()     : " << v10.size() << std::endl;
	std::cout << "v10.capacity() : " << v10.capacity() << std::endl;
	std::cout << RESET;
}

void	testVectorRelationalOperator(void)
{
	std::vector<int>	v1(3, 100);
	std::vector<int>	v2(2, 200);
	ft::vector<int>		v3(3, 100);
	ft::vector<int>		v4(2, 200);

	if (v1 == v2)
		std::cout << CYAN "v1 and v2 are equal" RESET << std::endl;
	if (v1 != v2)
		std::cout << CYAN "v1 and v2 are not equal" RESET << std::endl;
	if (v1 < v2)
		std::cout << CYAN "v1 is less than v2" RESET << std::endl;
	if (v1 > v2)
		std::cout << CYAN "v1 is greater than v2" RESET << std::endl;
	if (v1 <= v2)
		std::cout << CYAN "v1 is less than or equal to v2" RESET << std::endl;
	if (v1 >= v2)
		std::cout << CYAN "v1 is greater than or equal to v2" RESET << std::endl;

	if (v3 == v4)
		std::cout << BLUE "v3 and v4 are equal" RESET << std::endl;
	if (v3 != v4)
		std::cout << BLUE "v3 and v4 are not equal" RESET << std::endl;
	if (v3 < v4)
		std::cout << BLUE "v3 is less than v4" RESET << std::endl;
	if (v3 > v4)
		std::cout << BLUE "v3 is greater than v4" RESET << std::endl;
	if (v3 <= v4)
		std::cout << BLUE "v3 is less than or equal to v4" RESET << std::endl;
	if (v3 >= v4)
		std::cout << BLUE "v3 is greater than or equal to v4" RESET << std::endl;
}

void	testVectorResize(void)
{
	std::vector<int>	v1(10, 5);
	ft::vector<int>		v2(10, 5);

	v1.resize(5);
	v1.resize(8,100);
	v1.resize(12);

	std::cout << CYAN "v1.data()     :";
	for (size_t i = 0; i < v1.size(); i++)
		std::cout << ' ' << v1[i];
	std::cout << std::endl;
	std::cout << "v1.size()     : " << v1.size() << std::endl;
	std::cout << "v1.capacity() : " << v1.capacity() << std::endl;
	std::cout << RESET << std::endl;

	v2.resize(5);
	v2.resize(8,100);
	v2.resize(12);

	std::cout << BLUE "v2.data()     :";
	for (size_t i = 0; i < v2.size(); i++)
		std::cout << ' ' << v2[i];
	std::cout << std::endl;
	std::cout << "v2.size()     : " << v2.size() << std::endl;
	std::cout << "v2.capacity() : " << v2.capacity() << std::endl;
	std::cout << RESET;
}

void	testVectorData(void)
{
	std::vector<int>	v1(5);
	ft::vector<int>		v2(5);

	int	*p1 = v1.data();
	int	*p2 = v2.data();

	*p1 = 10;
	++p1;
	*p1 = 20;
	p1[2] = 100;

	std::cout << CYAN "v1.data() :";
	for (unsigned i=0; i<v1.size(); ++i)
		std::cout << ' ' << v1[i];
	std::cout << RESET << std::endl;

	*p2 = 10;
	++p2;
	*p2 = 20;
	p2[2] = 100;

	std::cout << BLUE "v2.data() :";
	for (unsigned i=0; i<v2.size(); ++i)
		std::cout << ' ' << v2[i];
	std::cout << RESET << std::endl;
}

void	testVectorAssign(void)
{
	// std::vector<int>	v1;
	// std::vector<int>	v2;
	// std::vector<int>	v3;
	ft::vector<int>		v4;
	ft::vector<int>		v5;
	ft::vector<int>		v6;

	// v1.assign(7, 100);

	// std::vector<int>::iterator it1;
	// it1 = v1.begin() + 1;
	// v2.assign(it1, v1.end() - 1);

	// int myint1[] = {1776, 7, 4};
	// v3.assign(myint1, myint1 + 3);

	// std::cout << CYAN "v1.data()     :";
	// for (unsigned i=0; i < v1.size(); ++i)
	// 	std::cout << ' ' << v1[i];
	// std::cout << std::endl;
	// std::cout << "v1.size()     : " << v1.size() << std::endl;
	// std::cout << "v1.capacity() : " << v1.capacity() << std::endl;
	// std::cout << RESET << std::endl;

	// std::cout << CYAN "v2.data()     :";
	// for (unsigned i=0; i < v2.size(); ++i)
	// 	std::cout << ' ' << v2[i];
	// std::cout << std::endl;
	// std::cout << "v2.size()     : " << v2.size() << std::endl;
	// std::cout << "v2.capacity() : " << v2.capacity() << std::endl;
	// std::cout << RESET << std::endl;

	// std::cout << CYAN "v3.data()     :";
	// for (unsigned i=0; i < v3.size(); ++i)
	// 	std::cout << ' ' << v3[i];
	// std::cout << std::endl;
	// std::cout << "v3.size()     : " << v3.size() << std::endl;
	// std::cout << "v3.capacity() : " << v3.capacity() << std::endl;
	// std::cout << RESET << std::endl;

	v4.assign(7, 100);

	ft::vector<int>::iterator it2;
	it2 = v4.begin() + 1;
	v5.assign(it2, v4.end() - 1);

	int myint2[] = {1776, 7, 4};
	v6.assign(myint2, myint2 + 3);

	std::cout << BLUE "v4.data()     :";
	for (unsigned i=0; i < v4.size(); ++i)
		std::cout << ' ' << v4[i];
	std::cout << std::endl;
	std::cout << "v4.size()     : " << v4.size() << std::endl;
	std::cout << "v4.capacity() : " << v4.capacity() << std::endl;
	std::cout << RESET << std::endl;

	std::cout << BLUE "v5.data()     :";
	for (unsigned i=0; i < v5.size(); ++i)
		std::cout << ' ' << v5[i];
	std::cout << std::endl;
	std::cout << "v5.size()     : " << v5.size() << std::endl;
	std::cout << "v5.capacity() : " << v5.capacity() << std::endl;
	std::cout << RESET << std::endl;

	std::cout << BLUE "v6.data()     :";
	for (unsigned i=0; i < v6.size(); ++i)
		std::cout << ' ' << v6[i];
	std::cout << std::endl;
	std::cout << "v6.size()     : " << v6.size() << std::endl;
	std::cout << "v6.capacity() : " << v6.capacity() << std::endl;
	std::cout << RESET;
}

void	testVectorPushBack(void)
{
	ft::vector<int>		v1;
	std::vector<int>	v2;

	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(1);
	v1.push_back(2);

	std::cout << CYAN "v1.data()     :";
	for (size_t i = 0; i < v1.size(); i++)
		std::cout << ' ' << v1[i];
	std::cout << std::endl;
	std::cout << "v1.size()     : " << v1.size() << std::endl;
	std::cout << "v1.capacity() : " << v1.capacity() << std::endl;
	std::cout << RESET << std::endl;

	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);
	v2.push_back(1);
	v2.push_back(2);

	std::cout << BLUE "v2.data()     :";
	for (size_t i = 0; i < v2.size(); i++)
		std::cout << ' ' << v2[i];
	std::cout << std::endl;
	std::cout << "v2.size()     : " << v2.size() << std::endl;
	std::cout << "v2.capacity() : " << v2.capacity() << std::endl;
	std::cout << RESET;
}

void	testVectorPopBack(void)
{
	std::vector<int>	v1(10, 50);
	ft::vector<int>		v2(10, 50);

	v1.pop_back();
	v1.pop_back();
	v1.pop_back();
	v1.pop_back();
	v1.pop_back();

	std::cout << CYAN "v1.data()     :";
	for (size_t i = 0; i < v1.size(); i++)
		std::cout << ' ' << v1[i];
	std::cout << std::endl;
	std::cout << "v1.size()     : " << v1.size() << std::endl;
	std::cout << "v1.capacity() : " << v1.capacity() << std::endl;
	std::cout << RESET << std::endl;

	v1.pop_back();
	v1.pop_back();
	v1.pop_back();
	v1.pop_back();
	v1.pop_back();

	std::cout << CYAN "v1.data()     :";
	for (size_t i = 0; i < v1.size(); i++)
		std::cout << ' ' << v1[i];
	std::cout << std::endl;
	std::cout << "v1.size()     : " << v1.size() << std::endl;
	std::cout << "v1.capacity() : " << v1.capacity() << std::endl;
	std::cout << RESET << std::endl;

	v2.pop_back();
	v2.pop_back();
	v2.pop_back();
	v2.pop_back();
	v2.pop_back();

	std::cout << BLUE "v2.data()     :";
	for (size_t i = 0; i < v2.size(); i++)
		std::cout << ' ' << v2[i];
	std::cout << std::endl;
	std::cout << "v2.size()     : " << v2.size() << std::endl;
	std::cout << "v2.capacity() : " << v2.capacity() << std::endl;
	std::cout << RESET << std::endl;

	v2.pop_back();
	v2.pop_back();
	v2.pop_back();
	v2.pop_back();
	v2.pop_back();

	std::cout << BLUE "v2.data()     :";
	for (size_t i = 0; i < v2.size(); i++)
		std::cout << ' ' << v2[i];
	std::cout << std::endl;
	std::cout << "v2.size()     : " << v2.size() << std::endl;
	std::cout << "v2.capacity() : " << v2.capacity() << std::endl;
	std::cout << RESET;
}

void	testVectorSwap(void)
{
	std::vector<int>	v1(3, 50);
	std::vector<int>	v2(5, 100);
	ft::vector<int>		v3(3, 50);
	ft::vector<int>		v4(5, 100);

	v1.push_back(50);
	v1.swap(v2);

	std::cout << CYAN "v1.data()     :";
	for (size_t i = 0; i < v1.size(); i++)
		std::cout << ' ' << v1[i];
	std::cout << std::endl;
	std::cout << "v1.size()     : " << v1.size() << std::endl;
	std::cout << "v1.capacity() : " << v1.capacity() << std::endl;
	std::cout << RESET << std::endl;

	std::cout << CYAN "v2.data()     :";
	for (size_t i = 0; i < v2.size(); i++)
		std::cout << ' ' << v2[i];
	std::cout << std::endl;
	std::cout << "v2.size()     : " << v2.size() << std::endl;
	std::cout << "v2.capacity() : " << v2.capacity() << std::endl;
	std::cout << RESET << std::endl;

	v3.push_back(50);
	// ft::swap(v3, v4);
	v3.swap(v4);

	std::cout << BLUE "v3.data()     :";
	for (size_t i = 0; i < v3.size(); i++)
		std::cout << ' ' << v3[i];
	std::cout << std::endl;
	std::cout << "v3.size()     : " << v3.size() << std::endl;
	std::cout << "v3.capacity() : " << v3.capacity() << std::endl;
	std::cout << RESET << std::endl;

	std::cout << BLUE "v4.data()     :";
	for (size_t i = 0; i < v4.size(); i++)
		std::cout << ' ' << v4[i];
	std::cout << std::endl;
	std::cout << "v4.size()     : " << v4.size() << std::endl;
	std::cout << "v4.capacity() : " << v4.capacity() << std::endl;
	std::cout << RESET;
}

void	testVectorClear(void)
{
	std::vector<int>	v1;
	ft::vector<int>		v2;

	v1.push_back(100);
	v1.push_back(200);
	v1.push_back(300);

	std::cout << CYAN "v1.data()     :";
	for (size_t i = 0; i < v1.size(); i++)
		std::cout << ' ' << v1[i];
	std::cout << std::endl;
	std::cout << "v1.size()     : " << v1.size() << std::endl;
	std::cout << "v1.capacity() : " << v1.capacity() << std::endl;
	std::cout << RESET << std::endl;

	v1.clear();
	v1.push_back(1101);
	v1.push_back(2202);

	std::cout << CYAN "v1.data()     :";
	for (size_t i = 0; i < v1.size(); i++)
		std::cout << ' ' << v1[i];
	std::cout << std::endl;
	std::cout << "v1.size()     : " << v1.size() << std::endl;
	std::cout << "v1.capacity() : " << v1.capacity() << std::endl;
	std::cout << RESET << std::endl;

	v2.push_back(100);
	v2.push_back(200);
	v2.push_back(300);

	std::cout << BLUE "v2.data()     :";
	for (size_t i = 0; i < v2.size(); i++)
		std::cout << ' ' << v2[i];
	std::cout << std::endl;
	std::cout << "v2.size()     : " << v2.size() << std::endl;
	std::cout << "v2.capacity() : " << v2.capacity() << std::endl;
	std::cout << RESET << std::endl;

	v2.clear();
	v2.push_back(1101);
	v2.push_back(2202);

	std::cout << BLUE "v2.data()     :";
	for (size_t i = 0; i < v2.size(); i++)
		std::cout << ' ' << v2[i];
	std::cout << std::endl;
	std::cout << "v2.size()     : " << v2.size() << std::endl;
	std::cout << "v2.capacity() : " << v2.capacity() << std::endl;
	std::cout << RESET;
}

void	testVectorErase(void)
{
	std::vector<int>	v1;
	ft::vector<int>		v2;

	for (int i = 1; i <= 10; ++i)
		v1.push_back(i);

	std::cout << CYAN "v1.data()     :";
	for (size_t i = 0; i < v1.size(); i++)
		std::cout << ' ' << v1[i];
	std::cout << std::endl;
	std::cout << "v1.size()     : " << v1.size() << std::endl;
	std::cout << "v1.capacity() : " << v1.capacity() << std::endl;
	std::cout << RESET << std::endl;

	for (int i = 1; i <= 10; ++i)
		v2.push_back(i);

	std::cout << BLUE "v2.data()     :";
	for (size_t i = 0; i < v2.size(); i++)
		std::cout << ' ' << v2[i];
	std::cout << std::endl;
	std::cout << "v2.size()     : " << v2.size() << std::endl;
	std::cout << "v2.capacity() : " << v2.capacity() << std::endl;
	std::cout << RESET << std::endl;

	v1.erase(v1.begin() + 5);
	v1.erase(v1.begin(), v1.begin() + 3);

	std::cout << CYAN "v1.data()     :";
	for (size_t i = 0; i < v1.size(); i++)
		std::cout << ' ' << v1[i];
	std::cout << std::endl;
	std::cout << "v1.size()     : " << v1.size() << std::endl;
	std::cout << "v1.capacity() : " << v1.capacity() << std::endl;
	std::cout << RESET << std::endl;

	v2.erase(v2.begin() + 5);
	v2.erase(v2.begin(), v2.begin() + 3);

	std::cout << BLUE "v2.data()     :";
	for (size_t i = 0; i < v2.size(); i++)
		std::cout << ' ' << v2[i];
	std::cout << std::endl;
	std::cout << "v2.size()     : " << v2.size() << std::endl;
	std::cout << "v2.capacity() : " << v2.capacity() << std::endl;
	std::cout << RESET;
}

void	testVectorInsert(void)
{
	// std::vector<int>			v1(3, 100);
	// std::vector<int>::iterator	it1;
	ft::vector<int>				v2(3, 100);
	ft::vector<int>::iterator	it2;

	// it1 = v1.begin();
	// it1 = v1.insert(it1, 200);
	// v1.insert(it1, 2, 300);

	// std::vector<int> tempVector1(2, 400);
	// v1.insert(v1.begin() + 2, tempVector1.begin(), tempVector1.end());

	// int	arr1[] = {501, 502, 503};
	// v1.insert(v1.begin(), arr1, arr1 + 3);

	// std::cout << CYAN "v1.data()     :";
	// for (size_t i = 0; i < v1.size(); i++)
	// 	std::cout << ' ' << v1[i];
	// std::cout << std::endl;
	// std::cout << "v1.size()     : " << v1.size() << std::endl;
	// std::cout << "v1.capacity() : " << v1.capacity() << std::endl;
	// std::cout << RESET << std::endl;

	it2 = v2.begin();
	it2 = v2.insert(it2, 200);
	v2.insert(it2, 2, 300);

	std::vector<int>	tempVector2(2, 400);
	v2.insert(v2.begin() + 2, tempVector2.begin(), tempVector2.end());

	int	arr2[] = {501, 502, 503};
	v2.insert(v2.begin(), arr2, arr2 + 3);

	std::cout << BLUE "v2.data()     :";
	for (size_t i = 0; i < v2.size(); i++)
		std::cout << ' ' << v2[i];
	std::cout << std::endl;
	std::cout << "v2.size()     : " << v2.size() << std::endl;
	std::cout << "v2.capacity() : " << v2.capacity() << std::endl;
	std::cout << RESET;
}
