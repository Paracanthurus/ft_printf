# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aokubo <aokubo@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/07 16:16:37 by aokubo            #+#    #+#              #
#    Updated: 2022/08/01 17:06:13 by aokubo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
SRCS	= ft_printf.c
B_SRC	= ft_printf_bonus.c
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
