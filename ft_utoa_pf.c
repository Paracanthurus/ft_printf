/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_pf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokubo <aokubo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 19:03:26 by aokubo            #+#    #+#             */
/*   Updated: 2022/08/01 19:29:17 by aokubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_utoa_pf(char *str, unsigned int u, size_t numlen)
{
	char	*s;
	size_t	len_s;

	s = ft_utoa(u);
	if (s == NULL)
		return (FAILURE);
	len_s = ft_strlen(s);
	if (u == 0)
		len_s = 0;
	ft_memset(&str[0], '0', numlen);
	ft_memmove(&str[numlen - len_s], s, len_s);
	ft_safe_free((void **)&s);
	return (SUCCESS);
}
