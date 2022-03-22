/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokubo <aokubo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 03:10:03 by aokubo            #+#    #+#             */
/*   Updated: 2022/03/16 17:58:03 by aokubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static size_t	ft_split_size(const char *s, char c);
static size_t	ft_strlen_split(const char *str, const char c);
static char		*ft_strdup_split(const char *s1, char c);
static char		**ft_free_split(char **res, size_t split_size);

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	split_size;
	size_t	i;
	size_t	j;

	if (s == NULL)
		return (NULL);
	split_size = ft_split_size(s, c);
	res = (char **)malloc(sizeof(char *) * (split_size + 1));
	if (res == NULL)
		return (NULL);
	res[split_size] = NULL;
	i = 0;
	j = 0;
	while (i < split_size)
	{
		while (s[j] == c)
			j++;
		res[i] = ft_strdup_split(&s[j], c);
		j += ft_strlen_split(&s[j], c);
		i++;
	}
	res = ft_free_split(res, split_size);
	return (res);
}

static size_t	ft_split_size(const char *s, char c)
{
	size_t	res;
	size_t	i;

	res = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] != '\0')
			res++;
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (res);
}

static char	*ft_strdup_split(const char *s1, char c)
{
	char	*res;
	size_t	len;

	len = ft_strlen_split(s1, c);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	ft_strlcpy(res, s1, len + 1);
	return (res);
}

static size_t	ft_strlen_split(const char *str, const char c)
{
	size_t	res;

	res = 0;
	while (str[res] != '\0' && str[res] != c)
		res++;
	return (res);
}

static char	**ft_free_split(char **res, size_t split_size)
{
	size_t	i;
	bool	judge;

	i = 0;
	judge = false;
	while (i < split_size)
	{
		if (res[i] == NULL)
			judge = true;
		i++;
	}
	if (!judge)
		return (res);
	i = 0;
	while (i < split_size)
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (NULL);
}
