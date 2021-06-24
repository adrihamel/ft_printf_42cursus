/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerrer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 19:50:05 by aguerrer          #+#    #+#             */
/*   Updated: 2021/06/15 19:50:26 by aguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	wc1(const char c, int *result)
{
	(*result)++;
	write(1, &c, 1);
}

int	min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

int	print_zero_handler(int n, t_info info, int *result)
{
	if (n == 0 && info.print_zero == 0)
	{
		if (info.precision == 0 && info.width == 0)
			info.width = 0;
		else if (info.precision == 0 && info.width != 0)
			wc1(' ', result);
		else if (info.flag <= 1 || info.width == 0)
			wc1('0', result);
		return (0);
	}
	return (1);
}

int	width_handling(t_info *info, int len, int *result)
{
	while (info->width - info->precision > 0 && info->width - len > 0)
	{
		if (info->flag == 2)
		{
			if (info->is_dot == 1 && info->precision > 0)
				wc1(' ', result);
			else
				wc1('0', result);
		}
		else
			wc1(' ', result);
		(info->width)--;
	}
	return (1);
}
