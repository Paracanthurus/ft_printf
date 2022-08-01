/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokubo <aokubo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 22:14:47 by aokubo            #+#    #+#             */
/*   Updated: 2022/08/01 23:17:53 by aokubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	ft_isspace(char c);
static long	ft_calculate(const char *str, int sign);

int	ft_atoi(const char *str)
{
	size_t	i;
	int		sign;
	long	res;

	sign = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	res = ft_calculate(&str[i], sign);
	if (errno == ERANGE)
		return (res);
	return (sign * res);
}

static int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v')
		return (1);
	if (c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

static long	ft_calculate(const char *str, int sign)
{
	size_t				i;
	unsigned long long	res;

	i = 0;
	res = 0;
	while (ft_isdigit(str[i]))
	{
		res *= 10;
		res += str[i] - '0';
		i++;
	}
	if (sign == 1 && (i > 19 || res > (unsigned long long)LONG_MAX))
	{
		errno = ERANGE;
		return (LONG_MAX);
	}
	if (sign == -1 && (i > 19 || res > (unsigned long long)LONG_MAX + 1))
	{
		errno = ERANGE;
		return (LONG_MIN);
	}
	return (res);
}
