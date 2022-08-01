/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_noformat.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokubo <aokubo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 19:15:16 by aokubo            #+#    #+#             */
/*   Updated: 2022/08/01 19:29:17 by aokubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_print_noformat(char **str, t_format *format)
{
	int		res;
	size_t	len;

	len = ft_strlen_char(*str, '%');
	if (len >= (size_t)INT_MAX || format->len + len >= (size_t)INT_MAX)
		return (-1);
	res = write(1, *str, len);
	*str += len;
	return (res);
}
