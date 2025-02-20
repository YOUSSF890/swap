CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_split.c  ft_handel.c ft_handel2.c ft_handel3.c init_stack.c  number_argement.c one_hundred_argerment.c push.c rr.c rrr.c ss.c push_swap.c ft_atoi.c get_next_line.c get_next_line_utils.c checker_bones.c push_bones.c ft_print_ok_and_ko.c rr_bones.c rrr_bones.c ss_bones.c

OBJ = $(SRC:%.c=%.o)
NAME = push_swap
HFILE = push_swap.h

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(SRC) -o $@

%.o: %.c $(HFILE)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean