/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokubo <aokubo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:50:36 by aokubo            #+#    #+#             */
/*   Updated: 2022/02/05 20:24:03 by aokubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf_bonus.h"

static void		ft_putp(uintptr_t n, t_format format);
static void		ft_put0p(uintptr_t n, t_format format);
static size_t	ft_numlen_p(uintptr_t n, t_format format);

size_t	ft_print_p(uintptr_t n, t_format f)
{
	size_t	len;

	len = ft_numlen_p(n, f);
	if ((f.flag & 1 << 0) || ((f.flag & 1 << 4) && f.precision == -1))
	{
		if (f.print)
			ft_putstr_fd("0x", 1);
	}
	if (f.flag & (1 << 0))
		ft_putp(n, f);
	len = ft_put_field_num(f, len);
	if (!((f.flag & 1 << 0) || ((f.flag & 1 << 4) && f.precision == -1)))
	{
		if (f.print)
			ft_putstr_fd("0x", 1);
	}
	if (!(f.flag & (1 << 0)))
		ft_putp(n, f);
	return (len);
}

static void	ft_putp(uintptr_t n, t_format format)
{
	char	str[17];
	int		i;

	ft_put0p(n, format);
	if (n == 0 && format.precision != 0)
	{
		if (format.print)
			ft_putchar_fd('0', 1);
		return ;
	}
	str[16] = '\0';
	i = 16;
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

static void	ft_put0p(uintptr_t n, t_format format)
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

static size_t	ft_numlen_p(uintptr_t n, t_format format)
{
	ssize_t	len;

	len = 2;
	format.precision += 2;
	if (n == 0 && format.precision != 0)
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
