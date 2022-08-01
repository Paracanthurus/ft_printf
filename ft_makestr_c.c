/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makestr_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokubo <aokubo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 18:57:04 by aokubo            #+#    #+#             */
/*   Updated: 2022/08/01 19:29:17 by aokubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	ft_makestr_c(char *str, char c, size_t len, t_format *format)
{
	str[len] = '\0';
	if (format->zero)
		ft_memset(str, '0', len);
	else
		ft_memset(str, ' ', len);
	if (format->minus)
		str[0] = c;
	else
		str[len - 1] = c;
}
