/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokubo <aokubo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 22:47:47 by aokubo            #+#    #+#             */
/*   Updated: 2022/03/16 17:59:11 by aokubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*res;

	if (size == 0 || count == 0)
		res = malloc(1);
	else if (count > SIZE_T_MAX / size)
	{
		errno = ENOMEM;
		return (NULL);
	}
	else
		res = malloc(size * count);
	if (res == NULL)
		return (NULL);
	if (size == 0 || count == 0)
		ft_bzero(res, 1);
	else
		ft_bzero(res, size * count);
	return (res);
}
