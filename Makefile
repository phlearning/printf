# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 13:33:42 by pvong             #+#    #+#              #
#    Updated: 2022/11/09 17:21:19 by pvong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT		= ./libft/libft.a

NAME		= libftprintf.a

SRCS		= ft_printf.c \
				srcs/ft_printnbr.c \
				srcs/ft_printhex.c \
				srcs/ft_printptr.c \

OBJS		= $(SRCS:.c=.o)

#Colors
GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
END=\033[0m

INCLUDES	= -I ./includes

CC			= gcc

CFLAGS		= -Wall -Werror -Wextra

.c.o:
			@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $(<:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			@$(MAKE) -C ./libft
			@cp libft/libft.a .
			@mv libft.a $(NAME)
			@ar rcs $(NAME) $(OBJS)
			@echo "$(Green)Compiled$(END)"

clean:
			@$(MAKE) clean -C ./libft
			@rm -f $(OBJS)
			@echo "$(RED)Cleaned$(END)"

fclean:		clean
			@$(MAKE) fclean -C ./libft
			@rm -f $(NAME)
			@echo "$(RED)Cleaned$(END)"


re:			fclean all
			@echo "$(BLUE)Recompiled$(END)"

rename:
ifeq (,$(wildcard ./main.c))
	@mv .main.c main.c
	@echo "$(GREEN)Renamed$(END)"
else 
	@mv main.c .main.c
	@echo "$(RED)Hidden$(END)"
endif 

test:		
			$(CC) $(CFLAGS) ft_printf.c main.c -L. -lftprintf -o test
			./test

rmtest:
			rm -rf test

.PHONY:		all clean fclean re test rename hide rmtest


