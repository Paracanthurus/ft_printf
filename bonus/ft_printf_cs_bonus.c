/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_cs_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokubo <aokubo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:52:56 by aokubo            #+#    #+#             */
/*   Updated: 2022/01/30 20:03:04 by aokubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf_bonus.h"

static void		ft_puts(char *s, size_t len, t_format format);
static size_t	ft_put_field_cs(t_format format, size_t len);

size_t	ft_print_c(char c, t_format format)
{
	size_t	len;

	len = 1;
	if (format.flag & (1 << 0))
	{
		if (format.print)
			ft_putchar_fd(c, 1);
	}
	len = ft_put_field_cs(format, len);
	if (!(format.flag & (1 << 0)))
	{
		if (format.print)
			ft_putchar_fd(c, 1);
	}
	return (len);
}

size_t	ft_print_s(char *s, t_format format)
{
	size_t	len;
	size_t	len_s;

	if (s == NULL)
		s = "(null)";
	len_s = ft_strlen(s);
	if (format.precision >= 0 && len_s > (size_t)format.precision)
		len_s = format.precision;
	if (format.flag & (1 << 0))
		ft_puts(s, len_s, format);
	len = ft_put_field_cs(format, len_s);
	if (!(format.flag & (1 << 0)))
		ft_puts(s, len_s, format);
	return (len);
}

static void	ft_puts(char *s, size_t len, t_format format)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (format.print)
			ft_putchar_fd(s[i], 1);
		i++;
	}
}

static size_t	ft_put_field_cs(t_format format, size_t len)
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
				ft_putchar_fd('0', 1);
			else
				ft_putchar_fd(' ', 1);
		}
		len++;
	}
	return (len);
}
