/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:28:05 by jhii              #+#    #+#             */
/*   Updated: 2023/02/22 19:05:35 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include "Utils.hpp"

namespace	ft
{
	template <class T>
	struct randomAccessIterator
	{
		typedef T									value_type;
		typedef value_type							*pointer;
		typedef value_type							&reference;
		typedef std::ptrdiff_t						difference_type;
		typedef std::random_access_iterator_tag		iterator_category;

		pointer	ptr;

		randomAccessIterator(void);
		~randomAccessIterator(void);
		randomAccessIterator(pointer);
		randomAccessIterator(randomAccessIterator<typename std::remove_const<value_type>::type> const &);

		randomAccessIterator	&operator=(randomAccessIterator<typename std::remove_const<value_type>::type> const &);

		randomAccessIterator	&operator++(void);
		randomAccessIterator	&operator--(void);
		randomAccessIterator	operator++(int);
		randomAccessIterator	operator--(int);
		reference				operator*(void) const;
		pointer					operator->(void) const;
		reference				operator[](difference_type);
	};

	template <class T, class U> bool
	operator==(randomAccessIterator<T> const &a, randomAccessIterator<U> const &b)
	{
		return (a.ptr == b.ptr);
	}

	template <class T, class U> bool
	operator!=(randomAccessIterator<T> const &a, randomAccessIterator<U> const &b)
	{
		return (a.ptr != b.ptr);
	}

	template <class T, class U> bool
	operator<=(randomAccessIterator<T> const &a, randomAccessIterator<U> const &b)
	{
		return (a.ptr <= b.ptr);
	}

	template <class T, class U> bool
	operator>=(randomAccessIterator<T> const &a, randomAccessIterator<U> const &b)
	{
		return (a.ptr >= b.ptr);
	}

	template <class T, class U> bool
	operator<(randomAccessIterator<T> const &a, randomAccessIterator<U> const &b)
	{
		return (a.ptr < b.ptr);
	}

	template <class T, class U> bool
	operator>(randomAccessIterator<T> const &a, randomAccessIterator<U> const &b)
	{
		return (a.ptr > b.ptr);
	}

	template <class T> randomAccessIterator<T>
	&operator+=(randomAccessIterator<T> &ref, ptrdiff_t n)
	{
		for (ptrdiff_t i = 0; i < n; ++i)
			++ref;
		return (ref);
	}

	template <class T> randomAccessIterator<T>
	&operator-=(randomAccessIterator<T> &ref, ptrdiff_t n)
	{
		for (ptrdiff_t i = 0; i < n; ++i)
			--ref;
		return (ref);
	}

	template <class T>
	randomAccessIterator<T>	operator+(randomAccessIterator<T> const &a, typename randomAccessIterator<T>::difference_type n)
	{
		randomAccessIterator<T> temp(a.ptr + n);
		return (temp);
	}

	template <class T>
	randomAccessIterator<T> operator-(randomAccessIterator<T> const &a, typename randomAccessIterator<T>::difference_type n)
	{
		randomAccessIterator<T> temp(a.ptr - n);
		return (temp);
	}

	template <class T>
	randomAccessIterator<T>	operator+(typename randomAccessIterator<T>::difference_type n, randomAccessIterator<T> const &a)
	{
		randomAccessIterator<T> temp(a.ptr + n);
		return (temp);
	}

	template <class T>
	randomAccessIterator<T> operator-(typename randomAccessIterator<T>::difference_type n, randomAccessIterator<T> const &a)
	{
		randomAccessIterator<T> temp(a.ptr - n);
		return (temp);
	}

	template <class T, class U> ptrdiff_t
	operator-(randomAccessIterator<T> const &a, randomAccessIterator<U> const &b)
	{
		return (a.ptr - b.ptr);
	}
}

# include "Iterator.tpp"

#endif
