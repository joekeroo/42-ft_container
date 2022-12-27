/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:32:38 by jhii              #+#    #+#             */
/*   Updated: 2022/12/23 16:17:02 by jhii             ###   ########.fr       */
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

#endif
