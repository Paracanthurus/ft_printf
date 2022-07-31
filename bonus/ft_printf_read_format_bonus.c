/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_read_format_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokubo <aokubo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:20:30 by aokubo            #+#    #+#             */
/*   Updated: 2022/07/31 00:22:23 by aokubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf_bonus.h"

void	ft_readflag(const char **s, t_format *format)
{
	if (**s == '-')
		format->flag |= (1 << 0);
	else if (**s == '+')
		format->flag |= (1 << 1);
	else if (**s == ' ')
		format->flag |= (1 << 2);
	else if (**s == '#')
		format->flag |= (1 << 3);
	else if (**s == '0')
		format->flag |= (1 << 4);
	else
		return ;
	(*s)++;
}

void	ft_readwidth(const char **s, t_format *format, va_list *args)
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
		format->flag |= (1 << 0);
	}
}

void	ft_readprecision(const char **s, t_format *format, va_list *args)
{
	if (**s != '.')
		return ;
	format->precision = 0;
	(*s)++;
	if (**s == '*')
	{
		format->precision = va_arg(*args, int);
		(*s)++;
	}
	else
	{
		format->precision = ft_atoi(*s);
		while (ft_isdigit(**s))
			(*s)++;
	}
	if (format->precision < 0)
		format->precision = -1;
}

void	ft_readtype(const char **s, t_format *format)
{
	if (ft_istype(**s))
	{
		format->type = **s;
		(*s)++;
	}
	else if (ft_isformat(**s))
	{
		format->type = **s;
		(*s)++;
	}
}
