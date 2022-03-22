/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokubo <aokubo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:36:23 by aokubo            #+#    #+#             */
/*   Updated: 2022/01/30 20:03:17 by aokubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf_bonus.h"

static void		ft_putu(unsigned int n, t_format format);
static void		ft_put0u(unsigned int n, t_format format);
static size_t	ft_numlen_u(unsigned int n, t_format format);

size_t	ft_print_u(unsigned int n, t_format format)
{
	size_t	len;

	len = ft_numlen_u(n, format);
	if (format.flag & (1 << 0))
		ft_putu(n, format);
	len = ft_put_field_num(format, len);
	if (!(format.flag & (1 << 0)))
		ft_putu(n, format);
	return (len);
}

static void	ft_putu(unsigned int n, t_format format)
{
	char	str[11];
	int		i;

	ft_put0u(n, format);
	if (n == 0 && format.precision != 0)
	{
		if (format.print)
			ft_putchar_fd('0', 1);
		return ;
	}
	str[10] = '\0';
	i = 10;
	while (n > 0)
	{
		i--;
		str[i] = n % 10 + '0';
		n /= 10;
	}
	if (format.print)
		ft_putstr_fd(&str[i], 1);
}

static void	ft_put0u(unsigned int n, t_format format)
{
	ssize_t	len;

	len = 0;
	if (n == 0 && format.precision != 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	while (len < format.precision)
	{
		if (format.print)
			ft_putchar_fd('0', 1);
		len++;
	}
}

static size_t	ft_numlen_u(unsigned int n, t_format format)
{
	ssize_t	len;

	len = 0;
	if (n == 0 && format.precision != 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	if (len < format.precision)
		len = format.precision;
	return (len);
}

size_t	ft_put_field_num(t_format format, size_t len)
{
	size_t	abs_width;

	if (format.width < 0)
		abs_width = format.width * -1;
	else
		abs_width = format.width;
	while (len < abs_width)
	{
		if (format.width > 0 && format.print)
		{
			if (!(format.flag & (1 << 0)) && (format.flag & (1 << 4)))
			{
				if (format.precision == -1)
					ft_putchar_fd('0', 1);
				else
					ft_putchar_fd(' ', 1);
			}
			else
				ft_putchar_fd(' ', 1);
		}
		len++;
	}
	return (len);
}
