/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokubo <aokubo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 00:56:56 by aokubo            #+#    #+#             */
/*   Updated: 2022/03/16 17:56:30 by aokubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_lstsize(t_list *list)
{
	int		res;

	res = 0;
	while (list != NULL)
	{
		list = list->next;
		res++;
	}
	return (res);
}
