/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makestr_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokubo <aokubo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 19:12:36 by aokubo            #+#    #+#             */
/*   Updated: 2022/08/01 19:29:17 by aokubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_makestr_p(char *str, uintptr_t p, size_t len, t_format *format)
{
	size_t	numlen;

	str[len] = '\0';
	if (format->zero)
		ft_memset(str, '0', len);
	else
		ft_memset(str, ' ', len);
	numlen = ft_numlen_p(p, format);
	ft_prefix_p_pf(str, p, len, format);
	if (format->minus)
	{
		if (!ft_ptoa_pf(&str[0], p, numlen))
			return (FAILURE);
	}
	else
	{
		if (!ft_ptoa_pf(&str[len - numlen], p, numlen))
			return (FAILURE);
	}
	return (SUCCESS);
}
