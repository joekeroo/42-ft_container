/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 14:09:03 by jhii              #+#    #+#             */
/*   Updated: 2022/12/28 14:16:47 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "Vector.hpp"

namespace	ft
{
	template <class T, class Container = vector<T> >
	class stack
	{
		typedef size_t		size_type;
		typedef T			value_type;
		typedef Container	container_type;

		explicit	stack(container_type const &ctnr = container_type());
	};
}

#include "Stack.tpp"

#endif
