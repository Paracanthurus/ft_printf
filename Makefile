# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aokubo <aokubo@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/07 16:16:37 by aokubo            #+#    #+#              #
#    Updated: 2022/03/23 03:45:49 by aokubo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
SRCS	= ft_printf.c ft_printf_format.c ft_printf_read_format.c \
			ft_printf_cs.c ft_printf_d.c ft_printf_u.c ft_printf_x.c \
			ft_printf_large_x.c ft_printf_p.c
B_SRC	= ft_printf_bonus.c ft_printf_format_bonus.c \
			ft_printf_read_format_bonus.c ft_printf_cs_bonus.c \
			ft_printf_d_bonus.c ft_printf_u_bonus.c ft_printf_x_bonus.c \
			ft_printf_large_x_bonus.c ft_printf_p_bonus.c
B_DIR	= bonus
L_DIR	= libft
B_SRCS	= $(addprefix $(B_DIR)/, $(B_SRC))
OBJS	= $(SRCS:.c=.o)
B_OBJS	= $(B_SRCS:.c=.o)
ifdef BONUS
 OBJS = $(B_OBJS)
endif
LIBFT	= $(L_DIR)/libft.a
AR		= ar rcs
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
#INCLUDE	= -I. -I$(B_DIR) -I$(L_DIR)

$(NAME):	$(OBJS)
			make bonus -C $(L_DIR)
			cp $(LIBFT) $(NAME)
			$(AR) $(NAME) $^

all:		$(NAME)

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
			$(RM) $(OBJS) $(B_OBJS)
			make clean -C $(L_DIR)

fclean:		clean
			$(RM) $(NAME) $(LIBFT)

re:			fclean all

bonus:
			make BONUS=1

.PHONY:		all clean fclean re bonus
