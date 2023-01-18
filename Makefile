CC		= gcc
# CFLAGS		= -Wall -Werror -Wextra -g -I includes
CFLAGS		= -g -I includes
RM		= rm -rf

SRCS		= $(wildcard srcs/*.c builtins/*.c execution/*.c parsing/*.c utils/*.c main.c)
SRC_DIRS	= $(dir $(SRCS))
OBJ_DIR		= bin/
OBJS		= $(SRCS:%.c=$(OBJ_DIR)%.o)
INCLUDE_FILES	= $(wildcard includes/*.h)

NAME		= minishell

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

$(OBJ_DIR)%.o: %.c $(INCLUDE_FILES)
	@mkdir -p $(OBJ_DIR) $(foreach dir, $(SRC_DIRS), $(OBJ_DIR)/$(dir))
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)

fclean:	clean
	$(RM) $(NAME)

re: fclean all
