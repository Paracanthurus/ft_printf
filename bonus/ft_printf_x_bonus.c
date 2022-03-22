/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokubo <aokubo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:39:57 by aokubo            #+#    #+#             */
/*   Updated: 2022/02/05 20:18:21 by aokubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf_bonus.h"

static void	ft_putx(unsigned int n, t_format format);

size_t	ft_print_x(unsigned int n, t_format f)
{
	size_t	len;

	len = ft_numlen_x(n, f);
	if ((f.flag & 1 << 3) && n != 0)
	{
		if ((f.flag & 1 << 0) || ((f.flag & 1 << 4) && f.precision == -1))
		{
			if (f.print)
				ft_putstr_fd("0x", 1);
		}
	}
	if (f.flag & (1 << 0))
		ft_putx(n, f);
	len = ft_put_field_num(f, len);
	if ((f.flag & 1 << 3) && n != 0)
	{
		if (!((f.flag & 1 << 0) || ((f.flag & 1 << 4) && f.precision == -1)))
		{
			if (f.print)
				ft_putstr_fd("0x", 1);
		}
	}
	if (!(f.flag & (1 << 0)))
		ft_putx(n, f);
	return (len);
}

static void	ft_putx(unsigned int n, t_format format)
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
			str[i] = n % 16 - 10 + 'a';
		n /= 16;
	}
	if (format.print)
		ft_putstr_fd(&str[i], 1);
}

void	ft_put0x(unsigned int n, t_format format)
{
	ssize_t	len;

	len = 0;
	if (n == 0 && format.precision != 0)
		len++;
	while (n != 0)
	{
		n /= 16;
		len++;
	}
	while (len < format.precision)
	{
		if (format.print)
			ft_putchar_fd('0', 1);
		len++;
	}
}

size_t	ft_numlen_x(unsigned int n, t_format format)
{
	ssize_t	len;

	len = 0;
	if ((format.flag & (1 << 3)) && n != 0)
	{
		len += 2;
		format.precision += 2;
	}
	if (n == 0 && (format.precision != 0))
		len++;
	while (n != 0)
	{
		n /= 16;
		len++;
	}
	if (len < format.precision)
		len = format.precision;
	return (len);
}
