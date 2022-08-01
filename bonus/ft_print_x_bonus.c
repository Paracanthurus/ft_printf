/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokubo <aokubo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 19:09:08 by aokubo            #+#    #+#             */
/*   Updated: 2022/08/01 23:01:48 by aokubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf_bonus.h"

int	ft_print_x(unsigned int x, t_format *format)
{
	int		res;
	size_t	len;
	char	*str;

	if (format->precision != -1)
		format->zero = 0;
	len = ft_max_size_t(ft_numlen_x(x, format), format->width);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (-1);
	if (!ft_makestr_x(str, x, len, format))
	{
		ft_safe_free((void **)&str);
		return (-1);
	}
	res = ft_putstr_pf(str, format);
	ft_safe_free((void **)&str);
	return (res);
}
