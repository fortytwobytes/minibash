CC			= cc
CFLAGS		=  -g -I includes # -Wall -Wextra -Werror 
RM			= rm -rf
MKDIR		= mkdir -p
COMP        = -L/goinfre/mtagemou/.brew/opt/readline/lib
LINK 		= -I/goinfre/mtagemou/.brew/opt/readline/include

RED             = \033[0;31m
GREEN           = \033[0;32m
YELLOW          = \033[0;33m
BLUE			= \033[0;34m
NO_COLOR        = \033[0m

SRCS		= $(wildcard srcs/*.c builtins/*.c execution/*.c parsing/*.c utils/*.c main.c)
SRCS_DIRS	= $(dir $(SRCS))

BIN_DIR		= bin/

OBJS		= $(SRCS:%.c=$(BIN_DIR)%.o)
OBJS_DIRS	= $(dir $(OBJS))

INCLUDES	= $(wildcard includes/*.h)

NAME		= minishell

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) -L/goinfre/mtagemou/.brew/opt/readline/lib -I/goinfre/mtagemou/.brew/opt/readline/include -lreadline $(OBJS)  -o $(NAME)

$(BIN_DIR)%.o: %.c $(INCLUDES)
	@$(MKDIR) $(OBJS_DIRS)
	@$(CC) $(LINK) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(BIN_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
