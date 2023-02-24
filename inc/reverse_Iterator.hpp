/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_Iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 20:06:09 by jhii              #+#    #+#             */
/*   Updated: 2023/02/22 20:11:47 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "IteratorTraits.hpp"

namespace	ft
{
	template <class T>
	class reverse_iterator
	{
		public:
			typedef T													iterator_type;
			typedef typename ft::iterator_traits<T>::pointer			pointer;
			typedef typename ft::iterator_traits<T>::reference			reference;
			typedef typename ft::iterator_traits<T>::value_type			value_type;
			typedef typename ft::iterator_traits<T>::difference_type	difference_type;
			typedef typename ft::iterator_traits<T>::iterator_category	iterator_category;

			reverse_iterator(void);
			~reverse_iterator(void);
			explicit				reverse_iterator(iterator_type);
			template <class Iter>	reverse_iterator(reverse_iterator<Iter> const &);

			template <class U>
			reverse_iterator	&operator=(reverse_iterator<U> const &);
			reverse_iterator	&operator++(void);
			reverse_iterator	&operator--(void);
			reverse_iterator	operator++(int);
			reverse_iterator	operator--(int);
			reference			operator[](int);
			reference			operator*(void) const;
			pointer				operator->(void) const;
			iterator_type		base(void) const;

		private:
			iterator_type	_base;
	};

	template <class T, class U> bool
	operator==(reverse_iterator<T> const &a, reverse_iterator<U> const &b)
	{
		return (b.base() == a.base());
	}

	template <class T, class U> bool
	operator!=(reverse_iterator<T> const &a, reverse_iterator<U> const &b)
	{
		return (b.base() != a.base());
	}

	template <class T, class U> bool
	operator<=(reverse_iterator<T> const &a, reverse_iterator<U> const &b)
	{
		return (b.base() <= a.base());
	}

	template <class T, class U> bool
	operator>=(reverse_iterator<T> const &a, reverse_iterator<U> const &b)
	{
		return (b.base() >= a.base());
	}

	template <class T, class U> bool
	operator<(reverse_iterator<T> const &a, reverse_iterator<U> const &b)
	{
		return (b.base() < a.base());
	}

	template <class T, class U> bool
	operator>(reverse_iterator<T> const &a, reverse_iterator<U> const &b)
	{
		return (b.base() > a.base());
	}

	template <class T> reverse_iterator<T>
	// &operator+=(reverse_iterator<T> &ref, ptrdiff_t n)
	&operator+=(reverse_iterator<T> &ref, __gnu_cxx::ptrdiff_t n)
	{
		reverse_iterator<T>	temp(ref.base() - n);
		ref = temp;
		return (ref);
	}

	template <class T> reverse_iterator<T>
	// &operator-=(reverse_iterator<T> &ref, ptrdiff_t n)
	&operator-=(reverse_iterator<T> &ref, __gnu_cxx::ptrdiff_t n)
	{
		reverse_iterator<T>	temp(ref.base() + n);
		ref = temp;
		return (ref);
	}

	template <class T> reverse_iterator<T>
	operator+(reverse_iterator<T> const &ref, typename reverse_iterator<T>::difference_type n)
	{
		reverse_iterator<T>	temp(ref.base() - n);
		return (temp);
	}

	template <class T> reverse_iterator<T>
	operator+(typename reverse_iterator<T>::difference_type n, reverse_iterator<T> const &ref)
	{
		reverse_iterator<T>	temp(ref.base() - n);
		return (temp);
	}

	template <class T> reverse_iterator<T>
	operator-(reverse_iterator<T> const &ref, typename reverse_iterator<T>::difference_type n)
	{
		reverse_iterator<T>	temp(ref.base() + n);
		return (temp);
	}

	template <class T> reverse_iterator<T>
	operator-(typename reverse_iterator<T>::difference_type n, reverse_iterator<T> const &ref)
	{
		reverse_iterator<T>	temp(ref.base() + n);
		return (temp);
	}

	// template <class T, class U> ptrdiff_t
	template <class T, class U> __gnu_cxx::ptrdiff_t
	operator-(reverse_iterator<T> const &a, reverse_iterator<U> const &b)
	{
		return (b.base() - a.base());
	}
}

# include "reverse_Iterator.tpp"

#endif
