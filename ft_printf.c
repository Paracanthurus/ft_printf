/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokubo <aokubo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 20:09:44 by aokubo            #+#    #+#             */
/*   Updated: 2022/07/31 20:03:31 by aokubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"


#include<libc.h>

void	ft_safe_free(void **p)
{
	free(*p);
	*p = NULL;
}

ssize_t	ft_putstr_pf(char *str, t_format *format)
{
	size_t len;

	if (str == NULL)
		return (-1);
	len = ft_strlen(str);
	if ((size_t)(INT_MAX - format->len) < len)
		return (-1);
	return (write(1, str, len));
}

void	ft_readflag(char **s, t_format *format)
{
	if (**s == '-')
		format->minus = 1;
	else if (**s == '+')
		format->plus = 1;
	else if (**s == ' ')
		format->space = 1;
	else if (**s == '#')
		format->sharp = 1;
	else if (**s == '0')
		format->zero = 1;
	else
		return ;
	(*s)++;
}

void	ft_readwidth(char **s, t_format *format, va_list *args)
{
	if (**s == '*')
	{
		format->width = va_arg(*args, int);
		(*s)++;
	}
	else if (ft_isdigit(**s) && **s != '0')
	{
		format->width = ft_atoi(*s);
		while (ft_isdigit(**s))
			(*s)++;
	}
	if (format->width < 0)
	{
		format->width *= -1;
		format->minus = 1;
	}
}

void	ft_readprecision(char **s, t_format *format, va_list *args)
{
	if (**s != '.')
		return ;
	format->precision = 0;
	(*s)++;
	if (**s == '*')
	{
		format->precision = va_arg(*args, int);
		(*s)++;
		if (format->precision < 0)
			format->precision = -1;
	}
	else if (ft_isdigit(**s))
	{
		format->precision = ft_atoi(*s);
		while (ft_isdigit(**s))
			(*s)++;
	}
}

int	ft_isflag(char c)
{
	return (c == '-' || c == '+' || c == ' ' || c == '#' || c == '0');
}

int	ft_istype(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
			|| c == 'x' || c == 'X' || c == '%');
}

void	ft_readtype(char **s, t_format *format)
{
	if (ft_istype(**s) || !(ft_isflag(**s) || ft_isdigit(**s) || **s == '*' || **s == '.' || **s == '\0'))
	{
		format->type = **s;
		(*s)++;
	}
}

void	ft_format_init(t_format *format)
{
	format->minus = 0;
	format->plus = 0;
	format->space = 0;
	format->sharp = 0;
	format->zero = 0;
	format->width = 0;
	format->precision = -1;
	format->type = 0;
}

void	ft_readformat(char **s, va_list *args, t_format *format)
{
	ft_format_init(format);
	while (**s != '\0' && format->type == 0)
	{
		ft_readflag(s, format);
		ft_readwidth(s, format, args);
		ft_readprecision(s, format, args);
		ft_readtype(s, format);
	}
}

size_t	ft_max_size_t(size_t a, size_t b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

void	ft_makestr_c(char *str, char c, size_t len, t_format *format)
{
	str[len] = '\0';
	if (format->zero)
		ft_memset(str, '0', len);
	else
		ft_memset(str, ' ', len);
	if (format->minus)
		str[0] = c;
	else
		str[len - 1] = c;
	if (format->minus)
		ft_memset(&str[1], ' ', len - 1);
}

int	ft_print_c(char c, t_format *format)
{
	int		res;
	size_t	len;
	char	*str;

	len = ft_max_size_t(1, format->width);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (-1);
	ft_makestr_c(str, c, len, format);
	res = ft_putstr_pf(str, format);
	ft_safe_free((void **)&str);
	return (res);
}

size_t	ft_numlen_d(int d, t_format *format)
{
	size_t	len;
	int		num;

	len = 0;
	num = d;
	while (d != 0)
	{
		d /= 10;
		len++;
	}
	if (format->precision != -1)
		len = ft_max_size_t(len, format->precision);
	if (num == 0 && format->precision == -1)
		len = 1;
	if (num < 0 || format->space)
		len++;
	return (len);
}

int	ft_itoa_pf(char *str, int d, size_t numlen, t_format *format)
{
	char	*s;
	size_t	len_s;

	s = ft_itoa(d);
	if (s == NULL)
		return (FAILURE);
	len_s = ft_strlen(s);
	if (d == 0)
		len_s = 0;
	if (d < 0 || format->space)
	{
		if (d < 0)
			s++;
		else
			len_s++;
		str++;
	}
	ft_memset(&str[0], '0', numlen - len_s);
	ft_memmove(&str[numlen - len_s], s, len_s);
	if (d < 0)
		s--;
	ft_safe_free((void **)&s);
	return (SUCCESS);
}

void	ft_sign_d(char *str, int d, size_t len, t_format *format)
{
	size_t	numlen;

	numlen = ft_numlen_d(d, format);
	if (d < 0)
	{
		if (format->minus || format->zero)
			str[0] = '-';
		else
			str[len - numlen] = '-';
	}
	else if (format->space)
	{
		if (format->minus || format->zero)
			str[0] = ' ';
		else
			str[len - numlen] = ' ';
	}
}

int	ft_makestr_d(char *str, int d, size_t len, t_format *format)
{
	size_t	numlen;

	str[len] = '\0';
	numlen = ft_numlen_d(d, format);
	if (format->zero)
		ft_memset(str, '0', len);
	else
		ft_memset(str, ' ', len);
	ft_sign_d(str, d, len, format);
	if (format->minus)
	{
		if (!ft_itoa_pf(&str[0], d, numlen, format))
			return (FAILURE);
		ft_memset(&str[numlen], ' ', len - numlen);
	}
	else
	{
		if (!ft_itoa_pf(&str[len - numlen], d, numlen, format))
			return (FAILURE);
	}
	return (SUCCESS);
}

int	ft_print_d(int d, t_format *format)
{
	int		res;
	size_t	len;
	char	*str;

	len = ft_max_size_t(ft_numlen_d(d, format), format->width);
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (-1);
	if (format->precision != -1)
		format->zero = 0;
	if (!ft_makestr_d(str, d, len, format))
	{
		ft_safe_free((void **)&str);
		return (-1);
	}
	res = ft_putstr_pf(str, format);
	ft_safe_free((void **)&str);
	return (res);
}

void	ft_makestr_s(char *str, char *s, size_t len, t_format *format)
{
	size_t	len_s;

	str[len] = '\0';
	if (format->zero)
		ft_memset(str, '0', len);
	else
		ft_memset(str, ' ', len);
	len_s = ft_strlen(s);
	if (format->precision != -1 && format->precision < len)
		len_s = format->precision;
	if (format->minus)
	{
		ft_memmove(&str[0], s, len_s);
		ft_memset(&str[len_s], ' ', len - len_s);
	}
	else
		ft_memmove(&str[len - len_s], s, len_s);
}

int	ft_print_s(char *s, t_format *format)
{
	int		res;
	size_t	len;
	char	*str;

	len = ft_strlen(s);
	if (format->precision != -1 && format->precision < len)
		len = format->precision;
	len = ft_max_size_t(len, format->width);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (-1);
	ft_makestr_s(str, s, len, format);
	res = ft_putstr_pf(str, format);
	ft_safe_free((void **)&str);
	return (res);
}

size_t	ft_numlen_u(unsigned int u, t_format *format)
{
	size_t			len;
	unsigned int	num;

	num = u;
	len = 0;
	while (u != 0)
	{
		u /= 10;
		len++;
	}
	if (format->precision != -1)
		len = ft_max_size_t(len, format->precision);
	if (num == 0 && format->precision == -1)
		len = 1;
	return (len);
}


char	*ft_utoa(unsigned int u)
{
	char			*str;
	size_t			len;
	unsigned int	num;

	num = u;
	len = 0;
	if (u == 0)
		len = 1;
	while (u != 0)
	{
		u /= 10;
		len++;
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	while (len > 0)
	{
		str[len - 1] = num % 10 + '0';
		num /= 10;
		len--;
	}
	return (str);
}

int	ft_utoa_pf(char *str, unsigned int u, size_t numlen, t_format *format)
{
	char	*s;
	size_t	len_s;

	s = ft_utoa(u);
	if (s == NULL)
		return (FAILURE);
	len_s = ft_strlen(s);
	if (u == 0)
		len_s = 0;
	ft_memset(&str[0], '0', numlen);
	ft_memmove(&str[numlen - len_s], s, len_s);
	ft_safe_free((void **)&s);
	return (SUCCESS);
}

int	ft_makestr_u(char *str, unsigned int u, size_t len, t_format *format)
{
	size_t	numlen;

	str[len] = '\0';
	if (format->zero)
		ft_memset(str, '0', len);
	else
		ft_memset(str, ' ', len);
	numlen = ft_numlen_u(u, format);
	if (format->minus)
	{
		if (!ft_utoa_pf(&str[0], u, numlen, format))
			return (FAILURE);
		ft_memset(&str[numlen], ' ', len - numlen);
	}
	else
	{
		if (!ft_utoa_pf(&str[len - numlen], u, numlen, format))
			return (FAILURE);
	}
	return (SUCCESS);
}

int	ft_print_u(unsigned int u, t_format *format)
{
	int		res;
	size_t	len;
	char	*str;

	len = ft_max_size_t(ft_numlen_u(u, format), format->width);
	str = (char * )malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (-1);
	if (format->precision != -1)
		format->zero = 0;
	if (!ft_makestr_u(str, u, len, format))
	{
		ft_safe_free((void **)&str);
		return (-1);
	}
	res = ft_putstr_pf(str, format);
	ft_safe_free((void **)&str);
	return (res);
}

int	ft_print_format(va_list *args, t_format *format)
{
	if (format->type == 'c')
		return (ft_print_c(va_arg(*args, int), format));
	else if (format->type == '%')
		return (ft_print_c('%', format));
	else if (format->type == 's')
		return (ft_print_s(va_arg(*args, char *), format));
	else if (format->type == 'd' || format->type == 'i')
		return (ft_print_d(va_arg(*args, int), format));
	else if (format->type == 'u')
		return (ft_print_u(va_arg(*args, unsigned int), format));
	// else if (format->type == 'x')
	// 	return (ft_print_x(va_arg(*args, unsigned int), format));
	// else if (format->type == 'X')
	// 	return (ft_print_large_x(va_arg(*args, unsigned int), format));
	// else if (format->type == 'p')
	// 	return (ft_print_p(va_arg(*args, uintptr_t), format));
	else
		return (ft_print_c(format->type, format));
}

int	ft_format(char **s, va_list *args, t_format *format)
{
	(*s)++;
	ft_readformat(s, args, format);
	if (format->type == 0)
		return (0);
	return (ft_print_format(args, format));
}

int	ft_putchar_pf(char c, t_format *format)
{
	if (INT_MAX - format->len < 1)
		return (-1);
	return (write(1, &c, 1));
}


int	ft_printstr(char *s, va_list *args)
{
	char		*str;
	t_format	format;
	int			len;

	format.len = 0;
	while (*s != '\0')
	{
		if (*s == '%')
			len = ft_format(&s, args, &format);
		else
		{
			len = ft_putchar_pf(*s, &format);
			s++;
		}
		if (len == -1)
			return (-1);
		format.len += len;
	}
	return (format.len);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			len;

	va_start(args, format);
	len = ft_printstr((char *)format, &args);
	va_end(args);
	return (len);
}
