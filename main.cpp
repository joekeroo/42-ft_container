/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:24:58 by jhii              #+#    #+#             */
/*   Updated: 2023/02/06 12:51:38 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector.hpp"
#include "Stack.hpp"
#include "RedBlackTree.hpp"

int	main(void)
{
	testVector();
	testStack();
	testRBT();
	system("leaks ft_container");
	return (0);
}
