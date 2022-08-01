/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokubo <aokubo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:35:57 by aokubo            #+#    #+#             */
/*   Updated: 2022/03/16 17:59:11 by aokubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*str_d;
	unsigned char	*str_s;
	size_t			i;

	if (dest == NULL && src == NULL)
		return (dest);
	str_d = (unsigned char *)dest;
	str_s = (unsigned char *)src;
	i = 0;
	if (dest > src)
	{
		i = 0;
		while (i < n)
		{
			str_d[n - 1 - i] = str_s[n - 1 - i];
			i++;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
