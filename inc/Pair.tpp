/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pair.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:52:35 by jhii              #+#    #+#             */
/*   Updated: 2023/02/05 19:18:08 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_TPP
# define PAIR_TPP

using namespace ft;

template <class T1, class T2>
pair<T1, T2>::pair(void): first(), second()
{
	std::cout << GREEN "pair constructor called" << std::endl;
}

template <class T1, class T2>
pair<T1, T2>::~pair(void)
{
	std::cout << RED "pair destructor called" << std::endl;
}

template <class T1, class T2>
pair<T1, T2>::pair(first_type const &a, second_type const &b): first(a), second(b)
{
	std::cout << GREEN "pair constructor called" << std::endl;
}

template <class T1, class T2>
template <class U, class V>
pair<T1, T2>::pair(pair<U, V> const &pr)
{
	std::cout << GREEN "pair copy constructor called" << std::endl;
	*this = pr;
}

template <class T1, class T2> pair<T1, T2>
&pair<T1, T2>::operator=(pair<T1, T2> const &pr)
{
	std::cout << GREEN "pair copy assignment operator called" << std::endl;
	this->first = pr.first;
	this->second = pr.second;
	return (*this);
}

template <class T1, class T2> void
pair<T1, T2>::swap(pair &pr)
{
	swap(this->first, pr.first);
	swap(this->second, pr.second);
}

#endif
