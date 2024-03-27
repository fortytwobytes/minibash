CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I includes 
RM			= rm -rf
MKDIR		= mkdir -p
USERS		= $(USER)

OS           := $(shell uname -s)
ifeq ($(OS),Linux)
    READLINE_LINK := -lreadline
else
    READLINE_DIR  := $(shell brew --prefix readline)
    READLINE_COMP := -L$(READLINE_DIR)/lib
    READLINE_LINK := -I$(READLINE_DIR)/include
endif

SRCS		= helpers/ft_close.c helpers/ft_dups.c helpers/ft_execve.c helpers/ft_fork.c helpers/ft_open.c helpers/ft_pipe.c helpers/ft_waits.c builtins/cd.c builtins/echo.c builtins/env.c builtins/export.c builtins/helpers.c builtins/pwd.c builtins/shell_exit.c builtins/unset.c builtins/utils.c execution/environment.c execution/execute.c execution/heredoc.c execution/misc.c execution/paths.c execution/shell.c execution/signals.c parsing/commands.c parsing/commands_list.c parsing/env.c parsing/expand.c parsing/expand_env.c parsing/free.c parsing/heredoc.c parsing/lexer.c parsing/operator.c parsing/parser.c parsing/heredoc_expansion.c parsing/parsing_utils.c parsing/token_list.c parsing/word_spliting.c utils/alpha.c utils/contains.c utils/fatal.c utils/ft_atoi.c utils/ft_calloc.c utils/ft_exit.c utils/ft_free.c utils/ft_itoa.c utils/ft_memcpy.c utils/ft_split.c utils/ft_strcmp.c utils/ft_strdup.c utils/ft_strjoins.c utils/ft_strlen.c utils/ft_substr.c utils/prints.c main.c
SRCS_DIRS	= $(dir $(SRCS))

BIN_DIR		= build/

OBJS		= $(SRCS:%.c=$(BIN_DIR)%.o)
OBJS_DIRS	= $(dir $(OBJS))

INCLUDES	= includes/builtin.h includes/execution.h includes/minibash.h includes/parsing.h includes/helpers.h includes/utils.h

NAME		= minibash


all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $(NAME) $(READLINE_LINK)

$(BIN_DIR)%.o: %.c $(INCLUDES)
	@$(MKDIR) $(OBJS_DIRS)
	$(CC) $(READLINE_COMP) $(CFLAGS)  -c $< -o $@

clean:
	@$(RM) $(BIN_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
