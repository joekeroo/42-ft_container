/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RedBlackTree.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:11:41 by jhii              #+#    #+#             */
/*   Updated: 2023/02/07 16:56:02 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDBLACKTREE_HPP
# define REDBLACKTREE_HPP

# include "Utils.hpp"
# include "Pair.hpp"

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
		T		data;
		node	*parent;
		node	*left;
		node	*right;
		int		color;
	};


	template <class T, class Alloc = std::allocator<T> >
	class redblacktree
	{
		public:
			typedef T																value_type;
			typedef node<T>															*node_ptr;
			typedef typename Alloc::template rebind<ft::node<value_type> >::other	node_allocator;

			redblacktree(node_allocator const &alloc = node_allocator());
			~redblacktree(void);

			void		preorder(void);
			void		inorder(void);
			void		postorder(void);
			node_ptr	searchTree(value_type key);
			node_ptr	minimum(node_ptr node);
			node_ptr	maximum(node_ptr node);
			node_ptr	successor(node_ptr node);
			node_ptr	predecessor(node_ptr node);
			node_ptr	getRoot(void);
			void		leftRotate(node_ptr node);
			void		rightRotate(node_ptr x);
			void		insert(value_type key);
			void		deleteNode(value_type data);
			void		printTree(void);

		private:
			node_ptr		_root;
			node_ptr		_TNULL;
			node_allocator	_alloc;

			void		initializeNullNode(node_ptr node, node_ptr parent);
			void		preOrderHelper(node_ptr node);
			void		inOrderHelper(node_ptr node);
			void		postOrderHelper(node_ptr node);

			node_ptr	searchTreeHelper(node_ptr node, value_type key);
			void		deleteFix(node_ptr node);
			void		rbTransplant(node_ptr a, node_ptr b);
			void		deleteNodeHelper(node_ptr node, value_type key);
			void		insertFix(node_ptr	node);
			void		printHelper(node_ptr root, std::string indent, bool last);
	};
}

# include "RedBlackTree.tpp"

#endif
