# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aokubo <aokubo@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/07 16:16:37 by aokubo            #+#    #+#              #
#    Updated: 2022/08/01 22:33:00 by aokubo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
SRCS	= ft_printf.c\
			ft_devide_type.c\
			ft_format_init.c\
			ft_isflag.c\
			ft_istype.c\
			ft_itoa_pf.c\
			ft_makestr_c.c\
			ft_makestr_d.c\
			ft_makestr_p.c\
			ft_makestr_s.c\
			ft_makestr_u.c\
			ft_makestr_x.c\
			ft_max_size_t.c\
			ft_numlen_d.c\
			ft_numlen_p.c\
			ft_numlen_u.c\
			ft_numlen_x.c\
			ft_prefix_p_pf.c\
			ft_prefix_x_pf.c\
			ft_print_c.c\
			ft_print_d.c\
			ft_print_format.c\
			ft_print_main.c\
			ft_print_noformat.c\
			ft_print_p.c\
			ft_print_s.c\
			ft_print_u.c\
			ft_print_x.c\
			ft_printf.c\
			ft_ptoa.c\
			ft_ptoa_pf.c\
			ft_putstr_pf.c\
			ft_readflag.c\
			ft_readformat.c\
			ft_readprecision.c\
			ft_readtype.c\
			ft_readwidth.c\
			ft_safe_free.c\
			ft_sign_d.c\
			ft_strlen_char.c\
			ft_utoa.c\
			ft_utoa_pf.c\
			ft_xtoa.c\
			ft_xtoa_pf.c\
			ft_xtoc.c
B_SRC	= ft_printf_bonus.c\
			ft_devide_type_bonus.c\
			ft_format_init_bonus.c\
			ft_isflag_bonus.c\
			ft_istype_bonus.c\
			ft_itoa_pf_bonus.c\
			ft_makestr_c_bonus.c\
			ft_makestr_d_bonus.c\
			ft_makestr_p_bonus.c\
			ft_makestr_s_bonus.c\
			ft_makestr_u_bonus.c\
			ft_makestr_x_bonus.c\
			ft_max_size_t_bonus.c\
			ft_numlen_d_bonus.c\
			ft_numlen_p_bonus.c\
			ft_numlen_u_bonus.c\
			ft_numlen_x_bonus.c\
			ft_prefix_p_pf_bonus.c\
			ft_prefix_x_pf_bonus.c\
			ft_print_c_bonus.c\
			ft_print_d_bonus.c\
			ft_print_format_bonus.c\
			ft_print_main_bonus.c\
			ft_print_noformat_bonus.c\
			ft_print_p_bonus.c\
			ft_print_s_bonus.c\
			ft_print_u_bonus.c\
			ft_print_x_bonus.c\
			ft_ptoa_bonus.c\
			ft_ptoa_pf_bonus.c\
			ft_putstr_pf_bonus.c\
			ft_readflag_bonus.c\
			ft_readformat_bonus.c\
			ft_readprecision_bonus.c\
			ft_readtype_bonus.c\
			ft_readwidth_bonus.c\
			ft_safe_free_bonus.c\
			ft_sign_d_bonus.c\
			ft_strlen_char_bonus.c\
			ft_utoa_bonus.c\
			ft_utoa_pf_bonus.c\
			ft_xtoa_bonus.c\
			ft_xtoa_pf_bonus.c\
			ft_xtoc_bonus.c
B_DIR	= bonus
B_SRCS	= $(addprefix $(B_DIR)/, $(B_SRC))
OBJS	= $(SRCS:.c=.o)
B_OBJS	= $(B_SRCS:.c=.o)
ifdef BONUS
 OBJS = $(B_OBJS)
endif
LIBFT	= libft/libft.a
AR		= ar rcs
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(LIBFT) $(OBJS)
			cp libft/libft.a $(NAME)
			$(AR) $(NAME) $(OBJS)

$(LIBFT):
			make bonus -C libft

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
			$(RM) $(OBJS) $(B_OBJS)
			make fclean -C libft

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

bonus:
			make BONUS=1

.PHONY:		all clean fclean re bonus
