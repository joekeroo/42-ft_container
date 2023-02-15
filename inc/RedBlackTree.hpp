/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RedBlackTree.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:11:41 by jhii              #+#    #+#             */
/*   Updated: 2023/02/15 18:07:21 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDBLACKTREE_HPP
# define REDBLACKTREE_HPP

# include "Pair.hpp"
# include "RBT_Iterator.hpp"
# include "reverse_Iterator.hpp"

enum	color
{
	black,
	red
};

namespace	ft
{
	template <class T, class Compare = std::less<T>, class Alloc = std::allocator<T> >
	class redblacktree
	{
		public:
			typedef T																value_type;
			typedef node<T>															*node_ptr;
			typedef Compare															value_compare;
			typedef Alloc															allocator_type;
			typedef size_t															size_type;
			typedef rbt_iterator<value_type>										iterator;
			typedef rbt_iterator<const value_type>									const_iterator;
			typedef reverse_iterator<iterator>										reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>							const_reverse_iterator;
			typedef typename Alloc::template rebind<ft::node<value_type> >::other	node_allocator;

			redblacktree(node_allocator const &alloc = node_allocator(), value_compare const &comp = value_compare());
			redblacktree(redblacktree const &ref);
			~redblacktree(void);

			redblacktree	&operator=(redblacktree const &ref);

			void		inorder(void);
			void		preorder(void);
			void		postorder(void);
			node_ptr	successor(node_ptr node);
			node_ptr	predecessor(node_ptr node);

			void		printTree(void);
			node_ptr	getRoot(void);
			node_ptr	getTNULL(void);
			node_ptr	minimum(node_ptr node);
			node_ptr	maximum(node_ptr node);
			node_ptr	searchTree(value_type const &key);

			// map functions needed in redblacktree

			iterator					begin(void);
			const_iterator				begin(void) const;
			iterator					end(void);
			const_iterator				end(void) const;

			reverse_iterator			rbegin(void);
			const_reverse_iterator		rbegin(void) const;
			reverse_iterator			rend(void);
			const_reverse_iterator		rend(void) const;

			template <class InputIterator>
			void						insert(InputIterator first, InputIterator last);
			iterator					insert(iterator it, value_type const &key);
			ft::pair<iterator, bool>	insert(value_type const &key);
			void						erase(iterator it);
			size_type					erase(value_type const &key);
			void						erase(iterator first, iterator last);
			bool						empty(void);
			size_type					size(void);
			size_type					max_size(void) const;

			value_type					&operator[](value_type const &key);
			value_type					&at(value_type const &key);

			void						swap(redblacktree &ref);
			void						clear(void);

			iterator									find(value_type const &key);
			const_iterator								find(value_type const &key) const;
			size_type									count(value_type const &key) const;
			iterator									lower_bound(value_type const &key);
			const_iterator								lower_bound(value_type const &key) const;
			iterator									upper_bound(value_type const &key);
			const_iterator								upper_bound(value_type const &key) const;
			ft::pair<iterator, iterator>				equal_range(value_type const &key);
			ft::pair<const_iterator, const_iterator>	equal_range(value_type const &key) const;

			allocator_type	get_allocator(void) const;

		private:
			size_type		_size;
			node_ptr		_root;
			node_ptr		_TNULL;
			allocator_type	_allocPair;
			node_allocator	_allocNode;
			value_compare	_compare;

			void		inOrderHelper(node_ptr node);
			void		preOrderHelper(node_ptr node);
			void		postOrderHelper(node_ptr node);
			void		printHelper(node_ptr root, std::string indent, bool last);
			node_ptr	searchTreeHelper(node_ptr &node, value_type const &key);

			void		insertNode(value_type const &key);
			void		eraseNode(value_type const &key);
			void		insertFix(node_ptr node);
			void		deleteFix(node_ptr node);
			void		rightRotate(node_ptr x);
			void		leftRotate(node_ptr node);
			void		rbTransplant(node_ptr a, node_ptr b);

			void		deallocateTree(void);
			void		duplicateTree(redblacktree const &rbt, node_ptr copy);
			void		insertPrimal(value_type const &key, int color);

			class	IndexOutOfBoundsException: public std::exception
			{ virtual const char	*what(void) const throw(); };
	};

	template <class T, class Compare, class Alloc>
	bool	operator==(redblacktree<T, Compare, Alloc> const &a, redblacktree<T, Compare, Alloc> const &b)
	{ return (a.size() == b.size() && ft::equal(a.begin(), a.end(), b.begin())); }

	template <class T, class Compare, class Alloc>
	bool	operator!=(redblacktree<T, Compare, Alloc> const &a, redblacktree<T, Compare, Alloc> const &b)
	{ return (!(a == b)); }

	template <class T, class Compare, class Alloc>
	bool	operator<(redblacktree<T, Compare, Alloc> const &a, redblacktree<T, Compare, Alloc> const &b)
	{ return (ft::lexicographical_compare(a.begin(), a.end(), b.begin(), b.end())); }

	template <class T, class Compare, class Alloc>
	bool	operator>(redblacktree<T, Compare, Alloc> const &a, redblacktree<T, Compare, Alloc> const &b)
	{ return (b < a); }

	template <class T, class Compare, class Alloc>
	bool	operator<=(redblacktree<T, Compare, Alloc> const &a, redblacktree<T, Compare, Alloc> const &b)
	{ return (!(b < a)); }

	template <class T, class Compare, class Alloc>
	bool	operator>=(redblacktree<T, Compare, Alloc> const &a, redblacktree<T, Compare, Alloc> const &b)
	{ return (!(a < b)); }

	template <class T, class Compare, class Alloc>
	void	swap(redblacktree<T, Compare, Alloc> const &a, redblacktree<T, Compare, Alloc> const &b)
	{ a.swap(b); }
}

# include "RedBlackTree.tpp"

#endif
