/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bidirectional_Iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:23:52 by jhii              #+#    #+#             */
/*   Updated: 2023/02/21 15:23:03 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONAL_ITERATOR_HPP
# define BIDIRECTIONAL_ITERATOR_HPP

# include "Utils.hpp"

namespace	ft
{
	template <class T>
	class	bidirectional_iterator
	{
		public:
			typedef T														value_type;
			typedef value_type												*pointer;
			typedef value_type												&reference;
			typedef	ft::node<typename std::remove_const<value_type>::type>	*node_pointer;
			typedef std::ptrdiff_t											difference_type;
			typedef std::random_access_iterator_tag							iterator_category;

			node_pointer	ptr;

			bidirectional_iterator(void);
			~bidirectional_iterator(void);
			bidirectional_iterator(node_pointer p);
			bidirectional_iterator(bidirectional_iterator<typename std::remove_const<value_type>::type> const &ref);

			bidirectional_iterator	&operator=(bidirectional_iterator const &ref);

			reference				operator*(void) const;
			pointer					operator->(void) const;
			bidirectional_iterator	&operator++(void);
			bidirectional_iterator	&operator--(void);
			bidirectional_iterator	operator++(int);
			bidirectional_iterator	operator--(int);
			bidirectional_iterator	operator+(difference_type n) const;
			bidirectional_iterator	operator-(difference_type n) const;
			bidirectional_iterator	&operator+=(difference_type n);
			bidirectional_iterator	&operator-=(difference_type n);
			bool					operator==(bidirectional_iterator const &ref);
			bool					operator!=(bidirectional_iterator const &ref);
	};
}

# include "Bidirectional_Iterator.tpp"

#endif
