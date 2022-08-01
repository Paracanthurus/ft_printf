/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen_d_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokubo <aokubo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 18:58:28 by aokubo            #+#    #+#             */
/*   Updated: 2022/08/01 23:01:48 by aokubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf_bonus.h"

size_t	ft_numlen_d(int d, t_format *format)
{
	size_t	len;
	int		num;

	len = 0;
	num = d;
	while (d != 0)
	{
		d /= 10;
		len++;
	}
	if (format->precision != -1)
		len = ft_max_size_t(len, format->precision);
	else if (num == 0)
		len = 1;
	if (num < 0 || format->space || format->plus)
		len++;
	return (len);
}
