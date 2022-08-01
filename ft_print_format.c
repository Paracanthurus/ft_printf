/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokubo <aokubo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 19:14:07 by aokubo            #+#    #+#             */
/*   Updated: 2022/08/01 19:25:08 by aokubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_print_format(char **s, va_list *args, t_format *format)
{
	(*s)++;
	ft_readformat(s, args, format);
	if (format->type == 0)
		return (0);
	return (ft_devide_type(args, format));
}
