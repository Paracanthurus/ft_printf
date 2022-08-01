/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokubo <aokubo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 20:11:01 by aokubo            #+#    #+#             */
/*   Updated: 2022/08/01 17:35:24 by aokubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include<unistd.h>
# include<stdarg.h>
# include<stdlib.h>
# include<limits.h>
# include"../libft/libft.h"

# define SUCCESS 1
# define FAILURE 0
typedef struct s_format
{
	int		minus;
	int		plus;
	int		space;
	int		sharp;
	int		zero;
	long	width;
	long	precision;
	char	type;
	int		x_large;
	ssize_t	len;
}	t_format;

int	ft_printf(const char *format, ...);

#endif
