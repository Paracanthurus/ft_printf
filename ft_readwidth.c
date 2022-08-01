/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readwidth.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokubo <aokubo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 18:52:42 by aokubo            #+#    #+#             */
/*   Updated: 2022/08/01 19:29:17 by aokubo           ###   ########.fr       */
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
		format->width *= -1;
		format->minus = 1;
	}
}
