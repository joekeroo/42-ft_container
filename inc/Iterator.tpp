/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:27:58 by jhii              #+#    #+#             */
/*   Updated: 2023/02/20 18:44:23 by jhii             ###   ########.fr       */
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
	return (this);
}

template <class T> randomAccessIterator<T>
&randomAccessIterator<T>::operator[](int n)
{
	return (*(this->ptr + n));
}

template <class T> bool
randomAccessIterator<T>::operator==(randomAccessIterator<T> const &ref)
{
	return (this->ptr == ref.ptr);
}

template <class T> bool
randomAccessIterator<T>::operator!=(randomAccessIterator<T> const &ref)
{
	return (this->ptr != ref.ptr);
}

template <class T> bool
randomAccessIterator<T>::operator<=(randomAccessIterator<T> const &ref)
{
	return (!(this->ptr > ref.ptr));
}

template <class T> bool
randomAccessIterator<T>::operator>=(randomAccessIterator<T> const &ref)
{
	return (!(this->ptr < ref.ptr));
}

template <class T> bool
randomAccessIterator<T>::operator<(randomAccessIterator<T> const &ref)
{
	return (ref.ptr - this->ptr > 0);
}

template <class T> bool
randomAccessIterator<T>::operator>(randomAccessIterator<T> const &ref)
{
	return (ref.ptr < this->ptr);
}

template <class T>
randomAccessIterator<T>
&randomAccessIterator<T>::operator+=(difference_type n)
{
	typename randomAccessIterator<T>::difference_type m = n;
	if (m >= 0)
	{
		while (m--)
			++this->ptr;
	}
	else
	{
		while (m++)
			--this->ptr;
	}
	return (*this);
}

template <class T>
randomAccessIterator<T>
&randomAccessIterator<T>::operator-=(difference_type n)
{
	return (this->ptr += -n);
}

template <class T>
randomAccessIterator<T>
randomAccessIterator<T>::operator+(difference_type n)
{
	randomAccessIterator<T> temp = *this;
	return (temp.ptr + n);
}

template <class T>
randomAccessIterator<T>
randomAccessIterator<T>::operator-(difference_type n)
{
	randomAccessIterator<T> temp = *this;
	return (temp.ptr - n);
}

template <class T>
typename randomAccessIterator<T>::difference_type
randomAccessIterator<T>::operator-(randomAccessIterator const &ref)
{
	typename randomAccessIterator<T>::difference_type temp;
	if (this->ptr > ref.ptr)
		temp = this->ptr - ref.ptr;
	else
		temp = ref.ptr - this->ptr;
	return (temp);
}

#endif
