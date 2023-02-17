/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.tpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:49:39 by jhii              #+#    #+#             */
/*   Updated: 2023/02/17 17:08:31 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_TPP
# define MAP_TPP

using namespace ft;

template <class Key, class T, class Compare, class Alloc>
map<Key, T, Compare, Alloc>::map(key_compare const &comp, allocator_type const &alloc): _comp(comp), _alloc(alloc), _rbt(alloc, comp)
{
	// std::cout << GREEN "Map constructor called" RESET << std::endl;
}

template <class Key, class T, class Compare, class Alloc>
map<Key, T, Compare, Alloc>::map(map const &ref): _rbt(this->_alloc, this->_comp)
{
	// std::cout << GREEN "Map copy constructor called" RESET << std::endl;
	this->_rbt = ref._rbt;
}

template <class Key, class T, class Compare, class Alloc> map<Key, T, Compare, Alloc>
&map<Key, T, Compare, Alloc>::operator=(map const &ref)
{
	// std::cout << GREEN "Map copy assignment operator called" RESET << std::endl;
	this->_rbt = ref._rbt;
	return (*this);
}

template <class Key, class T, class Compare, class Alloc>
map<Key, T, Compare, Alloc>::~map(void)
{
	// std::cout << RED "Map destructor called" RESET << std::endl;
}

template <class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::iterator
map<Key, T, Compare, Alloc>::begin(void)
{
	return (this->_rbt.begin());
}

template <class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::const_iterator
map<Key, T, Compare, Alloc>::begin(void) const
{
	return (this->_rbt.begin());
}

template <class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::iterator
map<Key, T, Compare, Alloc>::end(void)
{
	return (this->_rbt.end());
}

template <class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::const_iterator
map<Key, T, Compare, Alloc>::end(void) const
{
	return (this->_rbt.end());
}

template <class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::reverse_iterator
map<Key, T, Compare, Alloc>::rbegin(void)
{
	return (this->_rbt.rbegin());
}

template <class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::const_reverse_iterator
map<Key, T, Compare, Alloc>::rbegin(void) const
{
	return (this->_rbt.rbegin());
}

template <class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::reverse_iterator
map<Key, T, Compare, Alloc>::rend(void)
{
	return (this->_rbt.rend());
}

template <class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::const_reverse_iterator
map<Key, T, Compare, Alloc>::rend(void) const
{
	return (this->_rbt.rend());
}

template <class Key, class T, class Compare, class Alloc>
bool	map<Key, T, Compare, Alloc>::empty(void) const
{
	return (this->_rbt.empty());
}

template <class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::size_type
map<Key, T, Compare, Alloc>::size(void) const
{
	return (this->_rbt.size());
}

template <class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::size_type
map<Key, T, Compare, Alloc>::max_size(void) const
{
	return (this->_rbt.max_size() + this->_alloc.max_size());
}

template <class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::mapped_type
&map<Key, T, Compare, Alloc>::operator[](key_type const &key)
{
	ft::pair<const key_type, mapped_type> temp = ft::make_pair(key, mapped_type());
	return (this->_rbt[temp].second);
}

template <class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::mapped_type
&map<Key, T, Compare, Alloc>::at(key_type const &key)
{
	ft::pair<const key_type, mapped_type> temp = ft::make_pair(key, mapped_type());
	return (this->_rbt.at(temp).second);
}

template <class Key, class T, class Compare, class Alloc>
template <class InputIterator> void
map<Key, T, Compare, Alloc>::insert(InputIterator first, InputIterator last)
{
	this->_rbt.insert(first, last);
}

template <class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::iterator
map<Key, T, Compare, Alloc>::insert(iterator it, value_type const &val)
{
	return (this->_rbt.insert(it, val));
}

template <class Key, class T, class Compare, class Alloc>
ft::pair<typename map<Key, T, Compare, Alloc>::iterator, bool>
map<Key, T, Compare, Alloc>::insert(value_type const &val)
{
	return (this->_rbt.insert(val));
}

template <class Key, class T, class Compare, class Alloc>
void	map<Key, T, Compare, Alloc>::erase(iterator it)
{
	this->_rbt.erase(it);
}

template <class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::size_type
map<Key, T, Compare, Alloc>::erase(key_type const &key)
{
	ft::pair<const key_type, mapped_type> temp = ft::make_pair(key, mapped_type());
	return (this->_rbt.erase(temp));
}

template <class Key, class T, class Compare, class Alloc>
void	map<Key, T, Compare, Alloc>::erase(iterator first, iterator last)
{
	this->_rbt.erase(first, last);
}

template <class Key, class T, class Compare, class Alloc>
void	map<Key, T, Compare, Alloc>::swap(map &ref)
{
	map<Key, T, Compare, Alloc>	temp(ref);
	ref = *this;
	*this = temp;
}

template <class Key, class T, class Compare, class Alloc>
void	map<Key, T, Compare, Alloc>::clear(void)
{
	this->_rbt.clear();
}

template <class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::key_compare
map<Key, T, Compare, Alloc>::key_comp(void) const
{
	return (this->_comp);
}

template <class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::value_compare
map<Key, T, Compare, Alloc>::value_comp(void) const
{
	return (this->_rbt.value_comp());
}

template <class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::iterator
map<Key, T, Compare, Alloc>::find(key_type const &key)
{
	ft::pair<const key_type, mapped_type> temp = ft::make_pair(key, mapped_type());
	return (this->_rbt.find(temp));
}

template <class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::const_iterator
map<Key, T, Compare, Alloc>::find(key_type const &key) const
{
	ft::pair<const key_type, mapped_type> temp = ft::make_pair(key, mapped_type());
	return (this->_rbt.find(temp));
}

template <class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::size_type
map<Key, T, Compare, Alloc>::count(key_type const &key) const
{
	ft::pair<const key_type, mapped_type> temp = ft::make_pair(key, mapped_type());
	return (this->_rbt.count(temp));
}

template <class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::iterator
map<Key, T, Compare, Alloc>::lower_bound(key_type const &key)
{
	ft::pair<const key_type, mapped_type> temp = ft::make_pair(key, mapped_type());
	return (this->_rbt.lower_bound(temp));
}

template <class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::const_iterator
map<Key, T, Compare, Alloc>::lower_bound(key_type const &key) const
{
	ft::pair<const key_type, mapped_type> temp = ft::make_pair(key, mapped_type());
	return (this->_rbt.lower_bound(temp));
}

template <class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::iterator
map<Key, T, Compare, Alloc>::upper_bound(key_type const &key)
{
	ft::pair<const key_type, mapped_type> temp = ft::make_pair(key, mapped_type());
	return (this->_rbt.upper_bound(temp));
}

template <class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::const_iterator
map<Key, T, Compare, Alloc>::upper_bound(key_type const &key) const
{
	ft::pair<const key_type, mapped_type> temp = ft::make_pair(key, mapped_type());
	return (this->_rbt.upper_bound(temp));
}

template <class Key, class T, class Compare, class Alloc>
ft::pair<typename map<Key, T, Compare, Alloc>::iterator, typename map<Key, T, Compare, Alloc>::iterator>
map<Key, T, Compare, Alloc>::equal_range(key_type const &key)
{
	ft::pair<const key_type, mapped_type> temp = ft::make_pair(key, mapped_type());
	return (this->equal_range(temp));
}

template <class Key, class T, class Compare, class Alloc>
ft::pair<typename map<Key, T, Compare, Alloc>::const_iterator, typename map<Key, T, Compare, Alloc>::const_iterator>
map<Key, T, Compare, Alloc>::equal_range(key_type const &key) const
{
	ft::pair<const key_type, mapped_type> temp = ft::make_pair(key, mapped_type());
	return (this->equal_range(temp));
}

template <class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::allocator_type
map<Key, T, Compare, Alloc>::get_allocator(void) const
{
	return (this->_rbt.get_allocator());
}

template <class Key, class T, class Compare, class Alloc>
void	map<Key, T, Compare, Alloc>::printTree(void)
{
	this->_rbt.printTree();
}

#endif
