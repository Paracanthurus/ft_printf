/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_pf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokubo <aokubo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 18:58:54 by aokubo            #+#    #+#             */
/*   Updated: 2022/08/01 19:29:17 by aokubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_itoa_pf(char *str, int d, size_t numlen, t_format *format)
{
	char	*s;
	size_t	len_s;

	s = ft_itoa(d);
	if (s == NULL)
		return (FAILURE);
	len_s = ft_strlen(s);
	if (d == 0)
		len_s = 0;
	if (d < 0 || format->plus || format->space)
	{
		if (d < 0)
		{
			s++;
			len_s--;
		}
		numlen--;
		str++;
	}
	ft_memset(&str[0], '0', numlen - len_s);
	ft_memmove(&str[numlen - len_s], s, len_s);
	if (d < 0)
		s--;
	ft_safe_free((void **)&s);
	return (SUCCESS);
}
