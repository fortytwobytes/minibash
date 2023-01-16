NAME		=	minishell	
RM			=	rm -rf
OBJ_DIR		=	bin/
UTILS		=	utils.a
SRCS		=	srcs.a

all:	$(NAME) 

$(NAME):	$(UTILS) $(SRCS)
	@$(CC) $(CFLAGS) $(INC_DIR) $(UTILS) $(SRCS) -o $(NAME)
	@echo "compiled"

$(UTILS):
	@mkdir -p $(OBJ_DIR)
	@make -C utils

$(SRCS):
	@mkdir -p $(OBJ_DIR)
	@make -C srcs

clean:
	@$(RM) $(OBJ_DIR) $(UTILS) $(SRCS)
	@echo "cleaned"

fclean:	clean
	@$(RM) $(NAME)
	@echo "erased"

re:	fclean all
