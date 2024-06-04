CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99
INCS = -I ./includes/


SRCDIR = srcs/
SRCS_FIL = \
			assign_idx.c \
			build_stack.c \
			calculate_cost.c \
			do_both.c \
			ft_array_utils.c \
			ft_stack_utils.c \
			main.c \
			midpoint.c \
			moves_counter.c \
			operations.c \
			sort_reorder.c \
			target_finder.c  \
			validator.c

SRCS = $(addprefix $(SRCDIR), $(SRCS_FIL))

OBJDIR = objs/
OBJS = $(addprefix $(OBJDIR), $(notdir $(SRCS:.c=.o)))

# bonus
BONDIR = bonus/
BONUS_SRCS_FIL = \
				validator_bonus.c \
				checker_main_bonus.c \
				do_both_bonus.c \
				ft_array_utils_bonus.c \
				ft_stack_utils_bonus.c \
				operations_bonus.c
BONUS_SRCS = $(addprefix $(BONDIR), $(BONUS_SRCS_FIL))
BONUS_OBJS = $(addprefix $(OBJDIR), $(notdir $(BONUS_SRCS:.c=.o)))


# library
LIBFTDIR = libft/
LIBFT.A = $(LIBFTDIR)libft.a


NAME = $(PUSH_SWAP) $(CHECKER)
PUSH_SWAP = push_swap
CHECKER = checker

all:  $(OBJDIR) $(PUSH_SWAP)

bonus: $(OBJDIR) $(CHECKER)

$(OBJDIR):
		mkdir -p $(OBJDIR)

$(PUSH_SWAP): $(OBJS)
		make -C $(LIBFTDIR)
		$(CC) $(CFLAGS) $(OBJS) -o $(PUSH_SWAP) -L$(LIBFTDIR) -lft

$(CHECKER): $(BONUS_OBJS)
		make -C $(LIBFTDIR)
		$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(CHECKER) -L$(LIBFTDIR) -lft

$(OBJDIR)%.o: $(BONDIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

RM = rm -f

clean:
		# $(RM) $(OBJS)
		rm -rf $(OBJDIR)
		make clean -C ${LIBFTDIR}

fclean: clean
		$(RM) $(PUSH_SWAP) $(CHECKER)
		make fclean -C $(LIBFTDIR)

re: fclean all

.PHONY: all clean fclean re bonus
