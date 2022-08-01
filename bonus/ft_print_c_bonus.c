/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokubo <aokubo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 18:57:52 by aokubo            #+#    #+#             */
/*   Updated: 2022/08/01 23:01:48 by aokubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf_bonus.h"

int	ft_print_c(char c, t_format *format)
{
	int		res;
	size_t	len;
	char	*str;

	len = ft_max_size_t(1, format->width);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (-1);
	ft_makestr_c(str, c, len, format);
	if (len >= (size_t)INT_MAX || format->len + len >= (size_t)INT_MAX)
	{
		ft_safe_free((void **)&str);
		return (-1);
	}
	res = write(1, str, len);
	ft_safe_free((void **)&str);
	return (res);
}
