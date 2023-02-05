/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testRBT.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:10:12 by jhii              #+#    #+#             */
/*   Updated: 2023/02/05 19:14:12 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RedBlackTree.hpp"

void	testRBT(void)
{
	ft::redblacktree<int> bst;
	bst.insert(55);
	bst.insert(40);
	bst.insert(65);
	bst.insert(60);
	bst.insert(75);
	bst.insert(57);

	bst.printTree();
	std::cout << std::endl << "After deleting" << std::endl;
	bst.deleteNode(40);
	bst.printTree();
}
