/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bidirectional_Iterator.tpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:23:50 by jhii              #+#    #+#             */
/*   Updated: 2023/02/21 15:22:10 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONAL_ITERATOR_TPP
# define BIDIRECTIONAL_ITERATOR_TPP

using namespace ft;

template <class T>
bidirectional_iterator<T>::bidirectional_iterator(void)
{
	// std::cout << GREEN "bidirectional_iterator constructor called" RESET << std::endl;
}

template <class T>
bidirectional_iterator<T>::bidirectional_iterator(node_pointer p): ptr(p)
{
	// std::cout << GREEN "bidirectional_iterator constructor called" RESET << std::endl;
}

template <class T>
bidirectional_iterator<T>::bidirectional_iterator(bidirectional_iterator<typename std::remove_const<value_type>::type> const &ref): ptr(ref.ptr)
{
	// std::cout << GREEN "bidirectional_iterator copy constructor called" RESET << std::endl;
}

template <class T> bidirectional_iterator<T>
&bidirectional_iterator<T>::operator=(bidirectional_iterator const &ref)
{
	// std::cout << GREEN "bidirectional_iterator copy assignment operator called" RESET << std::endl;
	this->ptr = ref.ptr;
	return (*this);
}

template <class T>
bidirectional_iterator<T>::~bidirectional_iterator(void)
{
	// std::cout << RED "bidirectional_iterator destructor called" RESET << std::endl;
}

template <class T>
typename bidirectional_iterator<T>::reference
bidirectional_iterator<T>::operator*(void) const
{
	return (*(this->ptr->data));
}

template <class T>
typename bidirectional_iterator<T>::pointer
bidirectional_iterator<T>::operator->(void) const
{
	return (&(operator*()));
}

template <class T> bidirectional_iterator<T>
&bidirectional_iterator<T>::operator++(void)
{
	if (this->ptr->isSentinel == true)
	{
		if (this->ptr->left != nullptr)
			this->ptr = this->ptr->left;
		return (*this);
	}
	if (this->ptr->right->isSentinel == true)
	{
		node_pointer temp = this->ptr;
		while (temp->parent != nullptr)
		{
			if (temp == temp->parent->right)
				temp = temp->parent;
			else
				break ;
		}
		if (temp->parent != nullptr)
		{
			if (temp == temp->parent->left)
				this->ptr = temp->parent;
		}
		else
			this->ptr = this->ptr->right;
	}
	else
	{
		this->ptr = this->ptr->right;
		while (this->ptr->left->isSentinel == false)
			this->ptr = this->ptr->left;
	}
	return (*this);
}

template <class T> bidirectional_iterator<T>
&bidirectional_iterator<T>::operator--(void)
{
	if (this->ptr->isSentinel == true)
	{
		if (this->ptr->right != nullptr)
			this->ptr = this->ptr->right;
		return (*this);
	}
	if (this->ptr->left->isSentinel == true)
	{
		node_pointer temp = this->ptr;
		while (temp->parent != nullptr)
		{
			if (temp == temp->parent->left)
				temp = temp->parent;
			else
				break ;
		}
		if (temp->parent != nullptr)
		{
			if (temp == temp->parent->right)
				this->ptr = temp->parent;
		}
		else
			this->ptr = this->ptr->left;
	}
	else
	{
		this->ptr = this->ptr->left;
		while (this->ptr->right->isSentinel == false)
			this->ptr = this->ptr->right;
	}
	return (*this);
}

template <class T> bidirectional_iterator<T>
bidirectional_iterator<T>::operator++(int)
{
	bidirectional_iterator temp(this->ptr);
	++(*this);
	return (temp);
}

template <class T> bidirectional_iterator<T>
bidirectional_iterator<T>::operator--(int)
{
	bidirectional_iterator temp(this->ptr);
	--(*this);
	return (temp);
}

template <class T>
bidirectional_iterator<T>
bidirectional_iterator<T>::operator+(difference_type n) const
{
	bidirectional_iterator	temp = *this;
	for (difference_type i = 0; i < n; ++i)
		++temp;
	return (temp);
}

template <class T>
bidirectional_iterator<T>
bidirectional_iterator<T>::operator-(difference_type n) const
{
	bidirectional_iterator	temp = *this;
	for (difference_type i = 0; i < n; ++i)
		--temp;
	return (temp);
}

template <class T>
bidirectional_iterator<T>
&bidirectional_iterator<T>::operator+=(difference_type n)
{
	for (difference_type i = 0; i < n; ++i)
		++(*this);
	return (*this);
}

template <class T>
bidirectional_iterator<T>
&bidirectional_iterator<T>::operator-=(difference_type n)
{
	for (difference_type i = 0; i < n; ++i)
		--(*this);
	return (*this);
}

template <class T> bool
bidirectional_iterator<T>::operator==(bidirectional_iterator const &ref)
{
	return (this->ptr->data == ref.ptr->data);
}

template <class T> bool
bidirectional_iterator<T>::operator!=(bidirectional_iterator const &ref)
{
	return (this->ptr->data != ref.ptr->data);
}

#endif
