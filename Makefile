CC			= gcc
CFLAGS		= -g -I includes # -Wall -Wextra -Werror
RM			= rm -rf
MKDIR		= mkdir -p

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
	@echo -e "$(YELLOW)Linking object files... $(NO_COLOR)"
	@$(CC) $(OBJS) -o $(NAME)
	@echo -e "$(GREEN)Build completed successfully!$(NO_COLOR)"

$(BIN_DIR)%.o: %.c $(INCLUDES)
	@$(MKDIR) $(OBJS_DIRS)
	@echo -e "$(BLUE)[Compiling] $(NO_COLOR) $<"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo -e "$(RED)Cleaning up object files... $(NO_COLOR)"
	@$(RM) $(BIN_DIR)

fclean: clean
	@echo -e "$(RED)Cleaning up executable... $(NO_COLOR)"
	@$(RM) $(NAME)

re: fclean all
