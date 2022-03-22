/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokubo <aokubo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:36:23 by aokubo            #+#    #+#             */
/*   Updated: 2022/01/23 00:15:50 by aokubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

static void	ft_putu(unsigned int n);
static int	ft_numlen_u(unsigned int n);

int	ft_print_u(unsigned int n)
{
	ft_putu(n);
	return (ft_numlen_u(n));
}

static void	ft_putu(unsigned int n)
{
	char	str[11];
	int		i;

	if (n == 0)
	{
		ft_putchar_fd('0', 1);
		return ;
	}
	str[10] = '\0';
	i = 10;
	while (n > 0)
	{
		i--;
		str[i] = n % 10 + '0';
		n /= 10;
	}
	ft_putstr_fd(&str[i], 1);
}

static int	ft_numlen_u(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}
