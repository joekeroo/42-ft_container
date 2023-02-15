/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBT_Iterator.tpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:23:50 by jhii              #+#    #+#             */
/*   Updated: 2023/02/15 16:08:38 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_ITERATOR_TPP
# define RBT_ITERATOR_TPP

using namespace ft;

template <class T>
rbt_iterator<T>::rbt_iterator(void)
{
	// std::cout << GREEN "rbt_iterator constructor called" RESET << std::endl;
}

template <class T>
rbt_iterator<T>::rbt_iterator(node_pointer p): ptr(p)
{
	// std::cout << GREEN "rbt_iterator constructor called" RESET << std::endl;
}

template <class T>
rbt_iterator<T>::rbt_iterator(rbt_iterator const &ref): ptr(ref.ptr)
{
	// std::cout << GREEN "rbt_iterator copy constructor called" RESET << std::endl;
}

template <class T> rbt_iterator<T>
&rbt_iterator<T>::operator=(rbt_iterator const &ref)
{
	// std::cout << GREEN "rbt_iterator copy assignment operator called" RESET << std::endl;
	this->ptr = ref.ptr;
	return (*this);
}

template <class T>
rbt_iterator<T>::~rbt_iterator(void)
{
	// std::cout << RED "rbt_iterator destructor called" RESET << std::endl;
}

template <class T>
typename rbt_iterator<T>::reference
rbt_iterator<T>::operator*(void)
{
	return (*(this->ptr->data));
}

template <class T>
typename rbt_iterator<T>::pointer
rbt_iterator<T>::operator->(void)
{
	return (&(operator*()));
}

template <class T> rbt_iterator<T>
&rbt_iterator<T>::operator++(void)
{
	if (this->ptr->isSentinel == true)
	{
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

template <class T> rbt_iterator<T>
&rbt_iterator<T>::operator--(void)
{
	if (this->ptr->isSentinel == true)
	{
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

template <class T> rbt_iterator<T>
rbt_iterator<T>::operator++(int)
{
	rbt_iterator temp(this->ptr);
	++(*this);
	return (temp);
}

template <class T> rbt_iterator<T>
rbt_iterator<T>::operator--(int)
{
	rbt_iterator temp(this->ptr);
	--(*this);
	return (temp);
}

template <class T>
rbt_iterator<T>
rbt_iterator<T>::operator+(difference_type n) const
{
	rbt_iterator	temp = *this;
	for (difference_type i = 0; i < n; ++i)
		++temp;
	return (temp);
}

template <class T>
rbt_iterator<T>
rbt_iterator<T>::operator-(difference_type n) const
{
	rbt_iterator	temp = *this;
	for (difference_type i = 0; i < n; ++i)
		--temp;
	return (temp);
}

template <class T>
rbt_iterator<T>
&rbt_iterator<T>::operator+=(difference_type n)
{
	for (difference_type i = 0; i < n; ++i)
		++(*this);
	return (*this);
}

template <class T>
rbt_iterator<T>
&rbt_iterator<T>::operator-=(difference_type n)
{
	for (difference_type i = 0; i < n; ++i)
		--(*this);
	return (*this);
}

template <class T> bool
rbt_iterator<T>::operator==(rbt_iterator const &ref)
{
	return (this->ptr->data == ref.ptr->data);
}

template <class T> bool
rbt_iterator<T>::operator!=(rbt_iterator const &ref)
{
	return (!(this->ptr == ref.ptr));
}

#endif
