/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:52:21 by jhii              #+#    #+#             */
/*   Updated: 2023/02/10 12:49:25 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

# include "Utils.hpp"

namespace	ft
{
	template <class T1, class T2>
	struct pair
	{
		typedef T1	first_type;
		typedef T2	second_type;

		pair(void);
		~pair(void);
		template <class U, class V>
		pair(pair<U, V> const &);
		pair(first_type const &, second_type const &);

		pair	&operator=(pair const &);

		void	swap(pair &);

		first_type	first;
		second_type	second;
	};

	template <class T1, class T2>
	bool	operator==(pair<T1, T2> const &lhs, pair<T1, T2> const &rhs)
	{ return (lhs.first == rhs.first && lhs.second == rhs.second); }

	template <class T1, class T2>
	bool	operator!=(pair<T1, T2> const &lhs, pair<T1, T2> const &rhs)
	{ return (!(lhs == rhs)); }

	template <class T1, class T2>
	bool	operator<(pair<T1, T2> const &lhs, pair<T1, T2> const &rhs)
	{ return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second)); }

	template <class T1, class T2>
	bool	operator<=(pair<T1, T2> const &lhs, pair<T1, T2> const &rhs)
	{ return (!(rhs < lhs)); }

	template <class T1, class T2>
	bool	operator>(pair<T1, T2> const &lhs, pair<T1, T2> const &rhs)
	{ return (rhs < lhs); }

	template <class T1, class T2>
	bool	operator>=(pair<T1, T2> const &lhs, pair<T1, T2> const &rhs)
	{ return (!(lhs < rhs)); }

	template <class T1, class T2>
	void	swap(pair<T1, T2> &x, pair<T1, T2> &y)
	{ x.swap(y); }

	template <class T1, class T2>
	pair<T1, T2>	make_pair(T1 x, T2 y)
	{ return (pair<T1, T2>(x, y)); }

	template <class T1, class T2>
	std::ostream	&operator<<(std::ostream &output, pair<T1, T2> &ref)
	{
		output << "[" << ref.first;
		output << ", " << ref.second << "]";
		return (output);
	}
}

# include "Pair.tpp"

#endif
