/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readprecision_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokubo <aokubo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 18:53:17 by aokubo            #+#    #+#             */
/*   Updated: 2022/08/01 23:01:48 by aokubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf_bonus.h"

void	ft_readprecision(char **s, t_format *format, va_list *args)
{
	if (**s != '.')
		return ;
	format->precision = 0;
	(*s)++;
	if (**s == '*')
	{
		format->precision = va_arg(*args, int);
		(*s)++;
		if (format->precision < 0)
			format->precision = -1;
	}
	else if (ft_isdigit(**s))
	{
		format->precision = ft_atoi(*s);
		while (ft_isdigit(**s))
			(*s)++;
	}
}
