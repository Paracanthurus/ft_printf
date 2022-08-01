/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xtoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokubo <aokubo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 19:05:05 by aokubo            #+#    #+#             */
/*   Updated: 2022/08/01 23:01:41 by aokubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf_bonus.h"

char	ft_xtoc(unsigned int x, int large)
{
	x %= 16;
	if (x < 10)
		return (x + '0');
	if (large)
		return (x - 10 + 'A');
	return (x - 10 + 'a');
}
