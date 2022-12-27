/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 19:20:08 by jhii              #+#    #+#             */
/*   Updated: 2022/12/16 19:02:24 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

# include "Utils.hpp"

namespace	ft
{
	template <bool Cond, class T = void> struct enable_if {};
	template <class T> struct enable_if<true, T> { typedef T	type; };

	template <class T, T v>
	struct integral_constant
	{
		static const T					value = v;
		typedef T						value_type;
		typedef integral_constant<T,v>	type;
		operator T() const { return v; }
	};

	typedef integral_constant<bool,true>	true_type;
	typedef integral_constant<bool,false>	false_type;

	template <class T> struct is_integral : false_type {};
	template <> struct is_integral <bool> : true_type {};
	template <> struct is_integral <char> : true_type {};
	template <> struct is_integral <char16_t> : true_type {};
	template <> struct is_integral <char32_t> : true_type {};
	template <> struct is_integral <wchar_t> : true_type {};
	template <> struct is_integral <signed char> : true_type {};
	template <> struct is_integral <short int> : true_type {};
	template <> struct is_integral <int> : true_type {};
	template <> struct is_integral <long int> : true_type {};
	template <> struct is_integral <unsigned char> : true_type {};
	template <> struct is_integral <unsigned short int> : true_type {};
	template <> struct is_integral <unsigned int> : true_type {};
	template <> struct is_integral <unsigned long int> : true_type {};
}

#endif
