/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readformat_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokubo <aokubo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 18:55:45 by aokubo            #+#    #+#             */
/*   Updated: 2022/08/01 23:01:48 by aokubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf_bonus.h"

void	ft_readformat(char **s, va_list *args, t_format *format)
{
	ft_format_init(format);
	while (**s != '\0' && format->type == 0)
	{
		ft_readflag(s, format);
		ft_readwidth(s, format, args);
		ft_readprecision(s, format, args);
		ft_readtype(s, format);
	}
	if (format->minus)
		format->zero = 0;
}
