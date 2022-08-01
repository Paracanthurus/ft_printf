/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readwidth.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokubo <aokubo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 18:52:42 by aokubo            #+#    #+#             */
/*   Updated: 2022/08/02 06:02:05 by aokubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	ft_readwidth(char **s, t_format *format, va_list *args)
{
	if (**s == '*')
	{
		format->width = va_arg(*args, int);
		(*s)++;
	}
	else if (ft_isdigit(**s) && **s != '0')
	{
		format->width = ft_atoi(*s);
		while (ft_isdigit(**s))
			(*s)++;
	}
	if (format->width < 0)
	{
		if (format->width == INT_MIN)
			format->width = INT_MAX;
		else
			format->width *= -1;
		format->minus = 1;
	}
}
