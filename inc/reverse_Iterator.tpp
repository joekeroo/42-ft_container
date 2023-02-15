/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_Iterator.tpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 20:16:19 by jhii              #+#    #+#             */
/*   Updated: 2023/02/15 16:06:40 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_TPP
# define REVERSE_ITERATOR_TPP

using namespace ft;

template <class T>
reverse_iterator<T>::reverse_iterator(void)
{
	// std::cout << GREEN "reverse_iterator constructor called" RESET << std::endl;
}

template <class T>
reverse_iterator<T>::reverse_iterator(typename reverse_iterator<T>::iterator_type it)
{
	this->_base = it - 1;
	// std::cout << GREEN "reverse_iterator constructor called" RESET << std::endl;
}

template <class T>
template <class Iter>
reverse_iterator<T>::reverse_iterator(reverse_iterator<Iter> const &ref)
{
	this->_base = ref.base() - 1;
}

template <class T>
reverse_iterator<T>::~reverse_iterator(void)
{
	// std::cout << RED "reverse_iterator destructor called" RESET << std::endl;
}

template <class T>
template <class U> reverse_iterator<T>
&reverse_iterator<T>::operator=(reverse_iterator<U> const &ref)
{
	this->_base = ref.base() - 1;
	return (*this);
}

template <class T> reverse_iterator<T>
&reverse_iterator<T>::operator++(void)
{
	--this->_base;
	return (*this);
}

template <class T> reverse_iterator<T>
&reverse_iterator<T>::operator--(void)
{
	++this->_base;
	return (*this);
}

template <class T> reverse_iterator<T>
reverse_iterator<T>::operator++(int)
{
	reverse_iterator	temp = *this;
	this->_base--;
	return (temp);
}

template <class T> reverse_iterator<T>
reverse_iterator<T>::operator--(int)
{
	reverse_iterator	temp = *this;
	this->_base++;
	return (temp);
}

template <class T> reverse_iterator<T>
reverse_iterator<T>::operator+(typename reverse_iterator<T>::difference_type n) const
{
	this->_base -= n;
	return (this);
}

template <class T> reverse_iterator<T>
reverse_iterator<T>::operator-(typename reverse_iterator<T>::difference_type n) const
{
	this->_base += n;
	return (this);
}

template <class T> reverse_iterator<T>
&reverse_iterator<T>::operator+=(typename reverse_iterator<T>::difference_type n)
{
	this->_base -= n;
	return (*this);
}

template <class T> reverse_iterator<T>
&reverse_iterator<T>::operator-=(typename reverse_iterator<T>::difference_type n)
{
	this->_base += n;
	return (*this);
}

template <class T> reverse_iterator<T>
&reverse_iterator<T>::operator[](int n)
{
	this->_base -= n;
	return (*this);
}

template <class T> typename reverse_iterator<T>::reference
reverse_iterator<T>::operator*(void)
{
	return (*this->_base);
}

template <class T> typename reverse_iterator<T>::pointer
reverse_iterator<T>::operator->(void)
{
	return (&(operator*()));
}

template <class T> bool
reverse_iterator<T>::operator==(reverse_iterator const &ref)
{
	return (this->base() == ref.base());
}

template <class T> bool
reverse_iterator<T>::operator!=(reverse_iterator const &ref)
{
	return (this->base() != ref.base());
}

template <class Iter> typename reverse_iterator<Iter>::iterator_type
reverse_iterator<Iter>::base(void) const
{
	return (this->_base + 1);
}

template <class T> bool
operator<=(reverse_iterator<T> const &a, reverse_iterator<T> const &b)
{
	return (a.base() <= b.base());
}

template <class T> bool
operator>=(reverse_iterator<T> const &a, reverse_iterator<T> const &b)
{
	return (a.base() >= b.base());
}

template <class T> bool
operator<(reverse_iterator<T> const &a, reverse_iterator<T> const &b)
{
	return (a.base() < b.base());
}

template <class T> bool
operator>(reverse_iterator<T> const &a, reverse_iterator<T> const &b)
{
	return (a.base() > b.base());
}

template <class T> reverse_iterator<T>
operator+(typename reverse_iterator<T>::difference_type n, reverse_iterator<T> const &ref)
{
	return (ref + n);
}

template <class T> reverse_iterator<T>
operator-(typename reverse_iterator<T>::difference_type n, reverse_iterator<T> const &ref)
{
	return (ref - n);
}

template <class T> typename reverse_iterator<T>::difference_type
operator-(reverse_iterator<T> const &a, reverse_iterator<T> const &b)
{
	typename reverse_iterator<T>::difference_type	temp;
	if (a.base() > b.base())
		temp = a.base() - b.base();
	else
		temp = b.base() - a.base();
	return (temp);
}

#endif
