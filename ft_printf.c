/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokubo <aokubo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 20:09:44 by aokubo            #+#    #+#             */
/*   Updated: 2022/08/01 18:31:19 by aokubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	ft_safe_free(void **p)
{
	free(*p);
	*p = NULL;
}

ssize_t	ft_putstr_pf(char *str, t_format *format)
{
	size_t	len;

	if (str == NULL)
		return (-1);
	len = ft_strlen(str);
	if (len >= (size_t)INT_MAX || format->len + len >= (size_t)INT_MAX)
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
	if (ft_istype(**s) || !(ft_isflag(**s) || ft_isdigit(**s) || **s == '*'
							|| **s == '.' || **s == '\0'))
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
	format->x_large = 0;
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
	if (format->minus)
		format->zero = 0;
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
	if (len >= (size_t)INT_MAX || format->len + len >= (size_t)INT_MAX)
		return (-1);
	res = write(1, str, len);
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
	else if (num == 0)
		len = 1;
	if (num < 0 || format->space || format->plus)
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
	if (d < 0 || format->plus || format->space)
	{
		if (d < 0)
		{
			s++;
			len_s--;
		}
		numlen--;
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
	else if (format->plus)
	{
		if (format->minus || format->zero)
			str[0] = '+';
		else
			str[len - numlen] = '+';
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

	if (format->precision != -1)
		format->zero = 0;
	len = ft_max_size_t(ft_numlen_d(d, format), format->width);
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (-1);
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
	if (format->precision != -1 && (size_t)format->precision < len_s)
		len_s = format->precision;
	if (format->minus)
		ft_memmove(&str[0], s, len_s);
	else
		ft_memmove(&str[len - len_s], s, len_s);
}

int	ft_print_s(char *s, t_format *format)
{
	int		res;
	size_t	len;
	char	*str;

	if (s == NULL)
		s = "(null)";
	len = ft_strlen(s);
	if (format->precision != -1 && (size_t)format->precision < len)
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
	else if (num == 0)
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

int	ft_utoa_pf(char *str, unsigned int u, size_t numlen)
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
		if (!ft_utoa_pf(&str[0], u, numlen))
			return (FAILURE);
	}
	else
	{
		if (!ft_utoa_pf(&str[len - numlen], u, numlen))
			return (FAILURE);
	}
	return (SUCCESS);
}

int	ft_print_u(unsigned int u, t_format *format)
{
	int		res;
	size_t	len;
	char	*str;

	if (format->precision != -1)
		format->zero = 0;
	len = ft_max_size_t(ft_numlen_u(u, format), format->width);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (-1);
	if (!ft_makestr_u(str, u, len, format))
	{
		ft_safe_free((void **)&str);
		return (-1);
	}
	res = ft_putstr_pf(str, format);
	ft_safe_free((void **)&str);
	return (res);
}

char	ft_xtoc(unsigned int x, int large)
{
	x %= 16;
	if (x < 10)
		return (x + '0');
	if (large)
		return (x - 10 + 'A');
	return (x - 10 + 'a');
}

char	*ft_xtoa(unsigned int x, int large)
{
	char			*str;
	size_t			len;
	unsigned int	num;

	num = x;
	len = 0;
	if (x == 0)
		len = 1;
	while (x != 0)
	{
		x /= 16;
		len++;
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	while (len > 0)
	{
		str[len - 1] = ft_xtoc(num % 16, large);
		num /= 16;
		len--;
	}
	return (str);
}

size_t	ft_numlen_x(unsigned int x, t_format *format)
{
	size_t			len;
	unsigned int	num;

	num = x;
	len = 0;
	while (x != 0)
	{
		x /= 16;
		len++;
	}
	if (format->precision != -1)
		len = ft_max_size_t(len, format->precision);
	else if (num == 0)
		len = 1;
	if (format->sharp && num != 0)
		len += 2;
	return (len);
}

void	ft_prefix_x_pf(char *str, unsigned int x, size_t len, t_format *format)
{
	size_t	numlen;

	numlen = ft_numlen_x(x, format);
	if (format->sharp && x != 0)
	{
		if (format->minus || format->zero)
		{
			if (format->x_large)
				ft_memmove(&str[0], "0X", 2);
			else
				ft_memmove(&str[0], "0x", 2);
		}
		else
		{
			if (format->x_large)
				ft_memmove(&str[len - numlen], "0X", 2);
			else
				ft_memmove(&str[len - numlen], "0x", 2);
		}
	}
}

int	ft_xtoa_pf(char *str, unsigned int x, size_t numlen, t_format *format)
{
	char	*s;
	size_t	len_s;

	s = ft_xtoa(x, format->x_large);
	if (s == NULL)
		return (FAILURE);
	len_s = ft_strlen(s);
	if (x == 0)
		len_s = 0;
	if (format->sharp && x != 0)
	{
		numlen -= 2;
		str += 2;
	}
	ft_memset(&str[0], '0', numlen - len_s);
	ft_memmove(&str[numlen - len_s], s, len_s);
	ft_safe_free((void **)&s);
	return (SUCCESS);
}

int	ft_makestr_x(char *str, unsigned int x, size_t len, t_format *format)
{
	size_t	numlen;

	str[len] = '\0';
	if (format->zero)
		ft_memset(str, '0', len);
	else
		ft_memset(str, ' ', len);
	numlen = ft_numlen_x(x, format);
	ft_prefix_x_pf(str, x, len, format);
	if (format->minus)
	{
		if (!ft_xtoa_pf(&str[0], x, numlen, format))
			return (FAILURE);
	}
	else
	{
		if (!ft_xtoa_pf(&str[len - numlen], x, numlen, format))
			return (FAILURE);
	}
	return (SUCCESS);
}

int	ft_print_x(unsigned int x, t_format *format)
{
	int		res;
	size_t	len;
	char	*str;

	if (format->precision != -1)
		format->zero = 0;
	len = ft_max_size_t(ft_numlen_x(x, format), format->width);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (-1);
	if (!ft_makestr_x(str, x, len, format))
	{
		ft_safe_free((void **)&str);
		return (-1);
	}
	res = ft_putstr_pf(str, format);
	ft_safe_free((void **)&str);
	return (res);
}

size_t	ft_numlen_p(uintptr_t p, t_format *format)
{
	size_t		len;
	uintptr_t	num;

	num = p;
	len = 0;
	while (p != 0)
	{
		p /= 16;
		len++;
	}
	if (format->precision != -1)
		len = ft_max_size_t(len, format->precision);
	else if (num == 0)
		len = 1;
	len += 2;
	return (len);
}

void	ft_prefix_p_pf(char *str, uintptr_t p, size_t len, t_format *format)
{
	size_t	numlen;

	numlen = ft_numlen_p(p, format);
	if (format->minus || format->zero)
		ft_memmove(&str[0], "0x", 2);
	else
		ft_memmove(&str[len - numlen], "0x", 2);
}

char	*ft_ptoa(uintptr_t p)
{
	char		*str;
	size_t		len;
	uintptr_t	num;

	num = p;
	len = 0;
	while (p != 0)
	{
		p /= 16;
		len++;
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	while (len > 0)
	{
		str[len - 1] = ft_xtoc(num % 16, 0);
		num /= 16;
		len--;
	}
	return (str);
}

int	ft_ptoa_pf(char *str, uintptr_t p, size_t numlen)
{
	char	*s;
	size_t	len_s;

	s = ft_ptoa(p);
	if (s == NULL)
		return (FAILURE);
	len_s = ft_strlen(s);
	if (p == 0)
		len_s = 0;
	numlen -= 2;
	str += 2;
	ft_memset(&str[0], '0', numlen - len_s);
	ft_memmove(&str[numlen - len_s], s, len_s);
	ft_safe_free((void **)&s);
	return (SUCCESS);
}

int	ft_makestr_p(char *str, uintptr_t p, size_t len, t_format *format)
{
	size_t	numlen;

	str[len] = '\0';
	if (format->zero)
		ft_memset(str, '0', len);
	else
		ft_memset(str, ' ', len);
	numlen = ft_numlen_p(p, format);
	ft_prefix_p_pf(str, p, len, format);
	if (format->minus)
	{
		if (!ft_ptoa_pf(&str[0], p, numlen))
			return (FAILURE);
	}
	else
	{
		if (!ft_ptoa_pf(&str[len - numlen], p, numlen))
			return (FAILURE);
	}
	return (SUCCESS);
}

int	ft_print_p(uintptr_t p, t_format *format)
{
	int		res;
	size_t	len;
	char	*str;

	if (format->precision != -1)
		format->zero = 0;
	len = ft_max_size_t(ft_numlen_p(p, format), format->width);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (-1);
	if (!ft_makestr_p(str, p, len, format))
	{
		ft_safe_free((void **)&str);
		return (-1);
	}
	res = ft_putstr_pf(str, format);
	ft_safe_free((void **)&str);
	return (res);
}

int	ft_devide_type(va_list *args, t_format *format)
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
	else if (format->type == 'x')
		return (ft_print_x(va_arg(*args, unsigned int), format));
	else if (format->type == 'X')
	{
		format->x_large = 1;
		return (ft_print_x(va_arg(*args, unsigned int), format));
	}
	else if (format->type == 'p')
		return (ft_print_p(va_arg(*args, uintptr_t), format));
	return (ft_print_c(format->type, format));
}

int	ft_print_format(char **s, va_list *args, t_format *format)
{
	(*s)++;
	ft_readformat(s, args, format);
	if (format->type == 0)
		return (0);
	return (ft_devide_type(args, format));
}

size_t	ft_strlen_char(char *str, char c)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0' && str[len] != c)
		len++;
	return (len);
}

int	ft_print_char_pf(char **str, t_format *format)
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

int	ft_printstr(char *s, va_list *args)
{
	t_format	format;
	int			len;

	format.len = 0;
	while (*s != '\0')
	{
		if (*s == '%')
			len = ft_print_format(&s, args, &format);
		else
			len = ft_print_char_pf(&s, &format);
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
