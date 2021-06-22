/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerrer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 19:56:00 by aguerrer          #+#    #+#             */
/*   Updated: 2021/06/15 19:56:01 by aguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pointer_numlen(unsigned long long n, int radix)
{
	unsigned long long	ret;

	ret = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		ret++;
		n /= radix;
	}
	return (ret);
}

int	print_pointer(unsigned long long n, t_info info, int radix, int *result)
{
	int		len;

	len = ft_pointer_numlen(n, radix) + 2;
	if (n == (unsigned long long) NULL && info.is_dot == 1 \
							&& info.precision >= 0)
	{
		len--;
		radix = 15;
	}
	if (info.flag == 0)
		return (print_leftize_pointer(n, info, radix, result));
	while (info.width - len > 0 && info.width - info.precision > 0)
	{
		wc1(' ', result);
		info.width--;
	}
	write(1, &"0x", 2);
	(*result) += 2;
	while ((info.precision--) - len + 2 > 0)
		wc1('0', result);
	if (radix != 15)
		write_positive_integer_lower(n, radix, result);
	return (1);
}

int	print_leftize_pointer(unsigned long long n, t_info info,
								int radix, int *result)
{
	int		len;

	len = ft_pointer_numlen(n, radix) + 2;
	write(1, &"0x", 2);
	(*result) += 2;
	if (radix == 15)
		len = 2;
	while (info.precision - len + 2 > 0)
	{
		wc1('0', result);
		info.precision--;
	}
	if (radix != 15)
		write_positive_integer_lower(n, radix, result);
	while (info.width - len > 0 && info.width - info.precision > 0)
	{
		wc1(' ', result);
		info.width--;
	}
	return (1);
}