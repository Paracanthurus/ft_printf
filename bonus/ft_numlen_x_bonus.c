/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen_x_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokubo <aokubo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 19:06:21 by aokubo            #+#    #+#             */
/*   Updated: 2022/08/01 23:01:48 by aokubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf_bonus.h"

size_t	ft_numlen_x(unsigned int x, t_format *format)
{
	size_t			len;
	unsigned int	num;

	num = x;
	len = 0;
	while (x != 0)
	{
		x /= 16;
		len++;
	}
	if (format->precision != -1)
		len = ft_max_size_t(len, format->precision);
	else if (num == 0)
		len = 1;
	if (format->sharp && num != 0)
		len += 2;
	return (len);
}
