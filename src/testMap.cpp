/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testMap.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:10:12 by jhii              #+#    #+#             */
/*   Updated: 2023/02/16 19:21:58 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Map.hpp"

void	testMap(void)
{
	ft::map<int, std::string>	map;

    map.insert(ft::make_pair(9, "a"));
    map.insert(ft::make_pair(1, "b"));
    map.insert(ft::make_pair(7, "c"));
    map.insert(ft::make_pair(2, "d"));
    map.insert(ft::make_pair(3, "e"));
    map.insert(ft::make_pair(1, "f"));
    map.insert(ft::make_pair(1, "g"));
    map.insert(ft::make_pair(1, "h"));

	map.printTree();
	std::cout << std::endl;
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
