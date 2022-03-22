/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_cs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokubo <aokubo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:52:56 by aokubo            #+#    #+#             */
/*   Updated: 2022/03/16 17:00:37 by aokubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_print_c(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_print_s(char *s)
{
	if (s == NULL)
		s = "(null)";
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}
