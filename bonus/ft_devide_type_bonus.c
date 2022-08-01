/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_devide_type_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokubo <aokubo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 19:13:34 by aokubo            #+#    #+#             */
/*   Updated: 2022/08/01 23:01:48 by aokubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf_bonus.h"

int	ft_devide_type(va_list *args, t_format *format)
{
	if (format->type == 'c')
		return (ft_print_c(va_arg(*args, int), format));
	else if (format->type == '%')
		return (ft_print_c('%', format));
	else if (format->type == 's')
		return (ft_print_s(va_arg(*args, char *), format));
	else if (format->type == 'd' || format->type == 'i')
		return (ft_print_d(va_arg(*args, int), format));
	else if (format->type == 'u')
		return (ft_print_u(va_arg(*args, unsigned int), format));
	else if (format->type == 'x')
		return (ft_print_x(va_arg(*args, unsigned int), format));
	else if (format->type == 'X')
	{
		format->x_large = 1;
		return (ft_print_x(va_arg(*args, unsigned int), format));
	}
	else if (format->type == 'p')
		return (ft_print_p(va_arg(*args, uintptr_t), format));
	return (ft_print_c(format->type, format));
}
