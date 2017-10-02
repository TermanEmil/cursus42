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

# $(shell find src -name '*.c')


NAME		=	libftprintf.a
FLAGS		=	-Wall -Wextra -Werror
CC			=	gcc $(FLAGS)

SRC_PRINTF	=	$(shell find src -name '*.c')
SRC_LIBFT	=	$(shell find libft/src -name '*.c')
SRC			=	$(SRC_LIBFT) $(SRC_PRINTF)

INCLUDES	=	-I includes -I libft/includes
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
		@gcc .main.c $(INCLUDES) $(SRC) libft/libft.a -o rs

#@gcc .main.c $(INCLUDES) $(SRC) libft/libft.a -o rs
#@gcc $(FLAGS) -c $(SRC) $(INCLUDES)
#@$(MKDIR) $(OBJDIR)
#@$(MV) $(OBJ) $(OBJDIR)
#@ar rc $(NAME) $(OBJS)
#@ranlib $(NAME)

clean:
		@$(RM) $(OBJS)
		@$(RMRF) $(OBJDIR)

fclean: clean
		@$(RM) $(NAME)

re: fclean all

main:
	@gcc .main.c $(INCLUDES) $(NAME) -o rs

run:
	@./rs

sure: re run