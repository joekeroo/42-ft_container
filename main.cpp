/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:24:58 by jhii              #+#    #+#             */
/*   Updated: 2023/02/07 11:58:04 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector.hpp"
#include "Stack.hpp"
#include "RedBlackTree.hpp"

int	main(int argc, char **argv)
{
	testVector();
	testStack();
	testMap();
	if (argc == 2)
	{
		std::string	str(argv[1]);
		if (str == "leaks")
			system("leaks ft_container");
	}
	return (0);
}
