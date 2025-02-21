CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address

SRC = ft_split.c  ft_handel.c ft_handel2.c ft_handel3.c init_stack.c  number_argement.c one_hundred_argerment.c push.c rr.c rrr.c ss.c push_swap.c ft_atoi.c 

SRC_BONUS =  bonus/checker_bonus.c bonus/push_bonus.c bonus/init_stack_bonus.c bonus/ft_split_bonus.c bonus/ft_atoi_bonus.c bonus/rr_bonus.c  bonus/rrr_bonus.c  bonus/ss_bonus.c bonus/ft_print_ok_and_ko_bonus.c bonus/get_next_line.c bonus/get_next_line_utils.c bonus/ft_handel_bonus.c bonus/ft_handel2_bonus.c bonus/ft_handel3_bonus.c
OBJ = $(SRC:%.c=%.o)
OBJ_BONUS = $(SRC_BONUS:%.c=%.o)

NAME = push_swap
NAME_BONUS = checker

HFILE = push_swap.h

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(SRC) -o $@

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(SRC_BONUS) -o $@

clean:
	rm -rf $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: clean