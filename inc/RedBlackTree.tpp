/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RedBlackTree.tpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:08:37 by jhii              #+#    #+#             */
/*   Updated: 2023/02/07 16:56:26 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDBLACKTREE_TPP
# define REDBLACKTREE_TPP

using namespace ft;

template <class T, class Alloc>
redblacktree<T, Alloc>::redblacktree(node_allocator const &alloc): _alloc(alloc)
{
	// allocate node here
	this->_TNULL = this->_alloc.allocate(1);
	this->_TNULL->color = black;
	this->_TNULL->left = nullptr;
	this->_TNULL->right = nullptr;
	this->_root = this->_TNULL;
}

template <class T, class Alloc>
redblacktree<T, Alloc>::~redblacktree(void)
{
	while (this->_root != this->_TNULL)
		deleteNode(this->_root->data);
	this->_alloc.deallocate(this->_TNULL, 1);
}

template <class T, class Alloc>
void	redblacktree<T, Alloc>::preorder(void)
{
	preOrderHelper(this->_root);
}

template <class T, class Alloc>
void	redblacktree<T, Alloc>::inorder(void)
{
	inOrderHelper(this->_root);
}

template <class T, class Alloc>
void	redblacktree<T, Alloc>::postorder(void)
{
	postOrderHelper(this->_root);
}

template <class T, class Alloc> typename redblacktree<T, Alloc>::node_ptr
redblacktree<T, Alloc>::searchTree(value_type key)
{
	return (searchTreeHelper(this->_root, key));
}

template <class T, class Alloc> typename redblacktree<T, Alloc>::node_ptr
redblacktree<T, Alloc>::minimum(node_ptr node)
{
	while (node->left != this->_TNULL)
		node = node->left;
	return (node);
}

template <class T, class Alloc> typename redblacktree<T, Alloc>::node_ptr
redblacktree<T, Alloc>::maximum(node_ptr node)
{
	while (node->right != this->_TNULL)
		node = node->right;
	return (node);
}

template <class T, class Alloc> typename redblacktree<T, Alloc>::node_ptr
redblacktree<T, Alloc>::successor(node_ptr node)
{
	if (node->right != this->_TNULL)
		return (minimum(node->right));
	
	node_ptr	temp = node->parent;
	while (temp != this->_TNULL && node == temp->right)
	{
		node = temp;
		temp = temp->parent;
	}
	return (temp);
}

template <class T, class Alloc> typename redblacktree<T, Alloc>::node_ptr
redblacktree<T, Alloc>::predecessor(node_ptr node)
{
	if (node->left != this->_TNULL)
		return (minimum(node->left));
	
	node_ptr	temp = node->parent;
	while (temp != this->_TNULL && node == temp->left)
	{
		node = temp;
		temp = temp->parent;
	}
	return (temp);
}

template <class T, class Alloc>
void	redblacktree<T, Alloc>::leftRotate(node_ptr node)
{
	node_ptr temp = node->right;
	node->right = temp->left;
	if (temp->left != this->_TNULL)
		temp->left->parent = node;
	temp->parent = node->parent;
	if (node->parent == nullptr)
		this->_root = temp;
	else if (node == node->parent->left)
		node->parent->left = temp;
	else
		node->parent->right = temp;
	temp->left = node;
	node->parent = temp;
}

template <class T, class Alloc>
void	redblacktree<T, Alloc>::rightRotate(node_ptr node)
{
	node_ptr temp = node->left;
	node->left = temp->right;
	if (temp->right != this->_TNULL)
		temp->right->parent = node;
	temp->parent = node->parent;
	if (node->parent == nullptr)
		this->_root = temp;
	else if (node == node->parent->right)
		node->parent->right = temp;
	else
		node->parent->left = temp;
	temp->right = node;
	node->parent = temp;
}

template <class T, class Alloc> typename redblacktree<T, Alloc>::node_ptr
redblacktree<T, Alloc>::getRoot(void)
{
	return (this->_root);
}

template <class T, class Alloc>
void	redblacktree<T, Alloc>::insert(value_type key)
{
	// allocate node here
	if (searchTree(key)->data == key)
		return ;
	node_ptr	node = this->_alloc.allocate(1);
	node->parent = nullptr;
	node->data = key;
	node->left = this->_TNULL;
	node->right = this->_TNULL;
	node->color = red;

	node_ptr	y = nullptr;
	node_ptr	x = this->_root;

	while (x != this->_TNULL)
	{
		y = x;
		if (node->data < x->data)
			x = x->left;
		else
			x = x->right;
	}
	node->parent = y;
	if (y == nullptr)
		this->_root = node;
	else if (node->data < y->data)
		y->left = node;
	else
		y->right = node;
	if (node->parent == nullptr)
	{
		node->color = black;
		return ;
	}
	if (node->parent->parent == nullptr)
		return ;
	insertFix(node);
}

template <class T, class Alloc>
void	redblacktree<T, Alloc>::deleteNode(value_type data)
{
	deleteNodeHelper(this->_root, data);
}

template <class T, class Alloc>
void	redblacktree<T, Alloc>::printTree(void)
{
	if (this->_root)
		printHelper(this->_root, "", true);
}

template <class T, class Alloc>
void	redblacktree<T, Alloc>::initializeNullNode(node_ptr node, node_ptr parent)
{
	node->data = 0;
	node->parent = parent;
	node->left = nullptr;
	node->right = nullptr;
	node->color = black;
}

template <class T, class Alloc>
void	redblacktree<T, Alloc>::preOrderHelper(node_ptr node)
{
	if (node != this->_TNULL)
	{
		std::cout << node->data << " ";
		preOrderHelper(node->left);
		preOrderHelper(node->right);
	}
}

template <class T, class Alloc>
void	redblacktree<T, Alloc>::inOrderHelper(node_ptr node)
{
	if (node != this->_TNULL)
	{
		inOrderHelper(node->left);
		std::cout << node->data << " ";
		inOrderHelper(node->right);
	}
}

template <class T, class Alloc>
void	redblacktree<T, Alloc>::postOrderHelper(node_ptr node)
{
	if (node != this->_TNULL)
	{
		postOrderHelper(node->left);
		postOrderHelper(node->right);
		std::cout << node->data << " ";
	}
}

template <class T, class Alloc> typename redblacktree<T, Alloc>::node_ptr
redblacktree<T, Alloc>::searchTreeHelper(node_ptr node, value_type key)
{
	if (node == this->_TNULL || key == node->data)
		return (node);
	if (key < node->data)
		return (searchTreeHelper(node->left, key));
	return (searchTreeHelper(node->right, key));
}

template <class T, class Alloc>
void	redblacktree<T, Alloc>::deleteFix(node_ptr node)
{
	node_ptr	temp;
	while (node != this->_root && node->color == black)
	{
		if (node == node->parent->left)
		{
			temp = node->parent->right;
			if (temp->color == red)
			{
				temp->color = black;
				node->parent->color = red;
				leftRotate(node->parent);
				temp = node->parent->right;
			}
			if (temp->left->color == black && temp->right->color == black)
			{
				temp->color = red;
				node = node->parent;
			}
			else
			{
				if (temp->right->color == black)
				{
					temp->left->color = black;
					temp->color = red;
					rightRotate(temp);
					temp = node->parent->right;
				}
				temp->color = node->parent->color;
				node->parent->color = black;
				temp->right->color = black;
				leftRotate(node->parent);
				node = this->_root;
			}
		}
		else
		{
			temp = node->parent->left;
			if (temp->color == red)
			{
				temp->color = black;
				node->parent->color = red;
				rightRotate(node->parent);
				temp = node->parent->left;
			}
			// modified line 119 from the rbt example
			if (temp->right->color == black && temp->left->color == black)
			{
				temp->color = red;
				node = node->parent;
			}
			else
			{
				if (temp->left->color == black)
				{
					temp->right->color = black;
					temp->color = red;
					leftRotate(temp);
					temp = node->parent->left;
				}
				temp->color = node->parent->color;
				node->parent->color = black;
				temp->left->color = black;
				rightRotate(node->parent);
				node = this->_root;
			}
		}
	}
	node->color = black;
}

template <class T, class Alloc>
void	redblacktree<T, Alloc>::rbTransplant(node_ptr a, node_ptr b)
{
	if (a->parent == nullptr)
		this->_root = b;
	else if (a == a->parent->left)
		a->parent->left = b;
	else
		a->parent->right = b;
	b->parent = a->parent;
}

template <class T, class Alloc>
void	redblacktree<T, Alloc>::deleteNodeHelper(node_ptr node, value_type key)
{
	node_ptr	x, y, z;
	z = this->_TNULL;
	while (node != this->_TNULL)
	{
		if (node->data == key)
			z = node;
		if (node->data <= key)
			node = node->right;
		else
			node = node->left;
	}
	if (z == this->_TNULL)
	{
		std::cout << YELLOW "Key not found in the tree" RESET << std::endl;
		return ;
	}
	y = z;
	int	y_original_color = y->color;
	if (z->left == this->_TNULL)
	{
		x = z->right;
		rbTransplant(z, z->right);
	}
	else if (z->right == this->_TNULL)
	{
		x = z->left;
		rbTransplant(z, z->left);
	}
	else
	{
		y = minimum(z->right);
		y_original_color = y->color;
		x = y->right;
		if (y->parent == z)
			x->parent = y;
		else
		{
			rbTransplant(y, y->right);
			y->right = z->right;
			y->right->parent = y;
		}
		rbTransplant(z, y);
		y->left = z->left;
		y->left->parent = y;
		y->color = z->color;
	}
	// deallocate node here
	this->_alloc.deallocate(z, 1);
	if (y_original_color == black)
		deleteFix(x);
}

template <class T, class Alloc>
void	redblacktree<T, Alloc>::insertFix(node_ptr node)
{
	node_ptr	temp;
	while (node->parent->color == red)
	{
		if (node->parent == node->parent->parent->right)
		{
			temp = node->parent->parent->left;
			if (temp->color == red)
			{
				temp->color = black;
				node->parent->color = black;
				node->parent->parent->color = red;
				node = node->parent->parent;
			}
			else
			{
				if (node == node->parent->left)
				{
					node = node->parent;
					rightRotate(node);
				}
				node->parent->color = black;
				node->parent->parent->color = red;
				leftRotate(node->parent->parent);
			}
		}
		else
		{
			temp = node->parent->parent->right;
			if (temp->color == red)
			{
				temp->color = black;
				node->parent->color = black;
				node->parent->parent->color = red;
				node = node->parent->parent;
			}
			else
			{
				if (node == node->parent->right)
				{
					node = node->parent;
					leftRotate(node);
				}
				node->parent->color = black;
				node->parent->parent->color = red;
				rightRotate(node->parent->parent);
			}
		}
		if (node == this->_root)
			break ;
	}
	this->_root->color = black;
}

template <class T, class Alloc>
void	redblacktree<T, Alloc>::printHelper(node_ptr root, std::string indent, bool last)
{
	if (root != this->_TNULL)
	{
		std::cout << CYAN << indent << RESET;
		if (last)
		{
			std::cout << CYAN "R----" RESET;
			indent += "   ";
		}
		else
		{
			std::cout << CYAN "L----" RESET;
			indent += "|  ";
		}
		if (root->color == black)
			std::cout << BLACK << root->data << RESET << std::endl;
		else
			std::cout << RED << root->data << RESET << std::endl;
		printHelper(root->left, indent, false);
		printHelper(root->right, indent, true);
	}
}

#endif
