/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prefix_x_pf_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokubo <aokubo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 19:07:06 by aokubo            #+#    #+#             */
/*   Updated: 2022/08/01 23:02:04 by aokubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf_bonus.h"

void	ft_prefix_x_pf(char *str, unsigned int x, size_t len, t_format *format)
{
	size_t	numlen;

	numlen = ft_numlen_x(x, format);
	if (format->sharp && x != 0)
	{
		if (format->minus || format->zero)
		{
			if (format->x_large)
				ft_memmove(&str[0], "0X", 2);
			else
				ft_memmove(&str[0], "0x", 2);
		}
		else
		{
			if (format->x_large)
				ft_memmove(&str[len - numlen], "0X", 2);
			else
				ft_memmove(&str[len - numlen], "0x", 2);
		}
	}
}
