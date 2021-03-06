/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokubo <aokubo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 16:27:27 by aokubo            #+#    #+#             */
/*   Updated: 2022/03/23 04:01:55 by aokubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf_bonus.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	va_list	args_cpy;
	int		len;

	va_start(args, format);
	va_copy(args_cpy, args);
	len = ft_printf_len(format, &args_cpy);
	if (len != -1)
	{
		while (*format != '\0')
		{
			if (*format == '%')
			{
				format++;
				ft_format(&format, &args, 1);
			}
			else
			{
				ft_putchar_fd(*format, 1);
				format++;
			}
		}
	}
	va_end(args);
	return (len);
}

int	ft_printf_len(const char *s, va_list *args)
{
	ssize_t	len;

	len = 0;
	while (*s != '\0')
	{
		if (*s == '%')
		{
			s++;
			len += ft_format(&s, args, 0);
		}
		else
		{
			len++;
			s++;
		}
		if (len < 0 || INT_MAX < len)
		{
			len = -1;
			break ;
		}
	}
	va_end(*args);
	return (len);
}
