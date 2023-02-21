/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testMap.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:10:12 by jhii              #+#    #+#             */
/*   Updated: 2023/02/21 15:25:04 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <utility>
#include "Map.hpp"

void	testMap(void)
{
	// testMapAll();
}

void	testMapAll(void)
{
	testMapInsertAndErase();
	testMapEqualRange();
	testMapBound();
	testMapCount();
	testMapFind();
	testMapValueComp();
	testMapKeyComp();
	testMapClear();
	testMapSwap();
	testMapAt();
	testMapOperator();
	testMapSize();
	testMapEmpty();
	testMapIterator();
}

void	testMapInsertAndErase(void)
{
	ft::map<char, int> map1;
	std::map<char, int> map2;
	std::cout << std::endl;

	std::cout << YELLOW "[ TESTING ] map.insert()" RESET << std::endl;
	std::cout << BLUE "pair<iterator, bool>\tmap.insert(value_type const &value);" RESET << std::endl;
	ft::pair<ft::map<char, int>::iterator, bool>	res1, res2, res3, res4, res5, res6;
	res1 = map1.insert(ft::make_pair('g', 0));
	res2 = map1.insert(ft::make_pair('o', 1));
	res3 = map1.insert(ft::make_pair('i', 2));
	res4 = map1.insert(ft::make_pair('g', 3));
	res5 = map1.insert(ft::make_pair('p', 4));
	res6 = map1.insert(ft::make_pair('i', 5));

	std::pair<std::map<char, int>::iterator, bool>	res7, res8, res9, res10, res11, res12;
	res7 = map2.insert(std::make_pair('g', 0));
	res8 = map2.insert(std::make_pair('o', 1));
	res9 = map2.insert(std::make_pair('i', 2));
	res10 = map2.insert(std::make_pair('g', 3));
	res11 = map2.insert(std::make_pair('p', 4));
	res12 = map2.insert(std::make_pair('i', 5));

	std::cout << BLACK "ft::map\t\tstd::map" RESET << std::endl;
	std::cout << CYAN "[" << res1.first->first << ", " << res1.first->second << "] = " << res1.second << "\t" << "[" << res7.first->first << ", " << res7.first->second << "] = " << res7.second << RESET << std::endl;
	std::cout << CYAN "[" << res2.first->first << ", " << res2.first->second << "] = " << res2.second << "\t" << "[" << res8.first->first << ", " << res8.first->second << "] = " << res8.second << RESET << std::endl;
	std::cout << CYAN "[" << res3.first->first << ", " << res3.first->second << "] = " << res3.second << "\t" << "[" << res9.first->first << ", " << res9.first->second << "] = " << res9.second << RESET << std::endl;
	std::cout << CYAN "[" << res4.first->first << ", " << res4.first->second << "] = " << res4.second << "\t" << "[" << res10.first->first << ", " << res10.first->second << "] = " << res10.second << RESET << std::endl;
	std::cout << CYAN "[" << res5.first->first << ", " << res5.first->second << "] = " << res5.second << "\t" << "[" << res11.first->first << ", " << res11.first->second << "] = " << res11.second << RESET << std::endl;
	std::cout << CYAN "[" << res6.first->first << ", " << res6.first->second << "] = " << res6.second << "\t" << "[" << res12.first->first << ", " << res12.first->second << "] = " << res12.second << RESET << std::endl;
	std::cout << std::endl;

	std::cout << BLUE "printing elements using iterator ..." RESET << std::endl;
	std::cout << BLACK "ft::map " RESET;
	for (ft::map<char, int>::iterator it = map1.begin(); it != map1.end(); ++it)
		std::cout << CYAN "[" << it->first << ", " << it->second << "] " RESET;
	std::cout << std::endl;
	std::cout << BLACK "std::map " RESET;
	for (std::map<char, int>::iterator it = map2.begin(); it != map2.end(); ++it)
		std::cout << CYAN "[" << it->first << ", " << it->second << "] " RESET;
	std::cout << std::endl << std::endl;

	std::cout << BLUE "size_type\tmap.erase(key_type const &key);" RESET << std::endl;
	std::cout << BLACK "ft::map\t\tstd::map" RESET << std::endl;
	std::cout << CYAN "erase('g') = " << map1.erase('g') << "\terase('g') = " << map2.erase('g') << RESET << std::endl;
	std::cout << CYAN "erase('x') = " << map1.erase('x') << "\terase('x') = " << map2.erase('x') << RESET << std::endl;
	std::cout << CYAN "erase('o') = " << map1.erase('o') << "\terase('o') = " << map2.erase('o') << RESET << std::endl;
	std::cout << CYAN "erase('i') = " << map1.erase('i') << "\terase('i') = " << map2.erase('i') << RESET << std::endl;
	std::cout << CYAN "erase('d') = " << map1.erase('d') << "\terase('d') = " << map2.erase('d') << RESET << std::endl;
	std::cout << CYAN "erase('p') = " << map1.erase('p') << "\terase('p') = " << map2.erase('p') << RESET << std::endl;
	std::cout << std::endl;

	std::cout << BLUE "printing elements using iterator ..." RESET << std::endl;
	std::cout << BLACK "ft::map " RESET;
	for (ft::map<char, int>::iterator it = map1.begin(); it != map1.end(); ++it)
		std::cout << CYAN "[" << it->first << ", " << it->second << "] " RESET;
	std::cout << std::endl;
	std::cout << BLACK "std::map " RESET;
	for (std::map<char, int>::iterator it = map2.begin(); it != map2.end(); ++it)
		std::cout << CYAN "[" << it->first << ", " << it->second << "] " RESET;
	std::cout << std::endl << std::endl;

	ft::map<char, int>::iterator it1 = map1.begin();
	std::map<char, int>::iterator it2 = map2.begin();

	std::cout << BLUE "pair<iterator, bool>\tmap.insert(value_type const &value);" RESET << std::endl;
	ft::map<char, int>::iterator	res13, res14, res15, res16, res17, res18;
	res13 = map1.insert(it1, ft::make_pair('g', 0));
	res14 = map1.insert(it1, ft::make_pair('o', 1));
	res15 = map1.insert(it1, ft::make_pair('i', 2));
	res16 = map1.insert(it1, ft::make_pair('g', 3));
	res17 = map1.insert(it1, ft::make_pair('p', 4));
	res18 = map1.insert(it1, ft::make_pair('i', 5));

	std::map<char, int>::iterator	res19, res20, res21, res22, res23, res24;
	res19 = map2.insert(it2, std::make_pair('g', 0));
	res20 = map2.insert(it2, std::make_pair('o', 1));
	res21 = map2.insert(it2, std::make_pair('i', 2));
	res22 = map2.insert(it2, std::make_pair('g', 3));
	res23 = map2.insert(it2, std::make_pair('p', 4));
	res24 = map2.insert(it2, std::make_pair('i', 5));

	std::cout << BLACK "ft::map\t\tstd::map" RESET << std::endl;
	std::cout << CYAN "[" << res13->first << ", " << res13->second << "]" << "\t\t" << "[" << res19->first << ", " << res19->second << "]" << RESET << std::endl;
	std::cout << CYAN "[" << res14->first << ", " << res14->second << "]" << "\t\t" << "[" << res20->first << ", " << res20->second << "]" << RESET << std::endl;
	std::cout << CYAN "[" << res15->first << ", " << res15->second << "]" << "\t\t" << "[" << res21->first << ", " << res21->second << "]" << RESET << std::endl;
	std::cout << CYAN "[" << res16->first << ", " << res16->second << "]" << "\t\t" << "[" << res22->first << ", " << res22->second << "]" << RESET << std::endl;
	std::cout << CYAN "[" << res17->first << ", " << res17->second << "]" << "\t\t" << "[" << res23->first << ", " << res23->second << "]" << RESET << std::endl;
	std::cout << CYAN "[" << res18->first << ", " << res18->second << "]" << "\t\t" << "[" << res24->first << ", " << res24->second << "]" << RESET << std::endl;
	std::cout << std::endl;

	std::cout << BLUE "printing elements using iterator ..." RESET << std::endl;
	std::cout << BLACK "ft::map " RESET;
	for (ft::map<char, int>::iterator it = map1.begin(); it != map1.end(); ++it)
		std::cout << CYAN "[" << it->first << ", " << it->second << "] " RESET;
	std::cout << std::endl;
	std::cout << BLACK "std::map " RESET;
	for (std::map<char, int>::iterator it = map2.begin(); it != map2.end(); ++it)
		std::cout << CYAN "[" << it->first << ", " << it->second << "] " RESET;
	std::cout << std::endl << std::endl;

	std::cout << BLUE "void\tmap.erase(iterator position);" RESET << std::endl;
	std::cout << CYAN "erase(map.find('o'));" RESET << std::endl;
	std::cout << CYAN "erase(map.find('i'));" RESET << std::endl;
	std::cout << std::endl;

	it1 = map1.find('o');
	map1.erase(it1);
	it1 = map1.find('i');
	map1.erase(it1);
	it2 = map2.find('o');
	map2.erase(it2);
	it2 = map2.find('i');
	map2.erase(it2);

	std::cout << BLUE "printing elements using iterator ..." RESET << std::endl;
	std::cout << BLACK "ft::map " RESET;
	for (ft::map<char, int>::iterator it = map1.begin(); it != map1.end(); ++it)
		std::cout << CYAN "[" << it->first << ", " << it->second << "] " RESET;
	std::cout << std::endl;
	std::cout << BLACK "std::map " RESET;
	for (std::map<char, int>::iterator it = map2.begin(); it != map2.end(); ++it)
		std::cout << CYAN "[" << it->first << ", " << it->second << "] " RESET;
	std::cout << std::endl << std::endl;

	std::cout << BLUE "template <class InputIterator>\nvoid\tmap.insert(InputIterator first, InputIterator last);" RESET << std::endl;
	std::cout << CYAN "anothermap1.insert(map1.begin(),map1.find('z'));" RESET << std::endl;
	std::cout << CYAN "anothermap2.insert(map2.begin(),map2.find('z'));" RESET << std::endl;
	ft::map<char, int>	anothermap1;
	anothermap1.insert(map1.begin(),map1.find('z'));
	std::map<char, int>	anothermap2;
	anothermap2.insert(map2.begin(),map2.find('z'));
	std::cout << std::endl;

	std::cout << BLUE "printing elements using iterator ..." RESET << std::endl;
	std::cout << BLACK "ft::map (1) " RESET;
	for (ft::map<char, int>::iterator it = map1.begin(); it != map1.end(); ++it)
		std::cout << CYAN "[" << it->first << ", " << it->second << "] " RESET;
	std::cout << std::endl;
	std::cout << BLACK "ft::map (2) " RESET;
	for (ft::map<char, int>::iterator it = anothermap1.begin(); it != anothermap1.end(); ++it)
		std::cout << CYAN "[" << it->first << ", " << it->second << "] " RESET;
	std::cout << std::endl << std::endl;

	std::cout << BLUE "printing elements using iterator ..." RESET << std::endl;
	std::cout << BLACK "std::map (1) " RESET;
	for (std::map<char, int>::iterator it = map2.begin(); it != map2.end(); ++it)
		std::cout << CYAN "[" << it->first << ", " << it->second << "] " RESET;
	std::cout << std::endl;
	std::cout << BLACK "std::map (2) " RESET;
	for (std::map<char, int>::iterator it = anothermap2.begin(); it != anothermap2.end(); ++it)
		std::cout << CYAN "[" << it->first << ", " << it->second << "] " RESET;
	std::cout << std::endl << std::endl;

	std::cout << BLUE "void\tmap.erase(iterator first, iterator last);" RESET << std::endl;
	std::cout << CYAN "map1.erase(map1.begin(), map1.end());" RESET << std::endl;
	std::cout << CYAN "map2.erase(map2.begin(), map2.end());" RESET << std::endl;
	map1.erase(map1.begin(), map1.end());
	map2.erase(map2.begin(), map2.end());
	std::cout << std::endl;

	std::cout << BLUE "printing elements using iterator ..." RESET << std::endl;
	std::cout << BLACK "ft::map " RESET;
	for (ft::map<char, int>::iterator it = map1.begin(); it != map1.end(); ++it)
		std::cout << CYAN "[" << it->first << ", " << it->second << "] " RESET;
	std::cout << std::endl;
	std::cout << BLACK "std::map " RESET;
	for (std::map<char, int>::iterator it = map2.begin(); it != map2.end(); ++it)
		std::cout << CYAN "[" << it->first << ", " << it->second << "] " RESET;
	std::cout << std::endl << std::endl;
}

void	testMapEqualRange(void)
{
	ft::map<char, int> map1;
	std::map<char, int> map2;
	std::cout << std::endl;

	std::cout << YELLOW "[ TESTING ] map.equal_range()" RESET << std::endl;
	std::cout << BLUE "inserting elements into ft::map ..." RESET << std::endl;
	map1['a'] = 20;
	map1['b'] = 40;
	map1['c'] = 60;
	map1['d'] = 80;
	map1['e'] = 100;

	std::cout << BLUE "inserting elements into std::map ..." RESET << std::endl;
	map2['a'] = 20;
	map2['b'] = 40;
	map2['c'] = 60;
	map2['d'] = 80;
	map2['e'] = 100;
	std::cout << std::endl;

	ft::pair<ft::map<char, int>::iterator, ft::map<char, int>::iterator>	pair1;
	std::pair<std::map<char, int>::iterator, std::map<char, int>::iterator>	pair2;

	std::cout << BLUE "calling equal_range() on ft::map ..." RESET << std::endl;
	pair1 = map1.equal_range('b');

	std::cout << BLUE "calling equal_range() on std::map ..." RESET << std::endl;
	pair2 = map2.equal_range('b');
	std::cout << std::endl;

	std::cout << BLUE "printing lower and upper bound from equal_range() ..." RESET << std::endl;
	std::cout << BLACK "ft::map lower_bound() " RESET;
	std::cout << CYAN "[" << pair1.first->first << ", " << pair1.first->second << "] " RESET << std::endl;
	std::cout << BLACK "ft::map upper_bound() " RESET;
	std::cout << CYAN "[" << pair1.second->first << ", " << pair1.second->second << "] " RESET << std::endl;

	std::cout << BLACK "std::map lower_bound() " RESET;
	std::cout << CYAN "[" << pair2.first->first << ", " << pair2.first->second << "] " RESET << std::endl;
	std::cout << BLACK "std::map upper_bound() " RESET;
	std::cout << CYAN "[" << pair2.second->first << ", " << pair2.second->second << "] " RESET << std::endl;
	std::cout << std::endl;
}

void	testMapBound(void)
{
	ft::map<char, int>	map1;
	std::map<char, int>	map2;
	std::cout << std::endl;

	std::cout << YELLOW "[ TESTING ] map.lower_bound() && map.upper_bound()" RESET << std::endl;
	std::cout << BLUE "inserting elements into ft::map ..." RESET << std::endl;
	map1['a'] = 20;
	map1['b'] = 40;
	map1['c'] = 60;
	map1['d'] = 80;
	map1['e'] = 100;

	std::cout << BLUE "inserting elements into std::map ..." RESET << std::endl;
	map2['a'] = 20;
	map2['b'] = 40;
	map2['c'] = 60;
	map2['d'] = 80;
	map2['e'] = 100;
	std::cout << std::endl;

	ft::map<char, int>::iterator	itlow1;
	ft::map<char, int>::iterator	itup1;
	std::map<char, int>::iterator	itlow2;
	std::map<char, int>::iterator	itup2;

	std::cout << BLUE "calling lower_bound() on ft::map ..." RESET << std::endl;
	std::cout << BLUE "calling upper_bound() on ft::map ..." RESET << std::endl;
	itlow1 = map1.lower_bound ('b');
	itup1 = map1.upper_bound ('d');
	std::cout << std::endl;

	std::cout << BLUE "calling lower_bound() on std::map ..." RESET << std::endl;
	std::cout << BLUE "calling upper_bound() on std::map ..." RESET << std::endl;
	itlow2 = map2.lower_bound ('b');
	itup2 = map2.upper_bound ('d');
	std::cout << std::endl;

	std::cout << BLUE "erasing lower and upper bound on ft::map ..." RESET << std::endl;
	std::cout << BLUE "erasing lower and upper bound on std::map ..." RESET << std::endl;
	map1.erase(itlow1,itup1);
	map2.erase(itlow2,itup2);
	std::cout << std::endl;

	std::cout << BLUE "printing elements using iterator ..." RESET << std::endl;
	std::cout << BLACK "ft::map " RESET;
	for (ft::map<char, int>::iterator it = map1.begin(); it != map1.end(); ++it)
		std::cout << CYAN "[" << it->first << ", " << it->second << "] " RESET;
	std::cout << std::endl;

	std::cout << BLACK "std::map " RESET;
	for (std::map<char, int>::iterator it = map2.begin(); it != map2.end(); ++it)
		std::cout << CYAN "[" << it->first << ", " << it->second << "] " RESET;
	std::cout << std::endl << std::endl;
}

void	testMapCount(void)
{
	ft::map<int, std::string>	map1;
	std::map<int, std::string>	map2;
	std::cout << std::endl;

	std::cout << YELLOW "[ TESTING ] map.find()" RESET << std::endl;
	std::cout << BLUE "inserting elements into ft::map ..." RESET << std::endl;
	map1[9] = "alpaca";
	map1[4] = "bear";
	map1[8] = "cat";
	map1[3] = "dog";
	map1[7] = "elephant";
	map1[2] = "fish";
	map1[6] = "goat";
	map1[1] = "hare";
	map1[5] = "igloo";
	map1[0] = "jaguar";

	std::cout << BLUE "inserting elements into std::map ..." RESET << std::endl;
	map2[9] = "alpaca";
	map2[4] = "bear";
	map2[8] = "cat";
	map2[3] = "dog";
	map2[7] = "elephant";
	map2[2] = "fish";
	map2[6] = "goat";
	map2[1] = "hare";
	map2[5] = "igloo";
	map2[0] = "jaguar";
	std::cout << std::endl;

	std::cout << BLUE "printing elements based on count() ..." RESET << std::endl;
	for (int i = 5; i < 15; ++i)
	{
		std::cout << BLACK "ft::map " RESET;
		std::cout << CYAN << i << RESET;
		if (map1.count(i) > 0)
			std::cout << GREEN " is an element." RESET << std::endl;
		else 
			std::cout << RED " is not an element." RESET << std::endl;
	}

	for (int i = 5; i < 15; ++i)
	{
		std::cout << BLACK "std::map " RESET;
		std::cout << CYAN << i << RESET;
		if (map2.count(i) > 0)
			std::cout << GREEN " is an element." RESET << std::endl;
		else 
			std::cout << RED " is not an element." RESET << std::endl;
	}
	std::cout << std::endl;
}

void	testMapFind(void)
{
	ft::map<int, std::string>	map1;
	std::map<int, std::string>	map2;
	std::cout << std::endl;

	std::cout << YELLOW "[ TESTING ] map.find()" RESET << std::endl;
	std::cout << BLUE "inserting elements into ft::map ..." RESET << std::endl;
	map1[9] = "alpaca";
	map1[4] = "bear";
	map1[8] = "cat";
	map1[3] = "dog";
	map1[7] = "elephant";
	map1[2] = "fish";
	map1[6] = "goat";
	map1[1] = "hare";
	map1[5] = "igloo";
	map1[0] = "jaguar";

	std::cout << BLUE "inserting elements into std::map ..." RESET << std::endl;
	map2[9] = "alpaca";
	map2[4] = "bear";
	map2[8] = "cat";
	map2[3] = "dog";
	map2[7] = "elephant";
	map2[2] = "fish";
	map2[6] = "goat";
	map2[1] = "hare";
	map2[5] = "igloo";
	map2[0] = "jaguar";
	std::cout << std::endl;

	ft::map<int, std::string>::iterator		it1 = map1.find(6);
	if (it1 != map1.end())
		map1.erase(it1);

	std::map<int, std::string>::iterator	it2 = map2.find(6);
	if (it2 != map2.end())
		map2.erase(it2);

	std::cout << BLUE "printing elements using find() ..." RESET << std::endl;
	std::cout << BLACK "ft::map " RESET;
	for (int i = 0; i < 10; ++i)
	{
		if (i != 6)
			std::cout << CYAN "[" << i << ", " << map1.find(i)->second << "] " RESET;
	}
	std::cout << std::endl;

	std::cout << BLACK "std::map " RESET;
	for (int i = 0; i < 10; ++i)
	{
		if (i != 6)
			std::cout << CYAN "[" << i << ", " << map2.find(i)->second << "] " RESET;
	}
	std::cout << std::endl << std::endl;
}

void	testMapValueComp(void)
{
	ft::map<char, int>	map1;
	std::map<char, int>	map2;
	std::cout << std::endl;

	std::cout << YELLOW "[ TESTING ] map.value_comp()" RESET << std::endl;
	std::cout << BLUE "inserting elements into ft::map ..." RESET << std::endl;
	map1['x'] = 1001;
	map1['y'] = 2002;
	map1['z'] = 3003;

	std::cout << BLUE "inserting elements into std::map ..." RESET << std::endl;
	map2['x'] = 1001;
	map2['y'] = 2002;
	map2['z'] = 3003;
	std::cout << std::endl;

	ft::pair<char, int>		highest1 = *map1.rbegin();
	std::pair<char, int>	highest2 = *map2.rbegin();

	std::cout << BLUE "comparing keys using key_compare ..." RESET << std::endl;
	ft::map<char, int>::iterator it1 = map1.begin();
	std::map<char, int>::iterator it2 = map2.begin();

	std::cout << BLACK "ft::map " RESET;
	do	{
		std::cout << CYAN "[" << it1->first << ", " << it1->second << "] " RESET;
	} while (map1.value_comp()(*it1++, highest1));
	std::cout << std::endl;

	std::cout << BLACK "std::map " RESET;
	do	{
		std::cout << CYAN "[" << it2->first << ", " << it2->second << "] " RESET;
	} while (map2.value_comp()(*it2++, highest2));
	std::cout << std::endl << std::endl;
}

void	testMapKeyComp(void)
{
	ft::map<char, int>	map1;
	std::map<char, int>	map2;
	std::cout << std::endl;

	std::cout << YELLOW "[ TESTING ] map.key_comp()" RESET << std::endl;
	ft::map<char, int>::key_compare		comp1 = map1.key_comp();
	std::map<char, int>::key_compare	comp2 = map2.key_comp();

	std::cout << BLUE "inserting elements into ft::map ..." RESET << std::endl;
	map1['a'] = 100;
	map1['b'] = 200;
	map1['c'] = 300;

	std::cout << BLUE "inserting elements into std::map ..." RESET << std::endl;
	map2['a'] = 100;
	map2['b'] = 200;
	map2['c'] = 300;
	std::cout << std::endl;

	char	highest1 = map1.rbegin()->first;
	char	highest2 = map2.rbegin()->first;

	std::cout << BLUE "comparing keys using key_compare ..." RESET << std::endl;
	ft::map<char, int>::iterator it1 = map1.begin();
	std::map<char, int>::iterator it2 = map2.begin();

	std::cout << BLACK "ft::map " RESET;
	do	{
		std::cout << CYAN "[" << it1->first << ", " << it1->second << "] " RESET;
	} while ( comp1((*it1++).first, highest1));
	std::cout << std::endl;

	std::cout << BLACK "std::map " RESET;
	do	{
		std::cout << CYAN "[" << it2->first << ", " << it2->second << "] " RESET;
	} while ( comp2((*it2++).first, highest2));
	std::cout << std::endl << std::endl;
}

void	testMapClear(void)
{
	ft::map<int, std::string>	map1;
	std::map<int, std::string>	map2;
	std::cout << std::endl;

	std::cout << YELLOW "[ TESTING ] map.clear()" RESET << std::endl;
	std::cout << BLUE "inserting elements into ft::map ..." RESET << std::endl;
	map1[9] = "alpaca";
	map1[4] = "bear";
	map1[8] = "cat";
	map1[3] = "dog";
	map1[7] = "elephant";
	map1[2] = "fish";
	map1[6] = "goat";
	map1[1] = "hare";
	map1[5] = "igloo";
	map1[0] = "jaguar";

	std::cout << BLUE "inserting elements into std::map ..." RESET << std::endl;
	map2[9] = "alpaca";
	map2[4] = "bear";
	map2[8] = "cat";
	map2[3] = "dog";
	map2[7] = "elephant";
	map2[2] = "fish";
	map2[6] = "goat";
	map2[1] = "hare";
	map2[5] = "igloo";
	map2[0] = "jaguar";
	std::cout << std::endl;

	ft::map<int, std::string>::iterator		it1 = map1.begin();
	ft::map<int, std::string>::iterator		it2 = map1.end();
	std::map<int, std::string>::iterator	it3 = map2.begin();
	std::map<int, std::string>::iterator	it4 = map2.end();

	std::cout << BLUE "printing elements using iterator ..." RESET << std::endl;
	std::cout << BLACK "ft::map " RESET;
	while (it1 != it2)
	{
		std::cout << CYAN "[" << it1->first << ", " << it1->second << "] " RESET;
		++it1;
	}
	std::cout << std::endl;

	std::cout << BLACK "std::map " RESET;
	while (it3 != it4)
	{
		std::cout << CYAN "[" << it3->first << ", " << it3->second << "] " RESET;
		++it3;
	}
	std::cout << std::endl << std::endl;

	std::cout << BLUE "calling size() for maps ..." RESET << std::endl;
	std::cout << BLACK "ft::map " CYAN "size() = " << map1.size() << RESET << std::endl;
	std::cout << BLACK "std::map " CYAN "size() = " << map2.size() << RESET << std::endl;
	std::cout << std::endl;

	std::cout << BLUE "calling clear() on ft::map ..." RESET << std::endl;
	map1.clear();
	std::cout << BLUE "calling clear() on std::map ..." RESET << std::endl;
	map2.clear();
	std::cout << std::endl;

	std::cout << BLUE "calling size() for maps ..." RESET << std::endl;
	std::cout << BLACK "ft::map " CYAN "size() = " << map1.size() << RESET << std::endl;
	std::cout << BLACK "std::map " CYAN "size() = " << map2.size() << RESET << std::endl;
	std::cout << std::endl;
}

void	testMapSwap(void)
{
	ft::map<int, std::string>	map1;
	ft::map<int, std::string>	map2;
	std::map<int, std::string>	map3;
	std::map<int, std::string>	map4;
	std::cout << std::endl;

	std::cout << YELLOW "[ TESTING ] map.swap()" RESET << std::endl;
	std::cout << BLUE "inserting elements into ft::map (1) ..." RESET << std::endl;
	map1.insert(ft::make_pair(9, "alpaca"));
	map1.insert(ft::make_pair(4, "bear"));
	map1.insert(ft::make_pair(8, "cat"));

	std::cout << BLUE "inserting elements into ft::map (2) ..." RESET << std::endl;
	map2.insert(ft::make_pair(2, "fish"));
	map2.insert(ft::make_pair(6, "goat"));
	map2.insert(ft::make_pair(1, "hare"));
	map2.insert(ft::make_pair(5, "igloo"));
	map2.insert(ft::make_pair(0, "jaguar"));

	std::cout << BLUE "inserting elements into std::map (1) ..." RESET << std::endl;
	map3.insert(std::make_pair(9, "alpaca"));
	map3.insert(std::make_pair(4, "bear"));
	map3.insert(std::make_pair(8, "cat"));

	std::cout << BLUE "inserting elements into std::map (2) ..." RESET << std::endl;
	map4.insert(std::make_pair(2, "fish"));
	map4.insert(std::make_pair(6, "goat"));
	map4.insert(std::make_pair(1, "hare"));
	map4.insert(std::make_pair(5, "igloo"));
	map4.insert(std::make_pair(0, "jaguar"));
	std::cout << std::endl;


	ft::map<int, std::string>::iterator		it1 = map1.begin();
	ft::map<int, std::string>::iterator		it2 = map1.end();
	ft::map<int, std::string>::iterator		it3 = map2.begin();
	ft::map<int, std::string>::iterator		it4 = map2.end();

	std::map<int, std::string>::iterator	it5 = map3.begin();
	std::map<int, std::string>::iterator	it6 = map3.end();
	std::map<int, std::string>::iterator	it7 = map4.begin();
	std::map<int, std::string>::iterator	it8 = map4.end();

	std::cout << BLUE "printing elements BEFORE swap() ..." RESET << std::endl;
	std::cout << BLACK "ft::map (1) " RESET;
	while (it1 != it2)
	{
		std::cout << CYAN "[" << it1->first << ", " << it1->second << "] " RESET;
		++it1;
	}
	std::cout << std::endl;

	std::cout << BLACK "ft::map (2) " RESET;
	while (it3 != it4)
	{
		std::cout << CYAN "[" << it3->first << ", " << it3->second << "] " RESET;
		++it3;
	}
	std::cout << std::endl;
	std::cout << BLACK "ft::map (1) " CYAN "size() = " << map1.size() << RESET << std::endl;
	std::cout << BLACK "ft::map (2) " CYAN "size() = " << map2.size() << RESET << std::endl;
	std::cout << std::endl;

	std::cout << BLACK "std::map (1) " RESET;
	while (it5 != it6)
	{
		std::cout << CYAN "[" << it5->first << ", " << it5->second << "] " RESET;
		++it5;
	}
	std::cout << std::endl;

	std::cout << BLACK "std::map (2) " RESET;
	while (it7 != it8)
	{
		std::cout << CYAN "[" << it7->first << ", " << it7->second << "] " RESET;
		++it7;
	}
	std::cout << std::endl;
	std::cout << BLACK "std::map (1) " CYAN "size() = " << map3.size() << RESET << std::endl;
	std::cout << BLACK "std::map (2) " CYAN "size() = " << map4.size() << RESET << std::endl;
	std::cout << std::endl;

	std::cout << BLUE "swaping elements between ft::map (1) and (2) ..." RESET << std::endl;
	map1.swap(map2);

	std::cout << BLUE "swaping elements between std::map (1) and (2) ..." RESET << std::endl;
	map3.swap(map4);
	std::cout << std::endl;

	ft::map<int, std::string>::iterator		it9 = map1.begin();
	ft::map<int, std::string>::iterator		it10 = map1.end();
	ft::map<int, std::string>::iterator		it11 = map2.begin();
	ft::map<int, std::string>::iterator		it12 = map2.end();

	std::map<int, std::string>::iterator	it13 = map3.begin();
	std::map<int, std::string>::iterator	it14 = map3.end();
	std::map<int, std::string>::iterator	it15 = map4.begin();
	std::map<int, std::string>::iterator	it16 = map4.end();

	std::cout << BLUE "printing elements AFTER swap() ..." RESET << std::endl;
	std::cout << BLACK "ft::map (1) " RESET;
	while (it9 != it10)
	{
		std::cout << CYAN "[" << it9->first << ", " << it9->second << "] " RESET;
		++it9;
	}
	std::cout << std::endl;

	std::cout << BLACK "ft::map (2) " RESET;
	while (it11 != it12)
	{
		std::cout << CYAN "[" << it11->first << ", " << it11->second << "] " RESET;
		++it11;
	}
	std::cout << std::endl;
	std::cout << BLACK "ft::map (1) " CYAN "size() = " << map1.size() << RESET << std::endl;
	std::cout << BLACK "ft::map (2) " CYAN "size() = " << map2.size() << RESET << std::endl;
	std::cout << std::endl;

	std::cout << BLACK "std::map (1) " RESET;
	while (it13 != it14)
	{
		std::cout << CYAN "[" << it13->first << ", " << it13->second << "] " RESET;
		++it13;
	}
	std::cout << std::endl;

	std::cout << BLACK "std::map (2) " RESET;
	while (it15 != it16)
	{
		std::cout << CYAN "[" << it15->first << ", " << it15->second << "] " RESET;
		++it15;
	}
	std::cout << std::endl;
	std::cout << BLACK "std::map (1) " CYAN "size() = " << map3.size() << RESET << std::endl;
	std::cout << BLACK "std::map (2) " CYAN "size() = " << map4.size() << RESET << std::endl;
	std::cout << std::endl;
}

void	testMapAt(void)
{
	ft::map<int, std::string>	map1;
	std::map<int, std::string>	map2;
	std::cout << std::endl;

	std::cout << YELLOW "[ TESTING ] map.at()" RESET << std::endl;
	std::cout << BLUE "inserting elements into ft::map ..." RESET << std::endl;
	map1.insert(ft::make_pair(9, "alpaca"));
	map1.insert(ft::make_pair(4, "bear"));
	map1.insert(ft::make_pair(8, "cat"));
	map1.insert(ft::make_pair(3, "dog"));
	map1.insert(ft::make_pair(7, "elephant"));
	map1.insert(ft::make_pair(2, "fish"));
	map1.insert(ft::make_pair(6, "goat"));
	map1.insert(ft::make_pair(1, "hare"));
	map1.insert(ft::make_pair(5, "igloo"));
	map1.insert(ft::make_pair(0, "jaguar"));

	std::cout << BLUE "inserting elements into std::map ..." RESET << std::endl;
	map2.insert(std::make_pair(9, "alpaca"));
	map2.insert(std::make_pair(4, "bear"));
	map2.insert(std::make_pair(8, "cat"));
	map2.insert(std::make_pair(3, "dog"));
	map2.insert(std::make_pair(7, "elephant"));
	map2.insert(std::make_pair(2, "fish"));
	map2.insert(std::make_pair(6, "goat"));
	map2.insert(std::make_pair(1, "hare"));
	map2.insert(std::make_pair(5, "igloo"));
	map2.insert(std::make_pair(0, "jaguar"));
	std::cout << std::endl;

	std::cout << BLUE "printing elements using at() ..." RESET << std::endl;
	std::cout << BLACK "ft::map " RESET;
	for (int i = 0; i < 10; ++i)
		std::cout << CYAN "[" << i << ", " << map1.at(i) << "] " RESET;
	std::cout << std::endl;

	std::cout << BLACK "std::map " RESET;
	for (int i = 0; i < 10; ++i)
		std::cout << CYAN "[" << i << ", " << map2.at(i) << "] " RESET;
	std::cout << std::endl << std::endl;

	std::cout << BLUE "replacing elements in ft::map with at() ..." RESET << std::endl;
	map1.at(4) = "four";
	map1.at(3) = "three";
	map1.at(2) = "two";
	map1.at(1) = "one";
	map1.at(0) = "zero";

	std::cout << BLUE "replacing elements in std::map with at() ..." RESET << std::endl;
	map2.at(4) = "four";
	map2.at(3) = "three";
	map2.at(2) = "two";
	map2.at(1) = "one";
	map2.at(0) = "zero";
	std::cout << std::endl;

	std::cout << BLUE "printing elements using at() ..." RESET << std::endl;
	std::cout << BLACK "ft::map " RESET;
	for (int i = 0; i < 10; ++i)
		std::cout << CYAN "[" << i << ", " << map1[i] << "] " RESET;
	std::cout << std::endl;

	std::cout << BLACK "std::map " RESET;
	for (int i = 0; i < 10; ++i)
		std::cout << CYAN "[" << i << ", " << map2[i] << "] " RESET;
	std::cout << std::endl << std::endl;
}

void	testMapOperator(void)
{
	ft::map<int, std::string>	map1;
	std::map<int, std::string>	map2;
	std::cout << std::endl;

	std::cout << YELLOW "[ TESTING ] map::operator[]" RESET << std::endl;
	std::cout << BLUE "inserting elements into ft::map ..." RESET << std::endl;
	map1.insert(ft::make_pair(9, "alpaca"));
	map1.insert(ft::make_pair(4, "bear"));
	map1.insert(ft::make_pair(8, "cat"));
	map1.insert(ft::make_pair(3, "dog"));
	map1.insert(ft::make_pair(7, "elephant"));
	map1.insert(ft::make_pair(2, "fish"));
	map1.insert(ft::make_pair(6, "goat"));
	map1.insert(ft::make_pair(1, "hare"));
	map1.insert(ft::make_pair(5, "igloo"));
	map1.insert(ft::make_pair(0, "jaguar"));

	std::cout << BLUE "inserting elements into std::map ..." RESET << std::endl;
	map2.insert(std::make_pair(9, "alpaca"));
	map2.insert(std::make_pair(4, "bear"));
	map2.insert(std::make_pair(8, "cat"));
	map2.insert(std::make_pair(3, "dog"));
	map2.insert(std::make_pair(7, "elephant"));
	map2.insert(std::make_pair(2, "fish"));
	map2.insert(std::make_pair(6, "goat"));
	map2.insert(std::make_pair(1, "hare"));
	map2.insert(std::make_pair(5, "igloo"));
	map2.insert(std::make_pair(0, "jaguar"));
	std::cout << std::endl;

	std::cout << BLUE "printing elements using operator[] ..." RESET << std::endl;
	std::cout << BLACK "ft::map " RESET;
	for (int i = 0; i < 10; ++i)
		std::cout << CYAN "[" << i << ", " << map1[i] << "] " RESET;
	std::cout << std::endl;

	std::cout << BLACK "std::map " RESET;
	for (int i = 0; i < 10; ++i)
		std::cout << CYAN "[" << i << ", " << map2[i] << "] " RESET;
	std::cout << std::endl << std::endl;

	std::cout << BLUE "replacing elements in ft::map with operator[] ..." RESET << std::endl;
	map1[4] = "four";
	map1[3] = "three";
	map1[2] = "two";
	map1[1] = "one";
	map1[0] = "zero";

	std::cout << BLUE "replacing elements in std::map with operator[] ..." RESET << std::endl;
	map2[4] = "four";
	map2[3] = "three";
	map2[2] = "two";
	map2[1] = "one";
	map2[0] = "zero";
	std::cout << std::endl;

	std::cout << BLUE "printing elements using operator[] ..." RESET << std::endl;
	std::cout << BLACK "ft::map " RESET;
	for (int i = 0; i < 10; ++i)
		std::cout << CYAN "[" << i << ", " << map1[i] << "] " RESET;
	std::cout << std::endl;

	std::cout << BLACK "std::map " RESET;
	for (int i = 0; i < 10; ++i)
		std::cout << CYAN "[" << i << ", " << map2[i] << "] " RESET;
	std::cout << std::endl << std::endl;

	std::cout << BLUE "using ft::map::operator[] without initializing a pair ..." RESET << std::endl;
	map1[10];
	map1[11];
	map1[12];

	std::cout << BLUE "using ft::map::operator[] without initializing a pair ..." RESET << std::endl;
	map2[10];
	map2[11];
	map2[12];
	std::cout << std::endl;

	std::cout << BLUE "printing elements using operator[] ..." RESET << std::endl;
	std::cout << BLACK "ft::map " RESET;
	for (int i = 0; i < 13; ++i)
		std::cout << CYAN "[" << i << ", " << map1[i] << "] " RESET;
	std::cout << std::endl;

	std::cout << BLACK "std::map " RESET;
	for (int i = 0; i < 13; ++i)
		std::cout << CYAN "[" << i << ", " << map2[i] << "] " RESET;
	std::cout << std::endl << std::endl;
}

void	testMapSize(void)
{
	ft::map<int, std::string>	map1;
	std::map<int, std::string>	map2;
	std::cout << std::endl;

	std::cout << YELLOW "[ TESTING ] map.size()" RESET << std::endl;
	std::cout << BLACK "ft::map " CYAN "size() = " << map1.size() << RESET << std::endl;
	std::cout << BLACK "std::map " CYAN "size() = " << map2.size() << RESET << std::endl;
	std::cout << std::endl;

	std::cout << BLUE "inserting elements into ft::map ..." RESET << std::endl;
	map1.insert(ft::make_pair(9, "alpaca"));
	map1.insert(ft::make_pair(4, "bear"));
	map1.insert(ft::make_pair(8, "cat"));
	map1.insert(ft::make_pair(3, "dog"));
	map1.insert(ft::make_pair(7, "elephant"));
	map1.insert(ft::make_pair(2, "fish"));
	map1.insert(ft::make_pair(6, "goat"));
	map1.insert(ft::make_pair(1, "hare"));
	map1.insert(ft::make_pair(5, "igloo"));
	map1.insert(ft::make_pair(0, "jaguar"));

	std::cout << BLUE "inserting elements into std::map ..." RESET << std::endl;
	map2.insert(std::make_pair(9, "alpaca"));
	map2.insert(std::make_pair(4, "bear"));
	map2.insert(std::make_pair(8, "cat"));
	map2.insert(std::make_pair(3, "dog"));
	map2.insert(std::make_pair(7, "elephant"));
	map2.insert(std::make_pair(2, "fish"));
	map2.insert(std::make_pair(6, "goat"));
	map2.insert(std::make_pair(1, "hare"));
	map2.insert(std::make_pair(5, "igloo"));
	map2.insert(std::make_pair(0, "jaguar"));
	std::cout << std::endl;

	std::cout << BLACK "ft::map " CYAN "size() = " << map1.size() << RESET << std::endl;
	std::cout << BLACK "std::map " CYAN "size() = " << map2.size() << RESET << std::endl;
	std::cout << std::endl;

	std::cout << BLUE "erasing elements from ft::map ..." RESET << std::endl;
	map1.erase(9);
	map1.erase(4);
	map1.erase(8);
	map1.erase(3);
	map1.erase(7);

	std::cout << BLUE "erasing elements from std::map ..." RESET << std::endl;
	map2.erase(9);
	map2.erase(4);
	map2.erase(8);
	map2.erase(3);
	map2.erase(7);
	std::cout << std::endl;

	std::cout << BLACK "ft::map " CYAN "size() = " << map1.size() << RESET << std::endl;
	std::cout << BLACK "std::map " CYAN "size() = " << map2.size() << RESET << std::endl;
	std::cout << std::endl;

	std::cout << BLACK "ft::map " CYAN "max_size() = " << map1.max_size() << RESET << std::endl;
	std::cout << BLACK "std::map " CYAN "max_size() = " << map2.max_size() << RESET << std::endl;
	std::cout << std::endl;
}

void	testMapEmpty(void)
{
	ft::map<int, std::string>	map1;
	std::map<int, std::string>	map2;
	std::cout << std::endl;

	std::cout << YELLOW "[ TESTING ] map.empty()" RESET << std::endl;
	std::cout << BLACK "ft::map " CYAN "empty() = " RESET;
	if (map1.empty())
		std::cout << CYAN "true" RESET << std::endl;
	else
		std::cout << CYAN "false" RESET << std::endl;

	std::cout << BLACK "std::map " CYAN "empty() = " RESET;
	if (map2.empty())
		std::cout << CYAN "true" RESET << std::endl;
	else
		std::cout << CYAN "false" RESET << std::endl;
	std::cout << std::endl;

	std::cout << BLUE "inserting elements into ft::map ..." RESET << std::endl;
	map1.insert(ft::make_pair(9, "alpaca"));
	map1.insert(ft::make_pair(4, "bear"));
	map1.insert(ft::make_pair(8, "cat"));
	map1.insert(ft::make_pair(3, "dog"));
	map1.insert(ft::make_pair(7, "elephant"));

	std::cout << BLUE "inserting elements into std::map ..." RESET << std::endl;
	map2.insert(std::make_pair(9, "alpaca"));
	map2.insert(std::make_pair(4, "bear"));
	map2.insert(std::make_pair(8, "cat"));
	map2.insert(std::make_pair(3, "dog"));
	map2.insert(std::make_pair(7, "elephant"));
	std::cout << std::endl;

	std::cout << BLACK "ft::map " CYAN "empty() = " RESET;
	if (map1.empty())
		std::cout << CYAN "true" RESET << std::endl;
	else
		std::cout << CYAN "false" RESET << std::endl;

	std::cout << BLACK "std::map " CYAN "empty() = " RESET;
	if (map2.empty())
		std::cout << CYAN "true" RESET << std::endl;
	else
		std::cout << CYAN "false" RESET << std::endl;
	std::cout << std::endl;

	std::cout << BLUE "erasing elements from ft::map ..." RESET << std::endl;
	map1.erase(9);
	map1.erase(4);
	map1.erase(8);
	map1.erase(3);
	map1.erase(7);

	std::cout << BLUE "erasing elements from std::map ..." RESET << std::endl;
	map2.erase(9);
	map2.erase(4);
	map2.erase(8);
	map2.erase(3);
	map2.erase(7);
	std::cout << std::endl;

	std::cout << BLACK "ft::map " CYAN "empty() = " RESET;
	if (map1.empty())
		std::cout << CYAN "true" RESET << std::endl;
	else
		std::cout << CYAN "false" RESET << std::endl;

	std::cout << BLACK "std::map " CYAN "empty() = " RESET;
	if (map2.empty())
		std::cout << CYAN "true" RESET << std::endl;
	else
		std::cout << CYAN "false" RESET << std::endl;
	std::cout << std::endl;
}

void	testMapIterator(void)
{
	ft::map<int, std::string>	map1;
	std::map<int, std::string>	map2;
	std::cout << std::endl;

	std::cout << YELLOW "[ TESTING ] map::iterator" RESET << std::endl;
	std::cout << BLUE "inserting elements into ft::map ..." RESET << std::endl;
	map1.insert(ft::make_pair(9, "alpaca"));
	map1.insert(ft::make_pair(4, "bear"));
	map1.insert(ft::make_pair(8, "cat"));
	map1.insert(ft::make_pair(3, "dog"));
	map1.insert(ft::make_pair(7, "elephant"));
	map1.insert(ft::make_pair(2, "fish"));
	map1.insert(ft::make_pair(6, "goat"));
	map1.insert(ft::make_pair(1, "hare"));
	map1.insert(ft::make_pair(5, "igloo"));
	map1.insert(ft::make_pair(0, "jaguar"));

	std::cout << BLUE "inserting elements into std::map ..." RESET << std::endl;
	map2.insert(std::make_pair(9, "alpaca"));
	map2.insert(std::make_pair(4, "bear"));
	map2.insert(std::make_pair(8, "cat"));
	map2.insert(std::make_pair(3, "dog"));
	map2.insert(std::make_pair(7, "elephant"));
	map2.insert(std::make_pair(2, "fish"));
	map2.insert(std::make_pair(6, "goat"));
	map2.insert(std::make_pair(1, "hare"));
	map2.insert(std::make_pair(5, "igloo"));
	map2.insert(std::make_pair(0, "jaguar"));
	std::cout << std::endl;

	ft::map<int, std::string>::iterator		it1 = map1.begin();
	ft::map<int, std::string>::iterator		it2 = map1.end();

	std::map<int, std::string>::iterator	it3 = map2.begin();
	std::map<int, std::string>::iterator	it4 = map2.end();

	std::cout << BLUE "iterating using iterator ..." RESET << std::endl;
	std::cout << BLACK "ft::map " RESET;
	while (it1 != it2)
	{
		std::cout << CYAN "[" << it1->first << ", " << it1->second << "] " RESET;
		++it1;
	}
	std::cout << std::endl;

	std::cout << BLACK "std::map " RESET;
	while (it3 != it4)
	{
		std::cout << CYAN "[" << it3->first << ", " << it3->second << "] " RESET;
		++it3;
	}
	std::cout << std::endl << std::endl;

	ft::map<int, std::string>::reverse_iterator		rit1 = map1.rbegin();
	ft::map<int, std::string>::reverse_iterator		rit2 = map1.rend();

	std::map<int, std::string>::reverse_iterator	rit3 = map2.rbegin();
	std::map<int, std::string>::reverse_iterator	rit4 = map2.rend();

	std::cout << BLUE "iterating using reverse_iterator ..." RESET << std::endl;
	std::cout << BLACK "ft::map " RESET;
	while (rit1 != rit2)
	{
		std::cout << CYAN "[" << rit1->first << ", " << rit1->second << "] " RESET;
		++rit1;
	}
	std::cout << std::endl;

	std::cout << BLACK "std::map " RESET;
	while (rit3 != rit4)
	{
		std::cout << CYAN "[" << rit3->first << ", " << rit3->second << "] " RESET;
		++rit3;
	}
	std::cout << std::endl << std::endl;
}

void	testRBT(void)
{
	ft::redblacktree<int> rbt;
	std::cout << std::endl;

	std::cout << GREEN "Insert 55" RESET << std::endl;
	rbt.insert(55);
	rbt.printTree();
	std::cout << MAGENTA "rbt.size() : " << rbt.size() << RESET << std::endl;
	std::cout << std::endl;

	std::cout << GREEN "Insert 40" RESET << std::endl;
	rbt.insert(40);
	rbt.printTree();
	std::cout << MAGENTA "rbt.size() : " << rbt.size() << RESET << std::endl;
	std::cout << std::endl;

	std::cout << GREEN "Insert 65" RESET << std::endl;
	rbt.insert(65);
	rbt.printTree();
	std::cout << MAGENTA "rbt.size() : " << rbt.size() << RESET << std::endl;
	std::cout << std::endl;

	std::cout << GREEN "Insert 60" RESET << std::endl;
	rbt.insert(60);
	rbt.printTree();
	std::cout << MAGENTA "rbt.size() : " << rbt.size() << RESET << std::endl;
	std::cout << std::endl;

	std::cout << GREEN "Insert 75" RESET << std::endl;
	rbt.insert(75);
	rbt.printTree();
	std::cout << MAGENTA "rbt.size() : " << rbt.size() << RESET << std::endl;
	std::cout << std::endl;

	std::cout << GREEN "Insert 57" RESET << std::endl;
	rbt.insert(57);
	rbt.printTree();
	std::cout << MAGENTA "rbt.size() : " << rbt.size() << RESET << std::endl;
	std::cout << std::endl;

	std::cout << YELLOW "Delete 40" RESET << std::endl;
	rbt.erase(40);
	rbt.printTree();
	std::cout << MAGENTA "rbt.size() : " << rbt.size() << RESET << std::endl;
	std::cout << std::endl;

	ft::redblacktree<int>	rbt2(rbt);
	ft::redblacktree<int>	rbt3;
	rbt3 = rbt;
	rbt = ft::redblacktree<int>();

	std::cout << YELLOW "rbt set to 0" RESET << std::endl;
	rbt.printTree();
	std::cout << MAGENTA "rbt.size() : " << rbt.size() << RESET << std::endl;
	std::cout << std::endl;

	std::cout << YELLOW "Copy constructor" RESET << std::endl;
	rbt2.printTree();
	std::cout << MAGENTA "rbt2.size() : " << rbt2.size() << RESET << std::endl;
	std::cout << std::endl;

	std::cout << YELLOW "Copy assignment operator" RESET << std::endl;
	rbt3.printTree();
	std::cout << MAGENTA "rbt3.size() : " << rbt3.size() << RESET << std::endl;
	std::cout << std::endl;
}
