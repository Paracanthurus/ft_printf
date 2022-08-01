/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readflag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokubo <aokubo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 18:51:53 by aokubo            #+#    #+#             */
/*   Updated: 2022/08/01 19:29:17 by aokubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	ft_readflag(char **s, t_format *format)
{
	if (**s == '-')
		format->minus = 1;
	else if (**s == '+')
		format->plus = 1;
	else if (**s == ' ')
		format->space = 1;
	else if (**s == '#')
		format->sharp = 1;
	else if (**s == '0')
		format->zero = 1;
	else
		return ;
	(*s)++;
}
