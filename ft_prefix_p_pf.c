/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prefix_p_pf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokubo <aokubo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 19:10:44 by aokubo            #+#    #+#             */
/*   Updated: 2022/08/01 19:29:17 by aokubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	ft_prefix_p_pf(char *str, uintptr_t p, size_t len, t_format *format)
{
	size_t	numlen;

	numlen = ft_numlen_p(p, format);
	if (format->minus || format->zero)
		ft_memmove(&str[0], "0x", 2);
	else
		ft_memmove(&str[len - numlen], "0x", 2);
}
