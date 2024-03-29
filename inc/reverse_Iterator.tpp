/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_Iterator.tpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 20:16:19 by jhii              #+#    #+#             */
/*   Updated: 2023/02/22 20:04:47 by jhii             ###   ########.fr       */
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
reverse_iterator<T>::reverse_iterator(iterator_type it)
{
	// std::cout << GREEN "reverse_iterator constructor called" RESET << std::endl;
	this->_base = it - 1;
}

template <class T>
template <class Iter>
reverse_iterator<T>::reverse_iterator(reverse_iterator<Iter> const &ref): _base(ref.base() - 1)
{
	// std::cout << GREEN "reverse_iterator copy constructor called" RESET << std::endl;
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

template <class T> typename reverse_iterator<T>::reference
reverse_iterator<T>::operator[](int n)
{
	return (*(this->_base - n));
}

template <class T> typename reverse_iterator<T>::reference
reverse_iterator<T>::operator*(void) const
{
	return (*this->_base);
}

template <class T> typename reverse_iterator<T>::pointer
reverse_iterator<T>::operator->(void) const
{
	return (&(operator*()));
}

template <class Iter> typename reverse_iterator<Iter>::iterator_type
reverse_iterator<Iter>::base(void) const
{
	return (this->_base + 1);
}

#endif
