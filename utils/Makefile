CC		=	cc
# CFLAGS	=	-Wall -Wextra -Werror -g -I
CFLAGS	=	-g -I
AR		=	ar rcs

NAME	=	../utils.a

SRCS	=	test_utils.c	

OBJ_DIR	=	../bin/
OBJS	=	$(addprefix $(OBJ_DIR),$(SRCS:.c=.o))

INC_DIR	=	../includes/
INCLUDE	=	$(addprefix $(INC_DIR),utils.h)

all:	$(NAME)

$(NAME):	$(OBJS)
	@$(AR) $(NAME) $(OBJS)

$(OBJ_DIR)%.o:	%.c $(INCLUDE)
	@$(CC) $(CFLAGS) $(INC_DIR) -c $< -o $@