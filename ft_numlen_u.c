/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokubo <aokubo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 19:02:39 by aokubo            #+#    #+#             */
/*   Updated: 2022/08/01 19:29:17 by aokubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

size_t	ft_numlen_u(unsigned int u, t_format *format)
{
	size_t			len;
	unsigned int	num;

	num = u;
	len = 0;
	while (u != 0)
	{
		u /= 10;
		len++;
	}
	if (format->precision != -1)
		len = ft_max_size_t(len, format->precision);
	else if (num == 0)
		len = 1;
	return (len);
}
