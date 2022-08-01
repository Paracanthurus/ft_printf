/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokubo <aokubo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 02:42:24 by aokubo            #+#    #+#             */
/*   Updated: 2022/03/16 18:55:02 by aokubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static size_t	ft_set_count(const char c, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	start;
	size_t	end;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	while (ft_set_count(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > 0 && ft_set_count(s1[end - 1], set))
		end--;
	if (start < end)
		res = ft_substr(s1, start, end - start);
	else
		res = ft_substr(s1, start, 0);
	return (res);
}

static size_t	ft_set_count(const char c, char const *set)
{
	size_t	res;
	size_t	i;

	res = 0;
	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			res++;
		i++;
	}
	return (res);
}
