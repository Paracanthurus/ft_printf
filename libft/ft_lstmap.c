/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokubo <aokubo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 01:40:26 by aokubo            #+#    #+#             */
/*   Updated: 2022/03/16 17:56:21 by aokubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*list;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	res = ft_lstnew(f(lst->content));
	if (res == NULL)
		return (NULL);
	list = res;
	while (lst->next != NULL)
	{
		lst = lst->next;
		list->next = ft_lstnew(f(lst->content));
		if (list->next == NULL)
		{
			ft_lstclear(&res, del);
			break ;
		}
		list = list->next;
	}
	return (res);
}
