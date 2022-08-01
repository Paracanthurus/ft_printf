/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makestr_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokubo <aokubo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 19:01:32 by aokubo            #+#    #+#             */
/*   Updated: 2022/08/01 19:29:17 by aokubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	ft_makestr_s(char *str, char *s, size_t len, t_format *format)
{
	size_t	len_s;

	str[len] = '\0';
	if (format->zero)
		ft_memset(str, '0', len);
	else
		ft_memset(str, ' ', len);
	len_s = ft_strlen(s);
	if (format->precision != -1 && (size_t)format->precision < len_s)
		len_s = format->precision;
	if (format->minus)
		ft_memmove(&str[0], s, len_s);
	else
		ft_memmove(&str[len - len_s], s, len_s);
}
