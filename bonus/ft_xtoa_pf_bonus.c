/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xtoa_pf_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokubo <aokubo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 19:07:46 by aokubo            #+#    #+#             */
/*   Updated: 2022/08/01 23:01:48 by aokubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf_bonus.h"

int	ft_xtoa_pf(char *str, unsigned int x, size_t numlen, t_format *format)
{
	char	*s;
	size_t	len_s;

	s = ft_xtoa(x, format->x_large);
	if (s == NULL)
		return (FAILURE);
	len_s = ft_strlen(s);
	if (x == 0)
		len_s = 0;
	if (format->sharp && x != 0)
	{
		numlen -= 2;
		str += 2;
	}
	ft_memset(&str[0], '0', numlen - len_s);
	ft_memmove(&str[numlen - len_s], s, len_s);
	ft_safe_free((void **)&s);
	return (SUCCESS);
}
