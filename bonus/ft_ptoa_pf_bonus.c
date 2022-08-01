/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptoa_pf_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokubo <aokubo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 19:11:53 by aokubo            #+#    #+#             */
/*   Updated: 2022/08/01 23:01:48 by aokubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf_bonus.h"

int	ft_ptoa_pf(char *str, uintptr_t p, size_t numlen)
{
	char	*s;
	size_t	len_s;

	s = ft_ptoa(p);
	if (s == NULL)
		return (FAILURE);
	len_s = ft_strlen(s);
	if (p == 0)
		len_s = 0;
	numlen -= 2;
	str += 2;
	ft_memset(&str[0], '0', numlen - len_s);
	ft_memmove(&str[numlen - len_s], s, len_s);
	ft_safe_free((void **)&s);
	return (SUCCESS);
}
