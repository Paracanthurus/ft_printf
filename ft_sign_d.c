/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sign_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokubo <aokubo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 18:59:58 by aokubo            #+#    #+#             */
/*   Updated: 2022/08/01 19:29:17 by aokubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	ft_sign_d(char *str, int d, size_t len, t_format *format)
{
	size_t	numlen;

	numlen = ft_numlen_d(d, format);
	if (d < 0)
	{
		if (format->minus || format->zero)
			str[0] = '-';
		else
			str[len - numlen] = '-';
	}
	else if (format->plus)
	{
		if (format->minus || format->zero)
			str[0] = '+';
		else
			str[len - numlen] = '+';
	}
	else if (format->space)
	{
		if (format->minus || format->zero)
			str[0] = ' ';
		else
			str[len - numlen] = ' ';
	}
}
