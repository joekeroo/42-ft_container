/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:28:05 by jhii              #+#    #+#             */
/*   Updated: 2023/02/20 18:45:10 by jhii             ###   ########.fr       */
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
		typedef T								*pointer;
		typedef T								&reference;
		typedef T								value_type;
		typedef std::ptrdiff_t					difference_type;
		typedef std::random_access_iterator_tag	iterator_category;

		pointer	ptr;

		randomAccessIterator(void);
		~randomAccessIterator(void);
		randomAccessIterator(pointer);
		randomAccessIterator(randomAccessIterator const &);

		randomAccessIterator	&operator=(randomAccessIterator const &);
		randomAccessIterator	&operator++(void);
		randomAccessIterator	&operator--(void);
		randomAccessIterator	operator++(int);
		randomAccessIterator	operator--(int);
		randomAccessIterator	&operator[](int);
		randomAccessIterator	&operator+=(difference_type);
		randomAccessIterator	&operator-=(difference_type);
		randomAccessIterator	operator+(difference_type);
		randomAccessIterator	operator-(difference_type);
		reference				operator*(void) const;
		pointer					operator->(void) const;
		difference_type			operator-(randomAccessIterator const &);
		bool					operator==(randomAccessIterator const &);
		bool					operator!=(randomAccessIterator const &);
		bool					operator<=(randomAccessIterator const &);
		bool					operator>=(randomAccessIterator const &);
		bool					operator<(randomAccessIterator const &);
		bool					operator>(randomAccessIterator const &);

	};

	template <class T>
	randomAccessIterator<T>	operator+(typename randomAccessIterator<T>::difference_type n, randomAccessIterator<T> const &a)
	{
		randomAccessIterator<T> temp = a;
		return (temp.ptr + n);
	}

	template <class T>
	randomAccessIterator<T> operator-(typename randomAccessIterator<T>::difference_type n, randomAccessIterator<T> const &a)
	{
		randomAccessIterator<T> temp = a;
		return (temp.ptr - n);
	}
}

# include "Iterator.tpp"

#endif
