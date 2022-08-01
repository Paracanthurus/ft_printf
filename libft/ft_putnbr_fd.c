/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokubo <aokubo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:12:02 by aokubo            #+#    #+#             */
/*   Updated: 2022/02/06 01:10:26 by aokubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char			str[11];
	long long int	nll;
	int				i;

	nll = (long long int)n;
	if (nll == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	if (nll < 0)
	{
		nll *= -1;
		ft_putchar_fd('-', fd);
	}
	str[10] = '\0';
	i = 10;
	while (nll > 0)
	{
		i--;
		str[i] = nll % 10 + '0';
		nll /= 10;
	}
	ft_putstr_fd(&str[i], fd);
}
