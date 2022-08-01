/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokubo <aokubo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:28:38 by aokubo            #+#    #+#             */
/*   Updated: 2022/03/16 17:59:11 by aokubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*str_d;
	unsigned char	*str_s;
	size_t			i;

	if (dst == NULL && src == NULL)
		return (dst);
	str_d = (unsigned char *)dst;
	str_s = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		str_d[i] = str_s[i];
		i++;
	}
	return (dst);
}
