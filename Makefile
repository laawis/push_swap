# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gaollier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/29 12:16:03 by gaollier          #+#    #+#              #
#    Updated: 2023/06/29 12:16:16 by gaollier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIST_SRC = stack_instructions.c \
    	   stack_primitive.c    \
           stack_utils.c		\
		   stack_a_moves.c		\
		   stack_b_moves.c		\
		   combo_moves.c		\
		   stack_init.c			\
		   sort.c				\
	       main.c
LIST_OBJ = $(LIST_SRC:.c=.o)
LIST_HEADER = stack.h

DIR_BUILD = .build/
DIR_SRC = src/
DIR_HEADER = include/
DIR_LIB = lib/
DIR_LIBFT = $(addprefix $(DIR_LIB), libft/)

# Shortcuts
SRC = $(addprefix $(DIR_SRC), $(LIST_SRC))
OBJ = $(addprefix $(DIR_BUILD), $(LIST_OBJ))
HEADER = $(addprefix $(DIR_HEADER), $(LIST_HEADER))
LIBFT = $(addprefix $(DIR_LIBFT), libft.a)

CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

.PHONY: all 
all: $(LIBFT) $(NAME)

$(NAME): $(DIR_BUILD) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L $(DIR_LIBFT) -lft

$(DIR_BUILD)%.o: $(DIR_SRC)%.c $(HEADER)
	$(CC) $(CFLAGS) $< -c -I $(DIR_HEADER) -I $(DIR_LIBFT) -o $@

$(DIR_BUILD):
	mkdir -p $(DIR_BUILD)

$(LIBFT):
	$(MAKE) -C $(DIR_LIBFT)

.PHONY: clean
clean:
	$(RM) $(OBJ)
	$(MAKE) -C $(DIR_LIBFT) clean

.PHONY: fclean
fclean:	clean
	$(RM) $(NAME)
	$(MAKE) -C $(DIR_LIBFT) fclean

.PHONY: re
re:	fclean
	$(MAKE) all
	$(MAKE) -C $(DIR_LIBFT) re

