/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokubo <aokubo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 16:29:51 by aokubo            #+#    #+#             */
/*   Updated: 2022/03/23 03:44:56 by aokubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include<stdarg.h>
# include<unistd.h>
# include<limits.h>
# include"../libft/libft.h"

typedef struct s_format
{
	int		flag;
	int		width;
	int		precision;
	char	type;
	int		print;
}	t_format;

int		ft_printf(const char *format, ...);
size_t	ft_format(const char **s, va_list *args, int print);
int		ft_istype(char c);
void	ft_frag(const char **s, t_format *format);
void	ft_width(const char **s, t_format *format, va_list *args);
void	ft_precision(const char **s, t_format *format, va_list *args);
void	ft_type(const char **s, t_format *format);
size_t	ft_print_d(int n, t_format format);
size_t	ft_print_u(unsigned int n, t_format format);
size_t	ft_print_x(unsigned int n, t_format f);
void	ft_put0x(unsigned int n, t_format format);
size_t	ft_numlen_x(unsigned int n, t_format format);
size_t	ft_print_large_x(unsigned int n, t_format f);
size_t	ft_print_p(uintptr_t n, t_format f);
size_t	ft_print_c(char c, t_format format);
size_t	ft_print_s(char *s, t_format format);
size_t	ft_put_field(t_format format, size_t len);
size_t	ft_put_field_num(t_format format, size_t len);
int		ft_printf_len(const char *s, va_list args);

#endif
