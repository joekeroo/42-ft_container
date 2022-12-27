/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Algorithm.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:02:40 by jhii              #+#    #+#             */
/*   Updated: 2022/12/23 15:22:52 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_HPP
# define ALGORITHM_HPP

# include "Utils.hpp"

namespace	ft
{
	template <class InputIterator1, class InputIterator2>
	bool	equal(InputIterator1, InputIterator1, InputIterator2);
	template <class InputIterator1, class InputIterator2>
	bool	lexicographical_compare(InputIterator1, InputIterator1, InputIterator2, InputIterator2);
}

# include "Algorithm.tpp"

#endif
