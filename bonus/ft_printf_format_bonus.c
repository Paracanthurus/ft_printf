/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokubo <aokubo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:02:43 by aokubo            #+#    #+#             */
/*   Updated: 2022/07/31 01:02:25 by aokubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf_bonus.h"

static int		ft_isflag(char c);
static size_t	ft_print_format(va_list *args, t_format *format);

size_t	ft_readformat(const char **s, va_list *args, int print)
{
	t_format	format;

	// format.print = print;
	format.flag = 0;
	format.width = 0;
	format.precision = -1;
	format.type = 0;
	// while (ft_isformat(**s))
	while (format.type == 0)
	{
		ft_readfrag(s, &format);
		ft_readwidth(s, &format, args);
		ft_readprecision(s, &format, args);
		ft_readtype(s, &format);
	}
	// if (format.width < 0)
	// 	return ((size_t)INT_MAX + 1);
	return (ft_print_format(args, &format));
}

int	ft_isformat(char c)
{
	return (ft_isflag(c) || ft_isdigit(c) || ft_istype(c) || c == '.' || c == '*');
}

static int	ft_isflag(char c)
{
	return (c == '-' || c == '+' || c == ' ' || c == '#' || c == '0');
}

int	ft_istype(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
			|| c == 'x' || c == 'X' || c == '%');
}

static size_t	ft_print_format(va_list *args, t_format *format)
{
	size_t	len;

	if (format->type == 'c')
		len = ft_print_c(va_arg(*args, int), format);
	else if (format->type == '%')
		len = ft_print_c('%', format);
	else if (format->type == 's')
		len = ft_print_s(va_arg(*args, char *), format);
	else if (format->type == 'd' || format.type == 'i')
		len = ft_print_d(va_arg(*args, int), format);
	else if (format->type == 'u')
		len = ft_print_u(va_arg(*args, unsigned int), format);
	else if (format->type == 'x')
		len = ft_print_x(va_arg(*args, unsigned int), format);
	else if (format->type == 'X')
		len = ft_print_large_x(va_arg(*args, unsigned int), format);
	else if (format->type == 'p')
		len = ft_print_p(va_arg(*args, uintptr_t), format);
	else
		len = ft_print_c(format->type, format);
	return (len);
}
