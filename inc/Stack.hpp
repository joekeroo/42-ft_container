/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 14:09:03 by jhii              #+#    #+#             */
/*   Updated: 2023/01/02 14:26:57 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "Vector.hpp"

namespace	ft
{
	template <class T, class Container = ft::vector<T> >
	class stack
	{
		public:
			typedef Container							container_type;
			typedef typename Container::reference		reference;
			typedef typename Container::size_type		size_type;
			typedef typename Container::value_type		value_type;
			typedef typename Container::const_reference	const_reference;

			explicit stack(container_type const &ctnr = container_type());
			~stack(void);

			stack	&operator=(stack const &);

			void		push(value_type const &);
			void		pop(void);
			void		swap(stack &);
			bool		empty(void) const;
			size_type	size(void) const;
			reference	top(void);

		protected:
			container_type	c;
	};

	template <class T, class Container>
	bool	operator==(stack<T, Container> const &a, stack<T, Container> const &b)
	{ return (a == b); }

	template <class T, class Container>
	bool	operator!=(stack<T, Container> const &a, stack<T, Container> const &b)
	{ return (a != b); }

	template <class T, class Container>
	bool	operator<(stack<T, Container> const &a, stack<T, Container> const &b)
	{ return (a < b); }

	template <class T, class Container>
	bool	operator<=(stack<T, Container> const &a, stack<T, Container> const &b)
	{ return (a <= b); }

	template <class T, class Container>
	bool	operator>(stack<T, Container> const &a, stack<T, Container> const &b)
	{ return (a > b); }

	template <class T, class Container>
	bool	operator>=(stack<T, Container> const &a, stack<T, Container> const &b)
	{ return (a >= b); }
}

#include "Stack.tpp"

#endif
