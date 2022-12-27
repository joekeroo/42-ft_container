/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IteratorTraits.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:41:54 by jhii              #+#    #+#             */
/*   Updated: 2022/12/20 14:58:54 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORTRAITS_HPP
# define ITERATORTRAITS_HPP

# include "Utils.hpp"

namespace	ft
{
	template <class Iter>
	struct iterator_traits
	{
		typedef typename Iter::pointer				pointer;
		typedef typename Iter::reference			reference;
		typedef typename Iter::value_type			value_type;
		typedef	typename Iter::difference_type		difference_type;
		typedef typename Iter::iterator_category	iterator_category;
	};

	template <class T>
	struct iterator_traits<T *>
	{
		typedef T								*pointer;
		typedef T								&reference;
		typedef T								value_type;
		typedef	std::ptrdiff_t					difference_type;
		typedef std::random_access_iterator_tag	iterator_category;
	};

	template <class T>
	struct iterator_traits<T const *>
	{
		typedef T								*pointer;
		typedef const T							&reference;
		typedef const T							value_type;
		typedef	std::ptrdiff_t					difference_type;
		typedef std::random_access_iterator_tag	iterator_category;
	};
}

#endif
