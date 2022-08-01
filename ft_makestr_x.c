/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makestr_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokubo <aokubo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 19:08:30 by aokubo            #+#    #+#             */
/*   Updated: 2022/08/01 19:29:17 by aokubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_makestr_x(char *str, unsigned int x, size_t len, t_format *format)
{
	size_t	numlen;

	str[len] = '\0';
	if (format->zero)
		ft_memset(str, '0', len);
	else
		ft_memset(str, ' ', len);
	numlen = ft_numlen_x(x, format);
	ft_prefix_x_pf(str, x, len, format);
	if (format->minus)
	{
		if (!ft_xtoa_pf(&str[0], x, numlen, format))
			return (FAILURE);
	}
	else
	{
		if (!ft_xtoa_pf(&str[len - numlen], x, numlen, format))
			return (FAILURE);
	}
	return (SUCCESS);
}
