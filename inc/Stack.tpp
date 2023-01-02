/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 14:11:35 by jhii              #+#    #+#             */
/*   Updated: 2023/01/02 15:07:20 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_TPP
# define STACK_TPP

using namespace ft;

template<class T, class Container>
stack<T, Container>::stack(container_type const &cntr): c(cntr)
{
	// std::cout << GREEN "Stack constructor called" RESET << std::endl;
}

template<class T, class Container>
stack<T, Container>::~stack(void)
{
	// std::cout << RED "Stack destructor called" RESET << std::endl;
}

template <class T, class Container> stack<T, Container>
&stack<T, Container>::operator=(stack<T, Container> const &ref)
{
	// std::cout << GREEN "Stack copy assignment operator called" RESET << std::endl;
	this->c = ref.c;
	return (*this);
}

template<class T, class Container> void
stack<T, Container>::push(value_type const &val)
{
	this->c.push_back(val);
}

template<class T, class Container> void
stack<T, Container>::pop(void)
{
	this->c.pop_back();
}

template<class T, class Container> void
stack<T, Container>::swap(stack &ref)
{
	this->c.swap(ref.c);
}

template<class T, class Container> bool
stack<T, Container>::empty(void) const
{
	return (this->c.empty());
}

template<class T, class Container> typename stack<T, Container>::size_type
stack<T, Container>::size(void) const
{
	return (this->c.size());
}

template<class T, class Container> typename stack<T, Container>::reference
stack<T, Container>::top(void)
{
	return (this->c.back());
}

#endif
