/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen_p_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokubo <aokubo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 19:09:27 by aokubo            #+#    #+#             */
/*   Updated: 2022/08/01 23:01:48 by aokubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf_bonus.h"

size_t	ft_numlen_p(uintptr_t p, t_format *format)
{
	size_t		len;
	uintptr_t	num;

	num = p;
	len = 0;
	while (p != 0)
	{
		p /= 16;
		len++;
	}
	if (format->precision != -1)
		len = ft_max_size_t(len, format->precision);
	else if (num == 0)
		len = 1;
	len += 2;
	return (len);
}
