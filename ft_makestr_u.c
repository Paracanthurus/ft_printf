/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makestr_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokubo <aokubo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 19:04:08 by aokubo            #+#    #+#             */
/*   Updated: 2022/08/01 19:29:17 by aokubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_makestr_u(char *str, unsigned int u, size_t len, t_format *format)
{
	size_t	numlen;

	str[len] = '\0';
	if (format->zero)
		ft_memset(str, '0', len);
	else
		ft_memset(str, ' ', len);
	numlen = ft_numlen_u(u, format);
	if (format->minus)
	{
		if (!ft_utoa_pf(&str[0], u, numlen))
			return (FAILURE);
	}
	else
	{
		if (!ft_utoa_pf(&str[len - numlen], u, numlen))
			return (FAILURE);
	}
	return (SUCCESS);
}
