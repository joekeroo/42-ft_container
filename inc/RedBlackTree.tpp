/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RedBlackTree.tpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:08:37 by jhii              #+#    #+#             */
/*   Updated: 2023/02/16 18:53:59 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDBLACKTREE_TPP
# define REDBLACKTREE_TPP

using namespace ft;

template <class T, class Compare, class Alloc>
redblacktree<T, Compare, Alloc>::redblacktree(node_allocator const &alloc, value_compare const &comp): _allocNode(alloc), _compare(comp)
{
	this->_size = 0;
	this->_TNULL = this->_allocNode.allocate(1);
	this->_TNULL->color = black;
	this->_TNULL->left = nullptr;
	this->_TNULL->right = nullptr;
	this->_TNULL->isSentinel = true;
	this->_root = this->_TNULL;
}

template <class T, class Compare, class Alloc>
redblacktree<T, Compare, Alloc>::redblacktree(redblacktree const &ref)
{
	this->_size = 0;
	this->_TNULL = this->_allocNode.allocate(1);
	this->_TNULL->color = black;
	this->_TNULL->left = nullptr;
	this->_TNULL->right = nullptr;
	this->_TNULL->isSentinel = true;
	this->_root = this->_TNULL;
	if (ref._size)
		duplicateTree(ref, ref._root);
}

template <class T, class Compare, class Alloc>
redblacktree<T, Compare, Alloc>
&redblacktree<T, Compare, Alloc>::operator=(redblacktree const &ref)
{
	deallocateTree();
	this->_size = 0;
	this->_TNULL = this->_allocNode.allocate(1);
	this->_TNULL->color = black;
	this->_TNULL->left = nullptr;
	this->_TNULL->right = nullptr;
	this->_TNULL->isSentinel = true;
	this->_root = this->_TNULL;
	if (ref._size)
		duplicateTree(ref, ref._root);
	return (*this);
}

template <class T, class Compare, class Alloc>
redblacktree<T, Compare, Alloc>::~redblacktree(void)
{
	deallocateTree();
}

template <class T, class Compare, class Alloc>
void	redblacktree<T, Compare, Alloc>::inorder(void)
{
	inOrderHelper(this->_root);
}

template <class T, class Compare, class Alloc>
void	redblacktree<T, Compare, Alloc>::preorder(void)
{
	preOrderHelper(this->_root);
}

template <class T, class Compare, class Alloc>
void	redblacktree<T, Compare, Alloc>::postorder(void)
{
	postOrderHelper(this->_root);
}

template <class T, class Compare, class Alloc> typename redblacktree<T, Compare, Alloc>::node_ptr
redblacktree<T, Compare, Alloc>::successor(node_ptr node)
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

template <class T, class Compare, class Alloc> typename redblacktree<T, Compare, Alloc>::node_ptr
redblacktree<T, Compare, Alloc>::predecessor(node_ptr node)
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

template <class T, class Compare, class Alloc>
void	redblacktree<T, Compare, Alloc>::printTree(void)
{
	if (this->_root)
		printHelper(this->_root, "", true);
	std::cout << std::endl;
	std::cout << BLUE "size()  : " << this->_size << RESET << std::endl;
	if (this->_size)
	{
		std::cout << BLUE "minimum : " << *(this->_TNULL->left->data) << RESET << std::endl;
		std::cout << BLUE "maximum : " << *(this->_TNULL->right->data) << RESET << std::endl;
	}
}

template <class T, class Compare, class Alloc> typename redblacktree<T, Compare, Alloc>::node_ptr
redblacktree<T, Compare, Alloc>::getRoot(void)
{
	return (this->_root);
}

template <class T, class Compare, class Alloc> typename redblacktree<T, Compare, Alloc>::node_ptr
redblacktree<T, Compare, Alloc>::getTNULL(void)
{
	return (this->_TNULL);
}

template <class T, class Compare, class Alloc> typename redblacktree<T, Compare, Alloc>::node_ptr
redblacktree<T, Compare, Alloc>::minimum(node_ptr node)
{
	while (node->left != this->_TNULL)
		node = node->left;
	return (node);
}

template <class T, class Compare, class Alloc> typename redblacktree<T, Compare, Alloc>::node_ptr
redblacktree<T, Compare, Alloc>::maximum(node_ptr node)
{
	while (node->right != this->_TNULL)
		node = node->right;
	return (node);
}

template <class T, class Compare, class Alloc>
typename redblacktree<T, Compare, Alloc>::node_ptr
redblacktree<T, Compare, Alloc>::searchTree(value_type const &key)
{
	return (searchTreeHelper(this->_root, key));
}

template <class T, class Compare, class Alloc>
void	redblacktree<T, Compare, Alloc>::inOrderHelper(node_ptr node)
{
	if (node != this->_TNULL)
	{
		inOrderHelper(node->left);
		std::cout << *node->data << " ";
		inOrderHelper(node->right);
	} 
}

template <class T, class Compare, class Alloc>
void	redblacktree<T, Compare, Alloc>::preOrderHelper(node_ptr node)
{
	if (node != this->_TNULL)
	{
		std::cout << *node->data << " ";
		preOrderHelper(node->left);
		preOrderHelper(node->right);
	}
}

template <class T, class Compare, class Alloc>
void	redblacktree<T, Compare, Alloc>::postOrderHelper(node_ptr node)
{
	if (node != this->_TNULL)
	{
		postOrderHelper(node->left);
		postOrderHelper(node->right);
		std::cout << *node->data << " ";
	}
}

template <class T, class Compare, class Alloc>
void	redblacktree<T, Compare, Alloc>::printHelper(node_ptr root, std::string indent, bool last)
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
			std::cout << BLACK << *root->data << RESET << std::endl;
		else
			std::cout << RED << *root->data << RESET << std::endl;
		printHelper(root->left, indent, false);
		printHelper(root->right, indent, true);
	}
}

template <class T, class Compare, class Alloc>
typename redblacktree<T, Compare, Alloc>::node_ptr
redblacktree<T, Compare, Alloc>::searchTreeHelper(node_ptr &node, value_type const &key)
{
	if (node == this->_TNULL)
		return (node);
	if (this->_compare(key, *node->data))
		return (searchTreeHelper(node->left, key));
	else if (this->_compare(*node->data, key))
		return (searchTreeHelper(node->right, key));
	return (node);
}

template <class T, class Compare, class Alloc>
void	redblacktree<T, Compare, Alloc>::insertNode(value_type const &key)
{
	if (this->searchTree(key) == this->_TNULL)
	{
		node_ptr	node = this->_allocNode.allocate(1);
		node->data = this->_allocPair.allocate(1);
		this->_allocPair.construct(node->data, key);
		node->parent = nullptr;
		node->left = this->_TNULL;
		node->right = this->_TNULL;
		node->isSentinel = false;
		node->color = red;

		node_ptr	y = nullptr;
		node_ptr	x = this->_root;

		while (x != this->_TNULL)
		{
			y = x;
			if (this->_compare(*node->data, *x->data))
				x = x->left;
			else
				x = x->right;
		}
		node->parent = y;
		if (y == nullptr)
			this->_root = node;
		else if (this->_compare(*node->data, *y->data))
			y->left = node;
		else
			y->right = node;
		this->_size++;
		if (this->_size == 1)
		{
			this->_TNULL->left = this->_root;
			this->_TNULL->right = this->_root;
		}
		else
		{
			if (this->_compare(*node->data, *(this->_TNULL->left->data)))
				this->_TNULL->left = node;
			else if (this->_compare(*(this->_TNULL->right->data), *node->data))
				this->_TNULL->right = node;
		}
		if (node->parent == nullptr)
		{
			node->color = black;
			return ;
		}
		if (node->parent->parent == nullptr)
			return ;
		insertFix(node);
	}
	else
	{
		node_ptr	node;

		node = searchTree(key);
		this->_allocPair.destroy(node->data);
		this->_allocPair.deallocate(node->data, 1);
		node->data = this->_allocPair.allocate(1);
		this->_allocPair.construct(node->data, key);
	}
}

template <class T, class Compare, class Alloc>
void	redblacktree<T, Compare, Alloc>::eraseNode(value_type const &key)
{
	node_ptr	x, y, z;

	z = this->searchTree(key);
	if (z == this->_TNULL)
		return ;
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
	this->_size--;
	if (this->_size == 0)
	{
		this->_TNULL->left = nullptr;
		this->_TNULL->right = nullptr;
	}
	else
	{
		if (this->_TNULL->left == z)
			this->_TNULL->left = z->parent;
		else if (this->_TNULL->right == z)
			this->_TNULL->right = z->parent;
	}
	this->_allocPair.destroy(z->data);
	this->_allocPair.deallocate(z->data, 1);
	this->_allocNode.deallocate(z, 1);
	if (y_original_color == black)
		deleteFix(x);
}

template <class T, class Compare, class Alloc>
void	redblacktree<T, Compare, Alloc>::insertFix(node_ptr node)
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

template <class T, class Compare, class Alloc>
void	redblacktree<T, Compare, Alloc>::deleteFix(node_ptr node)
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

template <class T, class Compare, class Alloc>
void	redblacktree<T, Compare, Alloc>::rightRotate(node_ptr node)
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

template <class T, class Compare, class Alloc>
void	redblacktree<T, Compare, Alloc>::leftRotate(node_ptr node)
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

template <class T, class Compare, class Alloc>
void	redblacktree<T, Compare, Alloc>::rbTransplant(node_ptr a, node_ptr b)
{
	if (a->parent == nullptr)
		this->_root = b;
	else if (a == a->parent->left)
		a->parent->left = b;
	else
		a->parent->right = b;
	b->parent = a->parent;
}

template <class T, class Compare, class Alloc>
void	redblacktree<T, Compare, Alloc>::deallocateTree(void)
{
	while (this->_root != this->_TNULL)
		eraseNode(*this->_root->data);
	this->_allocNode.deallocate(this->_TNULL, 1);
}

template <class T, class Compare, class Alloc>
void	redblacktree<T, Compare, Alloc>::duplicateTree(redblacktree const &rbt, node_ptr copy)
{
	if (copy != rbt._TNULL)
	{
		this->_size++;
		this->insertPrimal(*copy->data, copy->color);
		duplicateTree(rbt, copy->left);
		duplicateTree(rbt, copy->right);
	}
}

template <class T, class Compare, class Alloc>
void	redblacktree<T, Compare, Alloc>::insertPrimal(value_type const &key, int color)
{
	node_ptr	node = this->_allocNode.allocate(1);
	node->data = this->_allocPair.allocate(1);
	this->_allocPair.construct(node->data, key);
	node->parent = nullptr;
	node->left = this->_TNULL;
	node->right = this->_TNULL;
	node->isSentinel = false;
	node->color = color;

	node_ptr	y = nullptr;
	node_ptr	x = this->_root;

	while (x != this->_TNULL)
	{
		y = x;
		if (this->_compare(*node->data, *x->data))
			x = x->left;
		else
			x = x->right;
	}
	node->parent = y;
	if (y == nullptr)
		this->_root = node;
	else if (this->_compare(*node->data, *y->data))
		y->left = node;
	else
		y->right = node;
	if (this->_size == 1)
	{
		this->_TNULL->left = this->_root;
		this->_TNULL->right = this->_root;
	}
	else
	{
		if (this->_compare(*node->data, *(this->_TNULL->left->data)))
			this->_TNULL->left = node;
		else if (this->_compare(*(this->_TNULL->right->data), *node->data))
			this->_TNULL->right = node;
	}
	if (node->parent == nullptr)
		return ;
	if (node->parent->parent == nullptr)
		return ;
}

template <class T, class Compare, class Alloc> const char
*redblacktree<T, Compare, Alloc>::IndexOutOfBoundsException::what(void) const throw()
{
	return (YELLOW "Error: key not found" RESET);
}

template <class T, class Compare, class Alloc>
typename redblacktree<T, Compare, Alloc>::iterator
redblacktree<T, Compare, Alloc>::begin(void)
{
	return (iterator(this->_TNULL->left));
}

template <class T, class Compare, class Alloc>
typename redblacktree<T, Compare, Alloc>::const_iterator
redblacktree<T, Compare, Alloc>::begin(void) const
{
	return (const_iterator(this->_TNULL->left));
}

template <class T, class Compare, class Alloc>
typename redblacktree<T, Compare, Alloc>::iterator
redblacktree<T, Compare, Alloc>::end(void)
{
	return (iterator(this->_TNULL));
}

template <class T, class Compare, class Alloc>
typename redblacktree<T, Compare, Alloc>::const_iterator
redblacktree<T, Compare, Alloc>::end(void) const
{
	return (const_iterator(this->_TNULL));
}

template <class T, class Compare, class Alloc>
typename redblacktree<T, Compare, Alloc>::reverse_iterator
redblacktree<T, Compare, Alloc>::rbegin(void)
{
	return (reverse_iterator(this->_TNULL));
}

template <class T, class Compare, class Alloc>
typename redblacktree<T, Compare, Alloc>::const_reverse_iterator
redblacktree<T, Compare, Alloc>::rbegin(void) const
{
	return (const_reverse_iterator(this->_TNULL));
}

template <class T, class Compare, class Alloc>
typename redblacktree<T, Compare, Alloc>::reverse_iterator
redblacktree<T, Compare, Alloc>::rend(void)
{
	return (reverse_iterator(this->_TNULL->left));
}

template <class T, class Compare, class Alloc>
typename redblacktree<T, Compare, Alloc>::const_reverse_iterator
redblacktree<T, Compare, Alloc>::rend(void) const
{
	return (const_reverse_iterator(this->_TNULL->left));
}

template <class T, class Compare, class Alloc>
ft::pair<typename redblacktree<T, Compare, Alloc>::iterator, bool>
redblacktree<T, Compare, Alloc>::insert(value_type const &key)
{
	if (searchTree(key) == this->_TNULL)
	{
		insertNode(key);
		ft::pair<iterator, bool> temp(find(key), true);
		return (temp);
	}
	else
	{
		insertNode(key);
		ft::pair<iterator, bool> temp(find(key), false);
		return (temp);
	}
}

template <class T, class Compare, class Alloc>
typename redblacktree<T, Compare, Alloc>::iterator
redblacktree<T, Compare, Alloc>::insert(iterator it, value_type const &key)
{
	(void)it;
	insertNode(key);
	return (find(key));
}

template <class T, class Compare, class Alloc>
template <class InputIterator> void
redblacktree<T, Compare, Alloc>::insert(InputIterator first, InputIterator last)
{
	for (InputIterator it = first; it != last; ++it)
		insert(*it);
}

template <class T, class Compare, class Alloc>
void	redblacktree<T, Compare, Alloc>::erase(iterator it)
{
	if (it != end())
		eraseNode(*it);
}

template <class T, class Compare, class Alloc>
typename redblacktree<T, Compare, Alloc>::size_type
redblacktree<T, Compare, Alloc>::erase(value_type const &key)
{
	eraseNode(key);
	return (this->_size);
}

template <class T, class Compare, class Alloc>
void	redblacktree<T, Compare, Alloc>::erase(iterator first, iterator last)
{
	while (first != last)
		eraseNode(*first++);
}

template <class T, class Compare, class Alloc>
bool	redblacktree<T, Compare, Alloc>::empty(void) const
{
	if (this->_size)
		return (true);
	return (false);
}

template <class T, class Compare, class Alloc>
size_t	redblacktree<T, Compare, Alloc>::size(void) const
{
	return (this->_size);
}

template <class T, class Compare, class Alloc>
size_t	redblacktree<T, Compare, Alloc>::max_size(void) const
{
	return (this->_allocNode.max_size());
}

template <class T, class Compare, class Alloc>
typename redblacktree<T, Compare, Alloc>::value_type
&redblacktree<T, Compare, Alloc>::operator[](value_type const &key)
{
	if (searchTree(key) == this->_TNULL)
		insertNode(key);
	return (*(searchTree(key)->data));
}

template <class T, class Compare, class Alloc>
typename redblacktree<T, Compare, Alloc>::value_type
&redblacktree<T, Compare, Alloc>::at(value_type const &key)
{
	if (searchTree(key) == this->_TNULL)
		throw(IndexOutOfBoundsException());
	return (*(searchTree(key)->data));
}

template <class T, class Compare, class Alloc>
void	redblacktree<T, Compare, Alloc>::swap(redblacktree &ref)
{
	redblacktree<T, Compare, Alloc>	temp(ref);
	ref = *this;
	*this = temp;
}

template <class T, class Compare, class Alloc>
void	redblacktree<T, Compare, Alloc>::clear(void)
{
	while (this->_root != this->_TNULL)
		eraseNode(*this->_root->data);
}

template <class T, class Compare, class Alloc>
typename redblacktree<T, Compare, Alloc>::value_compare
redblacktree<T, Compare, Alloc>::value_comp(void) const
{
	return (this->_compare);
}

template <class T, class Compare, class Alloc>
typename redblacktree<T, Compare, Alloc>::iterator
redblacktree<T, Compare, Alloc>::find(value_type const &key)
{
	for (iterator it = begin(); it != end(); ++it)
	{
		if (key == *it)
			return (it);
	}
	return (end());
}

template <class T, class Compare, class Alloc>
typename redblacktree<T, Compare, Alloc>::const_iterator
redblacktree<T, Compare, Alloc>::find(value_type const &key) const
{
	for (const_iterator it = begin(); it != end(); ++it)
	{
		if (key == *it)
			return (it);
	}
	return (end());
}

template <class T, class Compare, class Alloc>
typename redblacktree<T, Compare, Alloc>::size_type
redblacktree<T, Compare, Alloc>::count(value_type const &key) const
{
	if (searchTree(key) == this->_TNULL)
		return (0);
	return (1);
}

template <class T, class Compare, class Alloc>
typename redblacktree<T, Compare, Alloc>::iterator
redblacktree<T, Compare, Alloc>::lower_bound(value_type const &key)
{
	for (iterator it = begin(); it != end(); ++it)
	{
		if (this->_compare(*it, key))
			continue ;
		else
			return (it);
	}
	return (end());
}

template <class T, class Compare, class Alloc>
typename redblacktree<T, Compare, Alloc>::const_iterator
redblacktree<T, Compare, Alloc>::lower_bound(value_type const &key) const
{
	for (const_iterator it = begin(); it != end(); ++it)
	{
		if (this->_compare(*it, key))
			continue ;
		else
			return (it);
	}
	return (end());
}

template <class T, class Compare, class Alloc>
typename redblacktree<T, Compare, Alloc>::iterator
redblacktree<T, Compare, Alloc>::upper_bound(value_type const &key)
{
	for (iterator it = begin(); it != end(); ++it)
	{
		if (this->_compare(key, *it))
			return (it);
		else
			continue ;
	}
	return (end());
}

template <class T, class Compare, class Alloc>
typename redblacktree<T, Compare, Alloc>::const_iterator
redblacktree<T, Compare, Alloc>::upper_bound(value_type const &key) const
{
	for (const_iterator it = begin(); it != end(); ++it)
	{
		if (this->_compare(key, *it))
			return (it);
		else
			continue ;
	}
	return (end());
}

template <class T, class Compare, class Alloc>
ft::pair<typename redblacktree<T, Compare, Alloc>::iterator, typename redblacktree<T, Compare, Alloc>::iterator>
redblacktree<T, Compare, Alloc>::equal_range(value_type const &key)
{
	ft::pair<iterator, iterator>	temp(lower_bound(key), upper_bound(key));
	return (temp);
}

template <class T, class Compare, class Alloc>
ft::pair<typename redblacktree<T, Compare, Alloc>::const_iterator, typename redblacktree<T, Compare, Alloc>::const_iterator>
redblacktree<T, Compare, Alloc>::equal_range(value_type const &key) const
{
	ft::pair<const_iterator, const_iterator>	temp(lower_bound(key), upper_bound(key));
	return (temp);
}

template <class T, class Compare, class Alloc>
typename redblacktree<T, Compare, Alloc>::allocator_type
redblacktree<T, Compare, Alloc>::get_allocator(void) const
{
	return (this->_allocPair);
}

#endif
