# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eterman <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/22 12:15:47 by eterman           #+#    #+#              #
#    Updated: 2016/12/27 20:02:30 by eterman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	ft_ls
FLAGS		=	-Wall -Wextra -Werror
CC			=	gcc $(FLAGS)

SRC_PROJ	=	$(shell find src -name '*.c')
SRC			=	$(SRC_PROJ)

INC_LIBFT	=	$(shell find libft/includes -type d)
INC_LIBFT_P	=	$(foreach d, $(INC_LIBFT), -I$d)

INC_DIRS	=	$(shell find includes -type d)
INC_PROJ	=	$(foreach d, $(INC_DIRS), -I$d)

INCLUDES	=	$(INC_PROJ) $(INC_LIBFT_P)

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
		@gcc $(INCLUDES) -c $(SRC)
		@$(MKDIR) $(OBJDIR)
		@$(MV) $(OBJ) $(OBJDIR)
		@gcc $(OBJDIR)/$(OBJ) $(INCLUDES) libft/libft.a -o $(NAME)

clean:
		@$(RM) $(OBJS)
		@$(RMRF) $(OBJDIR)

fclean: clean
		@$(RM) $(NAME)

re: fclean all

run:
	@./$(NAME)

sure: re run
