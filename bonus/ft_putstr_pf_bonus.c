/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_pf_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokubo <aokubo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 18:50:29 by aokubo            #+#    #+#             */
/*   Updated: 2022/08/01 23:01:48 by aokubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf_bonus.h"

int	ft_putstr_pf(char *str, t_format *format)
{
	size_t	len;

	if (str == NULL)
		return (-1);
	len = ft_strlen(str);
	if (len >= (size_t)INT_MAX || format->len + len >= (size_t)INT_MAX)
		return (-1);
	return (write(1, str, len));
}
