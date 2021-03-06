/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerrer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 19:54:12 by aguerrer          #+#    #+#             */
/*   Updated: 2021/06/15 19:54:37 by aguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_char(const char c, int *result)
{
	wc1(c, result);
}

int	print_char(const char c, t_info info, int *result)
{
	int		len;

	len = 1;
	if (info.flag == 0)
	{
		return (print_leftize_char(c, info, result));
	}
	while (info.width - info.precision > 0 && info.width - len > 0)
	{
		if (info.flag == 2)
			wc1('0', result);
		else
			wc1(' ', result);
		info.width--;
	}
	while (info.precision - len > 0)
	{
		info.precision--;
		wc1('0', result);
	}
	write_char(c, result);
	return (1);
}

int	print_leftize_char(const char c, t_info info, int *result)
{
	int		len;

	len = 1;
	while (info.precision - len > 0)
	{
		wc1('0', result);
		info.precision--;
		info.width--;
	}
	write_char(c, result);
	while (info.width - len > 0)
	{
		wc1(' ', result);
		info.width--;
	}
	return (1);
}
