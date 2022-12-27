/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:28:05 by jhii              #+#    #+#             */
/*   Updated: 2022/12/07 19:37:19 by jhii             ###   ########.fr       */
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
		reference				operator*(void);
		pointer					operator->(void);
	};

	template <typename T>
	bool	operator==(randomAccessIterator<T> const &, randomAccessIterator<T> const &);
	template <typename T>
	bool	operator!=(randomAccessIterator<T> const &, randomAccessIterator<T> const &);
	template <typename T>
	bool	operator<=(randomAccessIterator<T> const &, randomAccessIterator<T> const &);
	template <typename T>
	bool	operator>=(randomAccessIterator<T> const &, randomAccessIterator<T> const &);
	template <typename T>
	bool	operator<(randomAccessIterator<T> const &, randomAccessIterator<T> const &);
	template <typename T>
	bool	operator>(randomAccessIterator<T> const &, randomAccessIterator<T> const &);
	template <typename T>
	randomAccessIterator<T>	operator+=(randomAccessIterator<T> const &, typename randomAccessIterator<T>::difference_type);
	template <typename T>
	randomAccessIterator<T>	operator-=(randomAccessIterator<T> const &, typename randomAccessIterator<T>::difference_type);
	template <typename T>
	randomAccessIterator<T>	operator+(randomAccessIterator<T> const &, typename randomAccessIterator<T>::difference_type);
	template <typename T>
	randomAccessIterator<T>	operator+(typename randomAccessIterator<T>::difference_type, randomAccessIterator<T> const &);
	template <typename T>
	randomAccessIterator<T> operator-(randomAccessIterator<T> const &, typename randomAccessIterator<T>::difference_type);
	template <typename T>
	randomAccessIterator<T> operator-(typename randomAccessIterator<T>::difference_type, randomAccessIterator<T> const &);
	template <typename T>
	typename randomAccessIterator<T>::difference_type operator-(randomAccessIterator<T> const &, randomAccessIterator<T> const &);
}

# include "Iterator.tpp"

#endif
