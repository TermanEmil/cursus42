# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eterman <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/22 12:15:47 by eterman           #+#    #+#              #
#    Updated: 2016/10/22 15:33:03 by eterman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		libft.a
FLAGS =		-Wall -Wextra -Werror
CC =		gcc $(FLAGS)
INC_DIRS =	$(shell find includes -type d)
INCLUDES =	$(foreach d, $(INC_DIRS), -I$d)

SRC = $(shell find src -name '*.c')

OBJ			=	*.o
OBJDIR		=	./obj/
OBJS		=	$(addprefix $(OBJDIR), $(OBJ))

ifeq ($(OS),Windows_NT)
	RM = del
	RMRF = rd /s /q
	MV = move
	MKDIR = mkdir
else
	RM = rm -f
	RMRF = rm -rf
	MV = mv
	MKDIR = mkdir -p
endif

all: $(NAME)

$(NAME):
		@gcc $(FLAGS) -c $(SRC) $(INCLUDES)
		@$(MKDIR) $(OBJDIR)
		@$(MV) $(OBJ) $(OBJDIR)
		@ar rc $(NAME) $(OBJS)
		@ranlib $(NAME)

clean:
		@$(RM) $(OBJS)
		@$(RMRF) $(OBJDIR)

fclean: clean
		@$(RM) $(NAME)

re: fclean all
