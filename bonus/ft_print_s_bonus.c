/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokubo <aokubo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 19:02:05 by aokubo            #+#    #+#             */
/*   Updated: 2022/08/01 23:01:48 by aokubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf_bonus.h"

int	ft_print_s(char *s, t_format *format)
{
	int		res;
	size_t	len;
	char	*str;

	if (s == NULL)
		s = "(null)";
	len = ft_strlen(s);
	if (format->precision != -1 && (size_t)format->precision < len)
		len = format->precision;
	len = ft_max_size_t(len, format->width);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (-1);
	ft_makestr_s(str, s, len, format);
	res = ft_putstr_pf(str, format);
	ft_safe_free((void **)&str);
	return (res);
}
