/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokubo <aokubo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:39:57 by aokubo            #+#    #+#             */
/*   Updated: 2022/01/23 00:26:48 by aokubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

static void	ft_putx(unsigned int n);

int	ft_print_x(unsigned int n)
{
	ft_putx(n);
	return (ft_numlen_x(n));
}

static void	ft_putx(unsigned int n)
{
	char	str[9];
	int		i;

	if (n == 0)
	{
		ft_putchar_fd('0', 1);
		return ;
	}
	str[8] = '\0';
	i = 8;
	while (n > 0)
	{
		i--;
		if (n % 16 < 10)
			str[i] = n % 16 + '0';
		else
			str[i] = n % 16 - 10 + 'a';
		n /= 16;
	}
	ft_putstr_fd(&str[i], 1);
}

int	ft_numlen_x(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	while (n != 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}
