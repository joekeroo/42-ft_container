/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBT_Iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:23:52 by jhii              #+#    #+#             */
/*   Updated: 2023/02/15 14:52:20 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_ITERATOR_HPP
# define RBT_ITERATOR_HPP

# include "Utils.hpp"

namespace	ft
{
	template <class T>
	class	rbt_iterator
	{
		public:
			typedef T								value_type;
			typedef value_type						*pointer;
			typedef value_type						&reference;
			typedef	ft::node<value_type>			*node_pointer;
			typedef std::ptrdiff_t					difference_type;
			typedef std::random_access_iterator_tag	iterator_category;

			node_pointer	ptr;

			rbt_iterator(void);
			~rbt_iterator(void);
			rbt_iterator(node_pointer p);
			rbt_iterator(rbt_iterator const &ref);

			rbt_iterator	&operator=(rbt_iterator const &ref);

			reference		operator*(void);
			pointer			operator->(void);
			rbt_iterator	&operator++(void);
			rbt_iterator	&operator--(void);
			rbt_iterator	operator++(int);
			rbt_iterator	operator--(int);
			rbt_iterator	operator+(difference_type n) const;
			rbt_iterator	operator-(difference_type n) const;
			rbt_iterator	&operator+=(difference_type n);
			rbt_iterator	&operator-=(difference_type n);
			bool			operator==(rbt_iterator const &ref);
			bool			operator!=(rbt_iterator const &ref);
	};
}

# include "RBT_Iterator.tpp"

#endif
