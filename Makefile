NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

PUSH_SWAP_SRCS = main.c error.c array.c node.c swap.c\
				rotate.c rev_rotate.c push.c compaction.c\
				sort.c sort3.c sort_u6.c sort_util.c\
				stack_util.c node_util.c
PUSH_SWAP_OBJS = $(PUSH_SWAP_SRCS:.c=.o)

LIBFT_OBJS = $(LIBFT_SRCS:.c=.o)
LIBFT_DIR = ./libft
LIBFT_A = ./libft/libft.a
INCLUDE = -I $(LIBFT_DIR)

all : $(NAME)

$(NAME) : $(PUSH_SWAP_OBJS)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -L $(LIBFT_DIR) -l ft -o $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	make clean -C $(LIBFT_DIR)
	$(RM) $(PUSH_SWAP_OBJS)

fclean : clean
	$(RM) $(LIBFT_A)
	$(RM) $(NAME)

re : fclean all