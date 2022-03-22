/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokubo <aokubo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 16:29:51 by aokubo            #+#    #+#             */
/*   Updated: 2022/01/30 20:56:49 by aokubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include<stdarg.h>
# include<unistd.h>
# include"libft.h"

int		ft_printf(const char *format, ...);
int		ft_format(const char **s, va_list *args);
char	ft_type(const char **s);
int		ft_print_d(int n);
int		ft_print_u(unsigned int n);
int		ft_print_x(unsigned int n);
int		ft_numlen_x(unsigned int n);
int		ft_print_large_x(unsigned int n);
int		ft_print_p(uintptr_t n);
int		ft_print_c(char c);
int		ft_print_s(char *s);

#endif
