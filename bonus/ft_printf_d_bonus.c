/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokubo <aokubo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:29:37 by aokubo            #+#    #+#             */
/*   Updated: 2022/01/30 19:34:38 by aokubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf_bonus.h"

static void		ft_putsign(int n, t_format format);
static void		ft_putd(long long n, t_format format);
static void		ft_put0d(long long n, t_format format);
static size_t	ft_numlen_d(int n, t_format format);

size_t	ft_print_d(int n, t_format format)
{
	size_t	len;

	len = ft_numlen_d(n, format);
	if (format.flag & ((1 << 0) | (1 << 4)))
		ft_putsign(n, format);
	if (format.flag & (1 << 0))
		ft_putd(n, format);
	len = ft_put_field_num(format, len);
	if (!(format.flag & ((1 << 0) | (1 << 4))))
		ft_putsign(n, format);
	if (!(format.flag & (1 << 0)))
		ft_putd(n, format);
	return (len);
}

static void	ft_putsign(int n, t_format format)
{
	if (n >= 0)
	{
		if (format.flag & (1 << 1))
		{
			if (format.print)
				ft_putchar_fd('+', 1);
		}
		else if (format.flag & (1 << 2))
		{
			if (format.print)
				ft_putchar_fd(' ', 1);
		}
	}
	else if (n < 0)
	{
		if (format.print)
			ft_putchar_fd('-', 1);
	}
}

static void	ft_putd(long long n, t_format format)
{
	char	str[11];
	int		i;

	ft_put0d(n, format);
	if (n == 0 && format.precision != 0)
	{
		if (format.print)
			ft_putchar_fd('0', 1);
		return ;
	}
	if (n < 0)
		n *= -1;
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

static void	ft_put0d(long long n, t_format format)
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

static size_t	ft_numlen_d(int n, t_format format)
{
	ssize_t	len;

	len = 0;
	if (n == 0 && format.precision != 0)
		len++;
	if (n < 0)
	{
		len++;
		format.precision++;
	}
	if (n >= 0 && (format.flag & ((1 << 1) | (1 << 2))))
	{
		len++;
		format.precision++;
	}
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	if (len < format.precision)
		len = format.precision;
	return (len);
}
