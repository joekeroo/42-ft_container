/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:48:08 by jhii              #+#    #+#             */
/*   Updated: 2023/02/22 19:49:20 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_TPP
# define VECTOR_TPP

using namespace	ft;

template <class T, class Alloc>
vector<T, Alloc>::vector(allocator_type const &alloc): _size(0), _capacity(0), _arr(NULL), _alloc(alloc)
{
	// std::cout << GREEN "Vector constructor called" RESET << std::endl;
}

template <class T, class Alloc>
vector<T, Alloc>::vector(size_type n, value_type const &value, allocator_type const &alloc): _alloc(alloc)
{
	// std::cout << GREEN "Vector constructor called" RESET << std::endl;
	this->_size = n;
	this->_capacity = n;
	if (this->_size > 0)
	{
		this->_arr = this->_alloc.allocate(this->_size);
		for (size_t i = 0; i < this->_size; ++i)
			this->_alloc.construct(this->_arr + i, value);
	}
	else if (this->_size == 0)
		this->_arr = NULL;
}

template <class T, class Alloc>
template <class InputIterator>
vector<T, Alloc>::vector(InputIterator first, InputIterator last, allocator_type const &alloc, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type*): _alloc(alloc)
{
	// std::cout << GREEN "Vector constructor called" RESET << std::endl;
	size_t	size = 0;
	for (InputIterator it = first; it != last; ++it)
		size++;
	if (size > 0)
	{
		this->_size = size;
		this->_capacity = this->_size;
		this->_arr = this->_alloc.allocate(this->_capacity);
		size_t i = 0;
		for (InputIterator it = first; it != last; ++it)
			this->_alloc.construct(this->_arr + i++, *it);
	}
	else
	{
		this->_size = 0;
		this->_capacity = 0;
		this->_arr = NULL;
	}
}

template <class T, class Alloc>
vector<T, Alloc>::vector(vector<typename std::remove_const<value_type>::type> const &ref): _size(ref.size()), _capacity(ref.capacity()), _alloc(allocator_type())
{
	// std::cout << GREEN "Vector copy constructor called" RESET << std::endl;
	if (this->_size > 0)
	{
		this->_arr = this->_alloc.allocate(this->_capacity);
		for (size_t i = 0; i < this->_size; ++i)
			this->_alloc.construct(this->_arr + i, *(ref._arr + i));
	}
	else if (this->_size == 0)
		this->_arr = NULL;
}

template <class T, class Alloc> vector<T, Alloc>
&vector<T, Alloc>::operator=(vector<typename std::remove_const<value_type>::type> const &ref)
{
	// std::cout << GREEN "Vector copy assignment operator called" RESET << std::endl;
	if (this->_capacity)
	{
		for (size_t i = 0; i < this->_size; ++i)
			this->_alloc.destroy(this->_arr + i);
		this->_alloc.deallocate(this->_arr, this->_capacity);
	}
	this->_size = ref._size;
	this->_capacity = ref._capacity;
	this->_alloc = allocator_type();
	if (this->_size > 0)
	{
		this->_arr = this->_alloc.allocate(this->_capacity);
		for (size_t i = 0; i < this->_size; ++i)
			this->_alloc.construct(this->_arr + i, *(ref._arr + i));
	}
	else if (this->_size == 0)
		this->_arr = NULL;
	return (*this);
}

template <class T, class Alloc>
vector<T, Alloc>::~vector(void)
{
	// std::cout << RED "Vector Destructor called" RESET << std::endl;
	if (this->_capacity > 0)
	{
		for (size_t i = 0; i < this->_size; ++i)
			this->_alloc.destroy(this->_arr + i);
		this->_alloc.deallocate(this->_arr, this->_capacity);
	}
}

template <class T, class Alloc> typename vector<T, Alloc>::iterator
vector<T, Alloc>::begin(void)
{
	return (typename vector<T, Alloc>::iterator(this->_arr));
}

template <class T, class Alloc> typename vector<T, Alloc>::const_iterator
vector<T, Alloc>::begin(void) const
{
	return (typename vector<T, Alloc>::const_iterator(this->_arr));
}

template <class T, class Alloc> typename vector<T, Alloc>::iterator
vector<T, Alloc>::end(void)
{
	return (typename vector<T, Alloc>::iterator(this->_arr + this->_size));
}

template <class T, class Alloc> typename vector<T, Alloc>::const_iterator
vector<T, Alloc>::end(void) const
{
	return (typename vector<T, Alloc>::const_iterator(this->_arr + this->_size));
}

template <class T, class Alloc> typename vector<T, Alloc>::reverse_iterator
vector<T, Alloc>::rbegin(void)
{
	return (typename vector<T, Alloc>::reverse_iterator(this->_arr + this->_size));
}

template <class T, class Alloc> typename vector<T, Alloc>::const_reverse_iterator
vector<T, Alloc>::rbegin(void) const
{
	return (typename vector<T, Alloc>::const_reverse_iterator(this->_arr + this->_size));
}

template <class T, class Alloc> typename vector<T, Alloc>::reverse_iterator
vector<T, Alloc>::rend(void)
{
	return (typename vector<T, Alloc>::reverse_iterator(this->_arr));
}

template <class T, class Alloc> typename vector<T, Alloc>::const_reverse_iterator
vector<T, Alloc>::rend(void) const
{
	return (typename vector<T, Alloc>::const_reverse_iterator(this->_arr));
}

template <class T, class Alloc> typename vector<T, Alloc>::value_type
&vector<T, Alloc>::operator[](int n)
{
	return (this->_arr[n]);
}

template <class T, class Alloc>
typename vector<T, Alloc>::allocator_type
vector<T, Alloc>::get_allocator(void) const
{
	return (this->_alloc);
}

template <class T, class Alloc> typename vector<T, Alloc>::size_type
vector<T, Alloc>::size(void) const
{
	return (this->_size);
}

template <class T, class Alloc> typename vector<T, Alloc>::size_type
vector<T, Alloc>::max_size(void) const
{
	return (this->_alloc.max_size());
}

template <class T, class Alloc> void
vector<T, Alloc>::resize(size_type n, value_type val)
{
	if (n == 0)
	{
		for (size_t i = this->_size - 1; i > n; --i)
			this->_alloc.destroy(this->_arr + i);
		this->_size = n;
	}
	else if (n < this->_size)
	{
		for (size_t i = this->_size - 1; i >= n; --i)
			this->_alloc.destroy(this->_arr + i);
		this->_size = n;
	}
	else if (n > this->_size)
	{
		T	*arr = new T[this->_size];
		for (size_t i = 0; i < this->_size; ++i)
			arr[i] = this->_arr[i];
		for (size_t i = 0; i < this->_size; ++i)
			this->_alloc.destroy(this->_arr + i);
		this->_alloc.deallocate(this->_arr, this->_capacity);
		while (n > this->_capacity)
			this->_capacity = this->_capacity * 2;
		this->_arr = this->_alloc.allocate(this->_capacity);
		for (size_t i = 0; i < this->_size; ++i)
			this->_alloc.construct(this->_arr + i, arr[i]);
		for (size_t i = this->_size; i < n; ++i)
			this->_alloc.construct(this->_arr + i, val);
		this->_size = n;
		delete[] arr;
	}
}

template <class T, class Alloc> typename vector<T, Alloc>::size_type
vector<T, Alloc>::capacity(void) const
{
	return (this->_capacity);
}

template <class T, class Alloc> bool
vector<T, Alloc>::empty(void) const
{
	return (this->_size == 0);
}

template <class T, class Alloc> void
vector<T, Alloc>::reserve(size_type n)
{
	if (n > this->_capacity)
	{
		T	*arr = new T[this->_size];
		for (size_t i = 0; i < this->_size; ++i)
			arr[i] = this->_arr[i];
		for (size_t i = 0; i < this->_size; ++i)
			this->_alloc.destroy(this->_arr + i);
		this->_alloc.deallocate(this->_arr, this->_capacity);
		this->_capacity = n;
		this->_arr = this->_alloc.allocate(this->_capacity);
		for (size_t i = 0; i < this->_size; ++i)
			this->_alloc.construct(this->_arr + i, arr[i]);
		delete[] arr;
	}
}

template <class T, class Alloc> void
vector<T, Alloc>::shrink_to_fit(void)
{
	if (this->_capacity > this->_size)
	{
		T	*arr = new T[this->_size];
		for (size_t i = 0; i < this->_size; ++i)
			arr[i] = this->_arr[i];
		for (size_t i = 0; i < this->_size; ++i)
			this->_alloc.destroy(this->_arr + i);
		this->_alloc.deallocate(this->_arr, this->_capacity);
		this->_capacity = this->_size;
		this->_arr = this->_alloc.allocate(this->_capacity);
		for (size_t i = 0; i < this->_size; ++i)
			this->_alloc.construct(this->_arr + i, arr[i]);
		delete[] arr;
	}
}

template <class T, class Alloc> typename vector<T, Alloc>::reference
vector<T, Alloc>::at(size_t n) const
{
	if (n > this->_size)
		throw (std::out_of_range(""));
	return (this->_arr[n]);
}

template <class T, class Alloc> typename vector<T, Alloc>::reference
vector<T, Alloc>::front(void) const
{
	return (this->_arr[0]);
}

template <class T, class Alloc> typename vector<T, Alloc>::reference
vector<T, Alloc>::back(void) const
{
	return (this->_arr[this->_size - 1]);
}

template <class T, class Alloc> typename vector<T, Alloc>::value_type
*vector<T, Alloc>::data(void)
{
	return (this->_arr);
}

template <class T, class Alloc>
template <class InputIterator> void
vector<T, Alloc>::assign(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type*)
{
	size_t	size = 0;
	for (InputIterator it = first; it != last; ++it)
		size++;
	value_type		*arr = new value_type[size];
	size_t j = 0;
	for (InputIterator it = first; it != last; ++it)
		arr[j++] = *it;
	this->_size = size;
	if (this->_size > this->_capacity)
		this->_capacity = this->_size;
	this->_arr = this->_alloc.allocate(this->_capacity);
	for (size_t i = 0; i < this->_size; ++i)
		this->_alloc.construct(this->_arr + i, arr[i]);
	delete[] arr;
}

template <class T, class Alloc> void
vector<T, Alloc>::assign(size_type n, value_type const &val)
{
	for (size_t i = 0; i < this->_size; ++i)
		this->_alloc.destroy(this->_arr + i);
	this->_alloc.deallocate(this->_arr, this->_capacity);
	this->_size = n;
	if (this->_size > this->_capacity)
		this->_capacity = this->_size;
	this->_arr = this->_alloc.allocate(this->_capacity);
	for (size_t i = 0; i < this->_size; ++i)
		this->_alloc.construct(this->_arr + i, val);
}

template <class T, class Alloc> void
vector<T, Alloc>::push_back(value_type const &value)
{
	if (this->_capacity == 0)
	{
		this->_capacity = 1;
		this->_arr = this->_alloc.allocate(this->_capacity);
		this->_alloc.construct(this->_arr, value);
	}
	else if (this->_size == this->_capacity && this->_capacity != 0)
	{
		T	*arr = new T[this->_size];
		for (size_t i = 0; i < this->_size; ++i)
			arr[i] = this->_arr[i];
		for (size_t i = 0; i < this->_size; ++i)
			this->_alloc.destroy(this->_arr + i);
		this->_alloc.deallocate(this->_arr, this->_capacity);
		this->_capacity = this->_capacity * 2;
		this->_arr = this->_alloc.allocate(this->_capacity);
		for (size_t i = 0; i < this->_size; ++i)
			this->_alloc.construct(this->_arr + i, arr[i]);
		this->_alloc.construct(this->_arr + this->_size, value);
		delete[] arr;
	}
	else if (this->_size < this->_capacity)
		this->_alloc.construct(this->_arr + this->_size, value);
	this->_size++;
}

template <class T, class Alloc> void
vector<T, Alloc>::pop_back(void)
{
	--this->_size;
	if (this->_size >= 0)
		this->_alloc.destroy(this->_arr + this->_size);
}

template <class T, class Alloc>
template <class InputIterator> void
vector<T, Alloc>::insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type*)
{
	size_type		size = this->_size;
	size_type		diff = 0;
	difference_type	index = position - this->begin();

	for (InputIterator it = first; it != last; ++it)
		diff++;
	T	*arr = new T[this->_size];
	for (size_t i = 0; i < this->_size; ++i)
		arr[i] = this->_arr[i];
	T	*temp = new T[diff];
	size_t j = 0;
	for (InputIterator it = first; it != last; ++it)
		temp[j++] = *it;
	for (size_t i = 0; i < size; ++i)
		this->pop_back();
	for (size_t i = 0; i < (size_t)index; ++i)
		this->push_back(arr[i]);
	for (size_t i = 0; i < diff; ++i)
		this->push_back(temp[i]);
	for (size_t i = (size_t)index; i < size; ++i)
		this->push_back(arr[i]);
	delete[] arr;
	delete[] temp;
}

template <class T, class Alloc> void
vector<T, Alloc>::insert(iterator position, size_type n, typename vector<T, Alloc>::value_type const &val)
{
	size_type		size = this->_size;
	difference_type	index = position - this->begin();

	T	*arr = new T[this->_size];
	for (size_t i = 0; i < this->_size; ++i)
		arr[i] = this->_arr[i];
	for (size_t i = 0; i < size; ++i)
		this->pop_back();
	for (size_t i = 0; i < (size_t)index; ++i)
		this->push_back(arr[i]);
	for (size_t i = 0; i < n; ++i)
		this->push_back(val);
	for (size_t i = (size_t)index; i < size; ++i)
		this->push_back(arr[i]);
	delete[] arr;
}

template <class T, class Alloc> typename vector<T, Alloc>::iterator
vector<T, Alloc>::insert(iterator position, value_type const &val)
{
	size_type		size = this->_size;
	difference_type	index = position - this->begin();

	T	*arr = new T[this->_size];
	for (size_t i = 0; i < this->_size; ++i)
		arr[i] = this->_arr[i];
	for (size_t i = 0; i < size; ++i)
		this->pop_back();
	for (size_t i = 0; i < (size_t)index; ++i)
		this->push_back(arr[i]);
	this->push_back(val);
	for (size_t i = (size_t)index; i < size; ++i)
		this->push_back(arr[i]);
	delete[] arr;
	return (this->begin() + index);
}

template <class T, class Alloc> typename vector<T, Alloc>::iterator
vector<T, Alloc>::erase(iterator position)
{
	for (iterator it = position; it != this->end() - 1; it++)
		*it = *(it + 1);
	this->_alloc.destroy(this->_arr + --this->_size);
	return (position);
}

template <class T, class Alloc> typename vector<T, Alloc>::iterator
vector<T, Alloc>::erase(iterator first, iterator last)
{
	difference_type	diff = first - last;
	difference_type	index = last - this->begin();
	for (iterator it = last; it != this->end(); it++)
		*(it - diff) = *(it);
	for (difference_type i = 1; i <= diff; ++i)
		this->_alloc.destroy(this->_arr + this->_size - i);
	this->_size -= (size_t)diff;
	return (this->begin() + index);
}

template <class T, class Alloc> void
vector<T, Alloc>::swap(vector<T, Alloc> &ref)
{
	std::swap(this->_size, ref._size);
	std::swap(this->_capacity, ref._capacity);
	std::swap(this->_arr, ref._arr);
	std::swap(this->_alloc, ref._alloc);
}

template <class T, class Alloc> void
vector<T, Alloc>::clear(void)
{
	size_t	temp = this->_size;
	for (size_t i = 0; i < temp; ++i)
		this->pop_back();
}

#endif
