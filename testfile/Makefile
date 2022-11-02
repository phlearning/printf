
CFLAGS = -Wall -Wextra -Werror

GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
END=\033[0m

SRCS		= test.c

OBJS		= $(SRCS:.c=.o)

.c.o:
			@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

test:	$(OBJS)
		@make -C ../libft
		cp ../libft/libft.a .
		@gcc $(CFLAGS) $(SRCS) -o test -L. -lft
		@echo "$(GREEN)Compiled test successfully$(RED)"


all:	test

clean:
		@make clean -C ../libft
		@rm -f test
		@echo "$(RED)Deleted test$(END)"

fclean:	clean
		@make fclean -C ../libft
		@rm -f test
		@echo "$(RED)Fcleaned$(END)"

re:		fclean all
		@echo "$(GREEN)Recompiled everything$(END)"