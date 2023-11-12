NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

PUSH_SWAP = push_swap
PUSH_SWAP_SRCS = push_swap.C
PUSH_SWAP_OBJS = $(PUSH_SWAP_SRCS:,c=.o)

LIBFT_OBJS = $(LIBFT_SRCS:.c=.o)
LIBFT_DIR = libft
INCLUDE = -I $(LIBFT_DIR)

all : $(NAME)

$(NAME) :
	make -C $(LIBFT_DIR)
	make $(PUSH_SWAP)

$(PUSH_SWAP) : $(PUSH_SWAP_OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) -L $(LIBFT_DIR) -l ft -o $@ $<

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	make clean -C $(LIBFT_DIR)
	$(RM) $(PUSH_SWAP_OBJS)

fclean : clean
	$(RM) $(PUSH_SWAP)

re : fclean all