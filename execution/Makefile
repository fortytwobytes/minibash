CC		=	cc
# CFLAGS	=	-Wall -Wextra -Werror -g -I
CFLAGS	=	-g -I
AR		=	ar rcs

NAME	=	../execution.a

SRCS	=	

OBJ_DIR	=	../bin/
OBJS	=	$(addprefix $(OBJ_DIR),$(SRCS:.c=.o))

INC_DIR	=	../includes/
INCLUDE	=	$(addprefix $(INC_DIR),execution.h)

all:	$(NAME)

$(NAME):	$(OBJS)
	@$(AR) $(NAME) $(OBJS)

$(OBJ_DIR)%.o:	%.c $(INCLUDE)
	@$(CC) $(CFLAGS) $(INC_DIR) -c $< -o $@