/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:25:17 by jhii              #+#    #+#             */
/*   Updated: 2023/02/22 15:11:23 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iterator>
# include "Iterator.hpp"
# include "reverse_Iterator.hpp"
# include "is_integral.hpp"
# include "Algorithm.hpp"

namespace	ft
{
	// template <class Category, class T, 
	// 	class Distance = std::ptrdiff_t, class Pointer = T*, class Reference = T&>
	// struct iterator;

	template <class T, class Alloc = std::allocator<T> >
	class vector
	{
		public:
			typedef T											value_type;
			typedef Alloc										allocator_type;
			typedef size_t										size_type;
			typedef ptrdiff_t									difference_type;
			typedef randomAccessIterator<value_type>			iterator;
			typedef randomAccessIterator<const value_type>		const_iterator;
			typedef reverse_iterator<iterator>					reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;

			explicit	vector(allocator_type const &alloc = allocator_type());
			explicit	vector(size_type n, value_type const &value = value_type(), allocator_type const &alloc = allocator_type());
			template <class InputIterator>
			vector(InputIterator first, InputIterator last, allocator_type const &alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0);
			vector(vector<typename std::remove_const<value_type>::type> const &);
			~vector(void);

			vector			&operator=(vector<typename std::remove_const<value_type>::type> const &);

			iterator		begin(void);
			const_iterator	begin(void) const;
			iterator		end(void);
			const_iterator	end(void) const;

			reverse_iterator		rbegin(void);
			const_reverse_iterator	rbegin(void) const;
			reverse_iterator		rend(void);
			const_reverse_iterator	rend(void) const;

			size_type		size(void) const;
			size_type		max_size(void) const;
			size_type		capacity(void) const;
			void			resize(size_type, value_type val = value_type());
			bool			empty(void) const;
			void			reserve(size_type);
			void			shrink_to_fit(void);

			value_type		&operator[](int);
			reference		at(size_t) const;
			reference		front(void) const;
			reference		back(void) const;
			value_type		*data(void);

			template <class InputIterator>
			void			assign(InputIterator, InputIterator, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0);
			void			assign(size_type, value_type const &);
			void			push_back(value_type const &);
			void			pop_back(void);
			template <class InputIterator>
			void			insert(iterator, InputIterator, InputIterator, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0);
			void			insert(iterator, size_type, value_type const &);
			iterator		insert(iterator, value_type const &);
			iterator		erase(iterator);
			iterator		erase(iterator, iterator);
			void			swap(vector &);
			void			clear(void);

			allocator_type	get_allocator(void) const;

			size_type		_size;
			size_type		_capacity;
			value_type		*_arr;
			allocator_type	_alloc;
	};

	template <class T, class Alloc>
	void	swap(vector<T, Alloc> &a, vector<T, Alloc> &b)
	{ a.swap(b); }

	template <class T, class Alloc>
	bool	operator==(vector<T, Alloc> const &a, vector<T, Alloc> const &b)
	{ return (a.size() == b.size() && ft::equal(a.begin(), a.end(), b.begin())); }

	template <class T, class Alloc>
	bool	operator!=(vector<T, Alloc> const &a, vector<T, Alloc> const &b)
	{ return (!(a == b)); }

	template <class T, class Alloc>
	bool	operator<(vector<T, Alloc> const &a, vector<T, Alloc> const &b)
	{ return (ft::lexicographical_compare(a.begin(), a.end(), b.begin(), b.end())); }

	template <class T, class Alloc>
	bool	operator>(vector<T, Alloc> const &a, vector<T, Alloc> const &b)
	{ return (b < a); }

	template <class T, class Alloc>
	bool	operator<=(vector<T, Alloc> const &a, vector<T, Alloc> const &b)
	{ return (!(b < a)); }

	template <class T, class Alloc>
	bool	operator>=(vector<T, Alloc> const &a, vector<T, Alloc> const &b)
	{ return (!(a < b)); }
}

# include "Vector.tpp"

#endif
