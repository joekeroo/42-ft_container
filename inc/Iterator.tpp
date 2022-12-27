/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:27:58 by jhii              #+#    #+#             */
/*   Updated: 2022/12/21 17:36:04 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TPP
# define ITERATOR_TPP

using namespace	ft;

template <class T>
randomAccessIterator<T>::randomAccessIterator(void)
{
	// std::cout << GREEN "randomAccessIterator constructor called" RESET << std::endl;
}

template <class T>
randomAccessIterator<T>::randomAccessIterator(randomAccessIterator::pointer in): ptr(in)
{
	// std::cout << GREEN "randomAccessIterator constructor called" RESET << std::endl;
}

template <class T>
randomAccessIterator<T>::~randomAccessIterator(void)
{
	// std::cout << RED "randomAccessIterator destructor called" RESET << std::endl;
}

template <class T>
randomAccessIterator<T>::randomAccessIterator(randomAccessIterator<T> const &ref)
{
	// std::cout << GREEN "randomAccessIterator copy constructor called" RESET << std::endl;
	*this = ref;
}

template <class T> randomAccessIterator<T>
&randomAccessIterator<T>::operator=(randomAccessIterator<T> const &ref)
{
	// std::cout << GREEN "randomAccessIterator copy assignment operator called" RESET << std::endl;
	this->ptr = ref.ptr;
	return (*this);
}

template <class T> typename randomAccessIterator<T>::reference
randomAccessIterator<T>::operator*(void)
{
	return (*this->ptr);
}

template <class T> typename randomAccessIterator<T>::pointer
randomAccessIterator<T>::operator->(void)
{
	return (this->ptr);
}

template <class T> randomAccessIterator<T>
randomAccessIterator<T>::operator++(int)
{
	randomAccessIterator tmp = *this;
	++(*this);
	return (tmp);
}

template <class T> randomAccessIterator<T>
&randomAccessIterator<T>::operator++(void)
{
	this->ptr++;
	return (*this);
}

template <class T> randomAccessIterator<T>
randomAccessIterator<T>::operator--(int)
{
	randomAccessIterator tmp = *this;
	--(*this);
	return (tmp);
}

template <class T> randomAccessIterator<T>
&randomAccessIterator<T>::operator--(void)
{
	this->ptr--;
	return (this);
}

template <class T> randomAccessIterator<T>
&randomAccessIterator<T>::operator[](int n)
{
	return (*(this->ptr + n));
}

template <typename T> bool
ft::operator==(randomAccessIterator<T> const &a, randomAccessIterator<T> const &b)
{
	return (a.ptr == b.ptr);
}

template <typename T> bool
ft::operator!=(randomAccessIterator<T> const &a, randomAccessIterator<T> const &b)
{
	return (a.ptr != b.ptr);
}

template <typename T> bool
ft::operator<=(randomAccessIterator<T> const &a, randomAccessIterator<T> const &b)
{
	return (!(a.ptr > b.ptr));
}

template <typename T> bool
ft::operator>=(randomAccessIterator<T> const &a, randomAccessIterator<T> const &b)
{
	return (!(a.ptr < b.ptr));
}

template <typename T> bool
ft::operator<(randomAccessIterator<T> const &a, randomAccessIterator<T> const &b)
{
	return (b.ptr - a.ptr > 0);
}

template <typename T> bool
ft::operator>(randomAccessIterator<T> const &a, randomAccessIterator<T> const &b)
{
	return (b.ptr < a.ptr);
}

template <typename T> randomAccessIterator<T>
&operator+=(randomAccessIterator<T> const &a, typename randomAccessIterator<T>::difference_type n)
{
	typename randomAccessIterator<T>::difference_type m = n;
	if (m >= 0)
	{
		while (m--)
			++a.ptr;
	}
	else
	{
		while (m++)
			--a.ptr;
	}
	return (a);
}

template <typename T> randomAccessIterator<T>
&operator-=(randomAccessIterator<T> const &a, typename randomAccessIterator<T>::difference_type n)
{
	return (a.ptr += -n);
}

template <typename T> randomAccessIterator<T>
ft::operator+(randomAccessIterator<T> const &a, typename randomAccessIterator<T>::difference_type n)
{
	randomAccessIterator<T> temp = a;
	return (temp.ptr + n);
}
template <typename T> randomAccessIterator<T>
ft::operator+(typename randomAccessIterator<T>::difference_type n, randomAccessIterator<T> const &a)
{
	randomAccessIterator<T> temp = a;
	return (temp.ptr + n);
}

template <typename T> randomAccessIterator<T>
ft::operator-(randomAccessIterator<T> const &a, typename randomAccessIterator<T>::difference_type n)
{
	randomAccessIterator<T> temp = a;
	return (temp.ptr - n);
}

template <typename T> randomAccessIterator<T>
ft::operator-(typename randomAccessIterator<T>::difference_type n, randomAccessIterator<T> const &a)
{
	randomAccessIterator<T> temp = a;
	return (temp.ptr - n);
}

template <typename T> typename randomAccessIterator<T>::difference_type
ft::operator-(randomAccessIterator<T> const &a, randomAccessIterator<T> const &b)
{
	typename randomAccessIterator<T>::difference_type temp;
	if (a.ptr > b.ptr)
		temp = a.ptr - b.ptr;
	else
		temp = b.ptr - a.ptr;
	return (temp);
}

#endif
