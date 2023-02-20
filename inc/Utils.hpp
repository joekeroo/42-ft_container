/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:32:38 by jhii              #+#    #+#             */
/*   Updated: 2023/02/20 16:02:48 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# define RESET		"\033[0m"
# define BLACK		"\033[30m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define BLUE		"\033[34m"
# define MAGENTA	"\033[35m"
# define CYAN		"\033[36m"
# define WHITE		"\033[37m"

# include <fstream>
# include <iostream>
# include "Vector.hpp"

namespace	ft
{
	template <class T> void
	swap(T &a, T &b)
	{
		T	c(a);
		a = b;
		b = c;
	}

	template <class T>
	struct	node
	{
		T		*data;
		node	*parent;
		node	*left;
		node	*right;
		int		color;
		bool	isSentinel;
	};
}

// ft::vector
void	testVector(void);
void	testVectorAll(void);
void	testVectorConstructor(void);
void	testVectorRelationalOperator(void);
void	testVectorResize(void);
void	testVectorData(void);
void	testVectorAssign(void);
void	testVectorPushBack(void);
void	testVectorPopBack(void);
void	testVectorSwap(void);
void	testVectorClear(void);
void	testVectorErase(void);
void	testVectorInsert(void);

// ft::stack
void	testStack(void);
void	testStackAll(void);
void	testStackConstructor(void);
void	testStackEmpty(void);
void	testStackSize(void);
void	testStackTop(void);
void	testStackPush(void);
void	testStackPop(void);
void	testStackSwap(void);

// ft::Maps and ft::redblacktree
void	testRBT(void);
void	testMap(void);
void	testMapInsertAndErase(void);
void	testMapEqualRange(void);
void	testMapBound(void);
void	testMapCount(void);
void	testMapFind(void);
void	testMapValueComp(void);
void	testMapKeyComp(void);
void	testMapClear(void);
void	testMapSwap(void);
void	testMapAt(void);
void	testMapOperator(void);
void	testMapEmpty(void);
void	testMapSize(void);
void	testMapIterator(void);

#endif
