/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:48:42 by jhii              #+#    #+#             */
/*   Updated: 2023/02/21 15:13:46 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
# define SET_HPP

# include "Pair.hpp"
# include "Utils.hpp"
# include "Algorithm.hpp"
# include "RedBlackTree.hpp"

namespace	ft
{
	template <class T, class Compare = std::less<T>, class Alloc = std::allocator<pair<const T, T> > >
	class set
	{
		public:
			typedef T											key_type;
			typedef T											mapped_type;
			typedef Alloc										allocator_type;
			typedef size_t										size_type;
			// typedef std::ptrdiff_t								difference_type;
			typedef __gnu_cxx::ptrdiff_t						difference_type;
			typedef Compare										key_compare;
			typedef ft::pair<const T, T>						value_type;

			class	value_compare: public std::binary_function<T, T, bool>
			{
				protected:
					key_compare	comp;
				
				public:
					value_compare(key_compare const &c): comp(c) {}
					bool	operator()(value_type const &lhs, value_type const &rhs) const
					{ return (comp(lhs.first, rhs.first)); }
			};

			typedef ft::bidirectional_iterator<value_type>			iterator;
			typedef ft::bidirectional_iterator<const value_type>	const_iterator;
			typedef ft::reverse_iterator<iterator>					reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;
			typedef typename allocator_type::reference				reference;
			typedef typename allocator_type::const_reference		const_reference;
			typedef typename allocator_type::pointer				pointer;
			typedef typename allocator_type::const_pointer			const_pointer;

			template <class InputIterator>
			set(InputIterator first, InputIterator last, key_compare const &comp = key_compare(), allocator_type const &alloc = allocator_type());
			explicit	set(key_compare const &comp = key_compare(), allocator_type const &alloc = allocator_type());
			set(set const &ref);
			~set(void);

			set	&operator=(set const &ref);

			iterator					begin(void);
			const_iterator				begin(void) const;
			iterator					end(void);
			const_iterator				end(void) const;

			reverse_iterator			rbegin(void);
			const_reverse_iterator		rbegin(void) const;
			reverse_iterator			rend(void);
			const_reverse_iterator		rend(void) const;

			bool						empty(void) const;
			size_type					size(void) const;
			size_type					max_size(void) const;

			mapped_type					&operator[](key_type const &key);
			mapped_type					&at(key_type const &key);

			template <class InputIterator>
			void						insert(InputIterator first, InputIterator last);
			iterator					insert(iterator it, value_type const &val);
			ft::pair<iterator, bool>	insert(value_type const &val);
			void						erase(iterator it);
			size_type					erase(key_type const &key);
			void						erase(iterator first, iterator last);
			void						swap(set &ref);
			void						clear(void);

			key_compare					key_comp(void) const;
			value_compare				value_comp(void) const;

			iterator									find(key_type const &key);
			const_iterator								find(key_type const &key) const;
			size_type									count(key_type const &key) const;
			iterator									lower_bound(key_type const &key);
			const_iterator								lower_bound(key_type const &key) const;
			iterator									upper_bound(key_type const &key);
			const_iterator								upper_bound(key_type const &key) const;
			ft::pair<iterator, iterator>				equal_range(key_type const &key);
			ft::pair<const_iterator, const_iterator>	equal_range(key_type const &key) const;

			allocator_type				get_allocator(void) const;
			void						printTree(void);

			key_compare												_comp;
			allocator_type											_alloc;
			redblacktree<value_type, value_compare, allocator_type>	_rbt;
	};

	template <class T, class Compare, class Alloc>
	bool	operator==(set<T, Compare, Alloc> const &a, set<T, Compare, Alloc> const &b)
	{ return (a._rbt.size() == b._rbt.size() && ft::equal(a._rbt.begin(), a._rbt.end(), b._rbt.begin())); }

	template <class T, class Compare, class Alloc>
	bool	operator!=(set<T, Compare, Alloc> const &a, set<T, Compare, Alloc> const &b)
	{ return (!(a == b)); }

	template <class T, class Compare, class Alloc>
	bool	operator<(set<T, Compare, Alloc> const &a, set<T, Compare, Alloc> const &b)
	{ return (ft::lexicographical_compare(a._rbt.begin(), a._rbt.end(), b._rbt.begin(), b._rbt.end())); }

	template <class T, class Compare, class Alloc>
	bool	operator>(set<T, Compare, Alloc> const &a, set<T, Compare, Alloc> const &b)
	{ return (b < a); }

	template <class T, class Compare, class Alloc>
	bool	operator<=(set<T, Compare, Alloc> const &a, set<T, Compare, Alloc> const &b)
	{ return (!(b < a)); }

	template <class T, class Compare, class Alloc>
	bool	operator>=(set<T, Compare, Alloc> const &a, set<T, Compare, Alloc> const &b)
	{ return (!(a < b)); }

	template <class T, class Compare, class Alloc>
	void	swap(set<T, Compare, Alloc> const &a, set<T, Compare, Alloc> const &b)
	{ a.swap(b); }
}

# include "Set.tpp"

#endif
