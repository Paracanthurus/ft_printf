/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokubo <aokubo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 19:15:41 by aokubo            #+#    #+#             */
/*   Updated: 2022/08/01 19:29:17 by aokubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_print_main(char *s, va_list *args)
{
	t_format	format;
	int			len;

	format.len = 0;
	while (*s != '\0')
	{
		if (*s == '%')
			len = ft_print_format(&s, args, &format);
		else
			len = ft_print_noformat(&s, &format);
		if (len == -1)
			return (-1);
		format.len += len;
	}
	return (format.len);
}
