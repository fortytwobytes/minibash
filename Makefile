CC			= cc
CFLAGS		=  -g -I includes # -Wall -Wextra -Werror 
RM			= rm -rf
MKDIR		= mkdir -p
COMP        = -L/goinfre/mtagemou/.brew/opt/readline/lib
LINK 		= -I/goinfre/mtagemou/.brew/opt/readline/include

SRCS		= $(wildcard srcs/*.c builtins/*.c execution/*.c parsing/*.c utils/*.c main.c)
SRCS_DIRS	= $(dir $(SRCS))

BIN_DIR		= bin/

OBJS		= $(SRCS:%.c=$(BIN_DIR)%.o)
OBJS_DIRS	= $(dir $(OBJS))

INCLUDES	= $(wildcard includes/*.h)

NAME		= minishell

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) -L/goinfre/mtagemou/.brew/opt/readline/lib -I/goinfre/mtagemou/.brew/opt/readline/include -lreadline -fsanitize=address $(OBJS)  -o $(NAME)

$(BIN_DIR)%.o: %.c $(INCLUDES)
	@$(MKDIR) $(OBJS_DIRS)
	@$(CC) $(LINK) $(CFLAGS) -fsanitize=address -c $< -o $@

clean:
	@$(RM) $(BIN_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
