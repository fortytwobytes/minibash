CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g -I includes 
CEXTRA		= -fsanitize=address,undefined,integer -Wshadow -Wuninitialized -Wunreachable-code
RM			= rm -rf
MKDIR		= mkdir -p
USERS		= $(USER)
COMP        = -L/goinfre/$(USERS)/.brew/opt/readline/lib
LINK 		= -I/goinfre/$(USERS)/.brew/opt/readline/include

SRCS		= $(wildcard srcs/*.c builtins/*.c execution/*.c parsing/*.c utils/*.c main.c debuggin.c)
SRCS_DIRS	= $(dir $(SRCS))

BIN_DIR		= bin/

OBJS		= $(SRCS:%.c=$(BIN_DIR)%.o)
OBJS_DIRS	= $(dir $(OBJS))

INCLUDES	= $(wildcard includes/*.h)

NAME		= minishell

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CEXTRA) $(CFLAGS) -L/goinfre/$(USERS)/.brew/opt/readline/lib -I/goinfre/$(USERS)/.brew/opt/readline/include -lreadline   $(OBJS)  -o $(NAME)

$(BIN_DIR)%.o: %.c $(INCLUDES)
	@$(MKDIR) $(OBJS_DIRS)
	@$(CC) $(LINK) $(CEXTRA) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(BIN_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
