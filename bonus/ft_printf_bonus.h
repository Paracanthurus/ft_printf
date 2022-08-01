/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokubo <aokubo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 20:11:01 by aokubo            #+#    #+#             */
/*   Updated: 2022/08/02 05:54:44 by aokubo           ###   ########.fr       */
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
	int		width;
	int		precision;
	char	type;
	int		x_large;
	size_t	len;
}	t_format;

int		ft_printf(const char *format, ...);
int		ft_devide_type(va_list *args, t_format *format);
void	ft_format_init(t_format *format);
int		ft_isflag(char c);
int		ft_istype(char c);
int		ft_itoa_pf(char *str, int d, size_t numlen, t_format *format);
void	ft_makestr_c(char *str, char c, size_t len, t_format *format);
int		ft_makestr_d(char *str, int d, size_t len, t_format *format);
int		ft_makestr_p(char *str, uintptr_t p, size_t len, t_format *format);
void	ft_makestr_s(char *str, char *s, size_t len, t_format *format);
int		ft_makestr_u(char *str, unsigned int u, size_t len, t_format *format);
int		ft_makestr_x(char *str, unsigned int x, size_t len, t_format *format);
size_t	ft_max_size_t(size_t a, size_t b);
size_t	ft_numlen_d(int d, t_format *format);
size_t	ft_numlen_p(uintptr_t p, t_format *format);
size_t	ft_numlen_u(unsigned int u, t_format *format);
size_t	ft_numlen_x(unsigned int x, t_format *format);
void	ft_prefix_p_pf(char *str, uintptr_t p, size_t len, t_format *format);
void	ft_prefix_x_pf(char *str, unsigned int x, size_t len, t_format *format);
int		ft_print_c(char c, t_format *format);
int		ft_print_d(int d, t_format *format);
int		ft_print_format(char **s, va_list *args, t_format *format);
int		ft_print_main(char *s, va_list *args);
int		ft_print_noformat(char **str, t_format *format);
int		ft_print_p(uintptr_t p, t_format *format);
int		ft_print_s(char *s, t_format *format);
int		ft_print_u(unsigned int u, t_format *format);
int		ft_print_x(unsigned int x, t_format *format);
int		ft_ptoa_pf(char *str, uintptr_t p, size_t numlen);
char	*ft_ptoa(uintptr_t p);
int		ft_putstr_pf(char *str, t_format *format);
void	ft_readflag(char **s, t_format *format);
void	ft_readformat(char **s, va_list *args, t_format *format);
void	ft_readprecision(char **s, t_format *format, va_list *args);
void	ft_readtype(char **s, t_format *format);
void	ft_readwidth(char **s, t_format *format, va_list *args);
void	ft_safe_free(void **p);
void	ft_sign_d(char *str, int d, size_t len, t_format *format);
size_t	ft_strlen_char(char *str, char c);
int		ft_utoa_pf(char *str, unsigned int u, size_t numlen);
char	*ft_utoa(unsigned int u);
int		ft_xtoa_pf(char *str, unsigned int x, size_t numlen, t_format *format);
char	*ft_xtoa(unsigned int x, int large);
char	ft_xtoc(unsigned int x, int large);

#endif
