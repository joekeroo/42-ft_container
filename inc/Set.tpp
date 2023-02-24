/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Set.tpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:49:39 by jhii              #+#    #+#             */
/*   Updated: 2023/02/21 15:08:35 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_TPP
# define SET_TPP

using namespace ft;

template <class T, class Compare, class Alloc>
set<T, Compare, Alloc>::set(key_compare const &comp, allocator_type const &alloc): _comp(comp), _alloc(alloc), _rbt(alloc, comp)
{
	// std::cout << GREEN "set constructor called" RESET << std::endl;
}

template <class T, class Compare, class Alloc>
set<T, Compare, Alloc>::set(set const &ref): _rbt(this->_alloc, this->_comp)
{
	// std::cout << GREEN "set copy constructor called" RESET << std::endl;
	this->_rbt = ref._rbt;
}

template <class T, class Compare, class Alloc>
template <class InputIterator>
set<T, Compare, Alloc>::set(InputIterator first, InputIterator last, key_compare const &comp, allocator_type const &alloc): _comp(comp), _alloc(alloc), _rbt(first, last, alloc, comp)
{
	// std::cout << GREEN "set constructor called" RESET << std::endl;
}

template <class T, class Compare, class Alloc> set<T, Compare, Alloc>
&set<T, Compare, Alloc>::operator=(set const &ref)
{
	// std::cout << GREEN "set copy assignment operator called" RESET << std::endl;
	this->_rbt = ref._rbt;
	return (*this);
}

template <class T, class Compare, class Alloc>
set<T, Compare, Alloc>::~set(void)
{
	// std::cout << RED "set destructor called" RESET << std::endl;
}

template <class T, class Compare, class Alloc>
typename set<T, Compare, Alloc>::iterator
set<T, Compare, Alloc>::begin(void)
{
	return (this->_rbt.begin());
}

template <class T, class Compare, class Alloc>
typename set<T, Compare, Alloc>::const_iterator
set<T, Compare, Alloc>::begin(void) const
{
	return (this->_rbt.begin());
}

template <class T, class Compare, class Alloc>
typename set<T, Compare, Alloc>::iterator
set<T, Compare, Alloc>::end(void)
{
	return (this->_rbt.end());
}

template <class T, class Compare, class Alloc>
typename set<T, Compare, Alloc>::const_iterator
set<T, Compare, Alloc>::end(void) const
{
	return (this->_rbt.end());
}

template <class T, class Compare, class Alloc>
typename set<T, Compare, Alloc>::reverse_iterator
set<T, Compare, Alloc>::rbegin(void)
{
	return (this->_rbt.rbegin());
}

template <class T, class Compare, class Alloc>
typename set<T, Compare, Alloc>::const_reverse_iterator
set<T, Compare, Alloc>::rbegin(void) const
{
	return (this->_rbt.rbegin());
}

template <class T, class Compare, class Alloc>
typename set<T, Compare, Alloc>::reverse_iterator
set<T, Compare, Alloc>::rend(void)
{
	return (this->_rbt.rend());
}

template <class T, class Compare, class Alloc>
typename set<T, Compare, Alloc>::const_reverse_iterator
set<T, Compare, Alloc>::rend(void) const
{
	return (this->_rbt.rend());
}

template <class T, class Compare, class Alloc>
bool	set<T, Compare, Alloc>::empty(void) const
{
	return (this->_rbt.empty());
}

template <class T, class Compare, class Alloc>
typename set<T, Compare, Alloc>::size_type
set<T, Compare, Alloc>::size(void) const
{
	return (this->_rbt.size());
}

template <class T, class Compare, class Alloc>
typename set<T, Compare, Alloc>::size_type
set<T, Compare, Alloc>::max_size(void) const
{
	return (this->_rbt.max_size());
}

template <class T, class Compare, class Alloc>
typename set<T, Compare, Alloc>::mapped_type
&set<T, Compare, Alloc>::operator[](key_type const &key)
{
	ft::pair<const key_type, mapped_type> temp = ft::make_pair(key, mapped_type());
	return (this->_rbt[temp].second);
}

template <class T, class Compare, class Alloc>
typename set<T, Compare, Alloc>::mapped_type
&set<T, Compare, Alloc>::at(key_type const &key)
{
	ft::pair<const key_type, mapped_type> temp = ft::make_pair(key, mapped_type());
	return (this->_rbt.at(temp).second);
}

template <class T, class Compare, class Alloc>
template <class InputIterator> void
set<T, Compare, Alloc>::insert(InputIterator first, InputIterator last)
{
	this->_rbt.insert(first, last);
}

template <class T, class Compare, class Alloc>
typename set<T, Compare, Alloc>::iterator
set<T, Compare, Alloc>::insert(iterator it, value_type const &val)
{
	return (this->_rbt.insert(it, val));
}

template <class T, class Compare, class Alloc>
ft::pair<typename set<T, Compare, Alloc>::iterator, bool>
set<T, Compare, Alloc>::insert(value_type const &val)
{
	return (this->_rbt.insert(val));
}

template <class T, class Compare, class Alloc>
void	set<T, Compare, Alloc>::erase(iterator it)
{
	this->_rbt.erase(it);
}

template <class T, class Compare, class Alloc>
typename set<T, Compare, Alloc>::size_type
set<T, Compare, Alloc>::erase(key_type const &key)
{
	ft::pair<const key_type, mapped_type> temp = ft::make_pair(key, mapped_type());
	return (this->_rbt.erase(temp));
}

template <class T, class Compare, class Alloc>
void	set<T, Compare, Alloc>::erase(iterator first, iterator last)
{
	this->_rbt.erase(first, last);
}

template <class T, class Compare, class Alloc>
void	set<T, Compare, Alloc>::swap(set &ref)
{
	std::swap(this->_comp, ref._comp);
	this->_rbt.swap(ref._rbt);
}

template <class T, class Compare, class Alloc>
void	set<T, Compare, Alloc>::clear(void)
{
	this->_rbt.clear();
}

template <class T, class Compare, class Alloc>
typename set<T, Compare, Alloc>::key_compare
set<T, Compare, Alloc>::key_comp(void) const
{
	return (this->_comp);
}

template <class T, class Compare, class Alloc>
typename set<T, Compare, Alloc>::value_compare
set<T, Compare, Alloc>::value_comp(void) const
{
	return (this->_rbt.value_comp());
}

template <class T, class Compare, class Alloc>
typename set<T, Compare, Alloc>::iterator
set<T, Compare, Alloc>::find(key_type const &key)
{
	ft::pair<const key_type, mapped_type> temp = ft::make_pair(key, mapped_type());
	return (this->_rbt.find(temp));
}

template <class T, class Compare, class Alloc>
typename set<T, Compare, Alloc>::const_iterator
set<T, Compare, Alloc>::find(key_type const &key) const
{
	ft::pair<const key_type, mapped_type> temp = ft::make_pair(key, mapped_type());
	return (this->_rbt.find(temp));
}

template <class T, class Compare, class Alloc>
typename set<T, Compare, Alloc>::size_type
set<T, Compare, Alloc>::count(key_type const &key) const
{
	ft::pair<const key_type, mapped_type> temp = ft::make_pair(key, mapped_type());
	return (this->_rbt.count(temp));
}

template <class T, class Compare, class Alloc>
typename set<T, Compare, Alloc>::iterator
set<T, Compare, Alloc>::lower_bound(key_type const &key)
{
	ft::pair<const key_type, mapped_type> temp = ft::make_pair(key, mapped_type());
	return (this->_rbt.lower_bound(temp));
}

template <class T, class Compare, class Alloc>
typename set<T, Compare, Alloc>::const_iterator
set<T, Compare, Alloc>::lower_bound(key_type const &key) const
{
	ft::pair<const key_type, mapped_type> temp = ft::make_pair(key, mapped_type());
	return (this->_rbt.lower_bound(temp));
}

template <class T, class Compare, class Alloc>
typename set<T, Compare, Alloc>::iterator
set<T, Compare, Alloc>::upper_bound(key_type const &key)
{
	ft::pair<const key_type, mapped_type> temp = ft::make_pair(key, mapped_type());
	return (this->_rbt.upper_bound(temp));
}

template <class T, class Compare, class Alloc>
typename set<T, Compare, Alloc>::const_iterator
set<T, Compare, Alloc>::upper_bound(key_type const &key) const
{
	ft::pair<const key_type, mapped_type> temp = ft::make_pair(key, mapped_type());
	return (this->_rbt.upper_bound(temp));
}

template <class T, class Compare, class Alloc>
ft::pair<typename set<T, Compare, Alloc>::iterator, typename set<T, Compare, Alloc>::iterator>
set<T, Compare, Alloc>::equal_range(key_type const &key)
{
	ft::pair<const key_type, mapped_type> temp = ft::make_pair(key, mapped_type());
	return (this->_rbt.equal_range(temp));
}

template <class T, class Compare, class Alloc>
ft::pair<typename set<T, Compare, Alloc>::const_iterator, typename set<T, Compare, Alloc>::const_iterator>
set<T, Compare, Alloc>::equal_range(key_type const &key) const
{
	ft::pair<const key_type, mapped_type> temp = ft::make_pair(key, mapped_type());
	return (this->_rbt.equal_range(temp));
}

template <class T, class Compare, class Alloc>
typename set<T, Compare, Alloc>::allocator_type
set<T, Compare, Alloc>::get_allocator(void) const
{
	return (this->_rbt.get_allocator());
}

template <class T, class Compare, class Alloc>
void	set<T, Compare, Alloc>::printTree(void)
{
	this->_rbt.printTree();
}

#endif
