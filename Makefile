# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 13:33:42 by pvong             #+#    #+#              #
#    Updated: 2022/11/02 18:41:06 by pvong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT		= ./libft/libft.a

NAME		= libftprintf.a

SRCS		= ft_printf.c \
				srcs/ft_printf_utils.c


OBJS		= $(SRCS:.c=.o)

INCLUDES	= -I ./includes

CC			= gcc

CFLAGS		= -Wall -Werror -Wextra

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			$(MAKE) -C ./libft
			cp libft/libft.a $(NAME)
			$(CC) $(FLAGS) $(INCLUDES) $(SRCS)
			ar rcs $(NAME) $(OBJS)

clean:
			$(MAKE) clean -C ./libft
			rm -f $(OBJS)

fclean:		clean
			$(MAKE) fclean -C ./libft
			rm -f $(NAME)

re:			fclean all

test:		
			./a.out

.PHONY:		all clean fclean re


