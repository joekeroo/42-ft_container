/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:27:58 by jhii              #+#    #+#             */
/*   Updated: 2023/02/22 19:04:28 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TPP
# define ITERATOR_TPP

using namespace	ft;

template <class T>
randomAccessIterator<T>::randomAccessIterator(void): ptr(pointer())
{
	// std::cout << GREEN "randomAccessIterator constructor called" RESET << std::endl;
}

template <class T>
randomAccessIterator<T>::randomAccessIterator(randomAccessIterator::pointer in): ptr(in)
{
	// std::cout << GREEN "randomAccessIterator constructor called" RESET << std::endl;
}

template <class T>
randomAccessIterator<T>::randomAccessIterator(randomAccessIterator<typename ft::remove_const<value_type>::type> const &ref)
{
	// std::cout << GREEN "randomAccessIterator copy constructor called" RESET << std::endl;
	*this = ref;
}

template <class T>
randomAccessIterator<T>::~randomAccessIterator(void)
{
	// std::cout << RED "randomAccessIterator destructor called" RESET << std::endl;
}

template <class T> randomAccessIterator<T>
&randomAccessIterator<T>::operator=(randomAccessIterator<typename ft::remove_const<value_type>::type> const &ref)
{
	// std::cout << GREEN "randomAccessIterator copy assignment operator called" RESET << std::endl;
	this->ptr = ref.ptr;
	return (*this);
}

template <class T> typename randomAccessIterator<T>::reference
randomAccessIterator<T>::operator*(void) const
{
	return (*this->ptr);
}

template <class T> typename randomAccessIterator<T>::pointer
randomAccessIterator<T>::operator->(void) const
{
	return (&(operator*()));
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
	return (*this);
}

template <class T> typename randomAccessIterator<T>::reference
randomAccessIterator<T>::operator[](difference_type n)
{
	return (*(this->ptr + n));
}

#endif
