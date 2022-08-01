/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokubo <aokubo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 03:53:22 by aokubo            #+#    #+#             */
/*   Updated: 2022/03/16 17:55:53 by aokubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static size_t	ft_itoa_len(long long int n);

char	*ft_itoa(int n)
{
	char			*res;
	size_t			len;
	unsigned int	i;
	long long int	nll;

	nll = (long long int)n;
	len = ft_itoa_len(nll);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	res[0] = '0';
	if (nll < 0)
	{
		res[0] = '-';
		nll *= -1;
	}
	i = len - 1;
	while (nll > 0)
	{
		res[i] = nll % 10 + '0';
		nll /= 10;
		i--;
	}
	res[len] = '\0';
	return (res);
}

static size_t	ft_itoa_len(long long int n)
{
	size_t	res;

	if (n == 0)
		return (1);
	res = 0;
	if (n < 0)
	{
		res++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		res++;
	}
	return (res);
}
