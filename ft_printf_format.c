/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokubo <aokubo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:02:43 by aokubo            #+#    #+#             */
/*   Updated: 2022/01/23 23:24:32 by aokubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

static int	ft_print_format(va_list *args, char type);

int	ft_format(const char **s, va_list *args)
{
	char	type;

	type = ft_type(s);
	return (ft_print_format(args, type));
}

static int	ft_print_format(va_list *args, char type)
{
	int	len;

	if (type == 'c')
		len = ft_print_c(va_arg(*args, int));
	else if (type == '%')
		len = ft_print_c('%');
	else if (type == 's')
		len = ft_print_s(va_arg(*args, char *));
	else if (type == 'd' || type == 'i')
		len = ft_print_d(va_arg(*args, int));
	else if (type == 'u')
		len = ft_print_u(va_arg(*args, unsigned int));
	else if (type == 'x')
		len = ft_print_x(va_arg(*args, unsigned int));
	else if (type == 'X')
		len = ft_print_large_x(va_arg(*args, unsigned int));
	else if (type == 'p')
		len = ft_print_p(va_arg(*args, uintptr_t));
	else
		len = ft_print_c(type);
	return (len);
}
