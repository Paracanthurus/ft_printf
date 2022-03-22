/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_large_x_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokubo <aokubo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:46:49 by aokubo            #+#    #+#             */
/*   Updated: 2022/03/16 17:09:10 by aokubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf_bonus.h"

static void	ft_put_large_x(unsigned int n, t_format format);

size_t	ft_print_large_x(unsigned int n, t_format f)
{
	size_t	len;

	len = ft_numlen_x(n, f);
	if ((f.flag & 1 << 3) && n != 0)
	{
		if ((f.flag & 1 << 0) || ((f.flag & 1 << 4) && f.precision == -1))
		{
			if (f.print)
				ft_putstr_fd("0X", 1);
		}
	}
	if (f.flag & (1 << 0))
		ft_put_large_x(n, f);
	len = ft_put_field_num(f, len);
	if ((f.flag & 1 << 3) && n != 0)
	{
		if (!((f.flag & 1 << 0) || ((f.flag & 1 << 4) && f.precision == -1)))
		{
			if (f.print)
				ft_putstr_fd("0X", 1);
		}
	}
	if (!(f.flag & (1 << 0)))
		ft_put_large_x(n, f);
	return (len);
}

static void	ft_put_large_x(unsigned int n, t_format format)
{
	char	str[9];
	int		i;

	ft_put0x(n, format);
	if (n == 0 && format.precision != 0)
	{
		if (format.print)
			ft_putchar_fd('0', 1);
		return ;
	}
	str[8] = '\0';
	i = 8;
	while (n > 0)
	{
		i--;
		if (n % 16 < 10)
			str[i] = n % 16 + '0';
		else
			str[i] = n % 16 - 10 + 'A';
		n /= 16;
	}
	if (format.print)
		ft_putstr_fd(&str[i], 1);
}
