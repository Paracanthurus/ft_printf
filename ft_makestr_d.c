/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makestr_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokubo <aokubo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 19:00:39 by aokubo            #+#    #+#             */
/*   Updated: 2022/08/01 19:29:17 by aokubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_makestr_d(char *str, int d, size_t len, t_format *format)
{
	size_t	numlen;

	str[len] = '\0';
	numlen = ft_numlen_d(d, format);
	if (format->zero)
		ft_memset(str, '0', len);
	else
		ft_memset(str, ' ', len);
	ft_sign_d(str, d, len, format);
	if (format->minus)
	{
		if (!ft_itoa_pf(&str[0], d, numlen, format))
			return (FAILURE);
	}
	else
	{
		if (!ft_itoa_pf(&str[len - numlen], d, numlen, format))
			return (FAILURE);
	}
	return (SUCCESS);
}
