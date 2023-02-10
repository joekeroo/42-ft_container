/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RedBlackTree.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:11:41 by jhii              #+#    #+#             */
/*   Updated: 2023/02/10 12:57:08 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDBLACKTREE_HPP
# define REDBLACKTREE_HPP

# include "Utils.hpp"

enum	color
{
	black,
	red
};

namespace	ft
{
	template <class T>
	struct	node
	{
		T		*data;
		node	*parent;
		node	*left;
		node	*right;
		int		color;
	};

	template <class T, class Compare = std::less<T>, class Alloc = std::allocator<T> >
	class redblacktree
	{
		public:
			typedef T																value_type;
			typedef node<T>															*node_ptr;
			typedef Compare															value_compare;
			typedef Alloc															allocator_type;
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

			size_t		size(void);
			void		printTree(void);
			void		insert(value_type const &key);
			void		deleteNode(value_type const &key);
			node_ptr	getRoot(void);
			node_ptr	minimum(node_ptr node);
			node_ptr	maximum(node_ptr node);
			node_ptr	searchTree(value_type const &key);

		private:
			size_t			_size;
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

			void		insertFix(node_ptr node);
			void		deleteFix(node_ptr node);
			void		rightRotate(node_ptr x);
			void		leftRotate(node_ptr node);
			void		rbTransplant(node_ptr a, node_ptr b);

			void		deallocateTree(void);
			void		duplicateTree(redblacktree const &rbt, node_ptr copy);
			void		insertPrimal(value_type const &key, int color);
	};
}

# include "RedBlackTree.tpp"

#endif
