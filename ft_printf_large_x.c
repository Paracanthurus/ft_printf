/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_large_x.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokubo <aokubo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:46:49 by aokubo            #+#    #+#             */
/*   Updated: 2022/01/23 00:07:01 by aokubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

static void	ft_put_large_x(unsigned int n);

int	ft_print_large_x(unsigned int n)
{
	ft_put_large_x(n);
	return (ft_numlen_x(n));
}

static void	ft_put_large_x(unsigned int n)
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
			str[i] = n % 16 - 10 + 'A';
		n /= 16;
	}
	ft_putstr_fd(&str[i], 1);
}
