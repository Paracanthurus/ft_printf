/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokubo <aokubo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:50:36 by aokubo            #+#    #+#             */
/*   Updated: 2022/01/23 00:22:11 by aokubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

static void	ft_putp(uintptr_t n);
static int	ft_numlen_p(uintptr_t n);

int	ft_print_p(uintptr_t n)
{
	ft_putstr_fd("0x", 1);
	ft_putp(n);
	return (ft_numlen_p(n));
}

static void	ft_putp(uintptr_t n)
{
	char	str[17];
	int		i;

	if (n == 0)
	{
		ft_putchar_fd('0', 1);
		return ;
	}
	str[16] = '\0';
	i = 16;
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

static int	ft_numlen_p(uintptr_t n)
{
	int	len;

	len = 2;
	if (n == 0)
		len++;
	while (n != 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}
