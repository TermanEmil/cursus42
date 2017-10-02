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

NAME		=	megaphone
FLAGS		=	-Wall -Wextra -Werror
CC			=	g++
EXTENSION	=	.cpp

ifeq ($(OS),Windows_NT)
	RMF = del /q /s
	RMDIR = rmdir
	GREEN 		=
	RED			=
	CYAN 		=
	EOC			=
else
	RMF = rm -f
	RMDIR = rm -rf
	GREEN 		=	'\033[0;32m'
	RED			=	'\033[0;31m'
	CYAN 		=	'\033[0;36m'
	EOC			=	'\033[0m'
endif

COMPILE		=	$(CC) $(FLAGS)

SRC			=	megaphone.cpp

SRC_FILES	=	$(notdir $(SRC))

OBJDIR		=	objs
OBJS_NAMES	=	$(SRC_FILES:$(EXTENSION)=.o)
OBJS		=	$(addprefix $(OBJDIR)/,$(OBJS_NAMES))
OBJS_TO_DEL =	$(addprefix $(OBJDIR)\,$(OBJS_NAMES))

all: $(NAME)

$(OBJDIR):
	mkdir $(OBJDIR)

define COMPILE_FILE
	@$(COMPILE) -c $(1) -o $(2)
endef

$(OBJDIR)/%.o: ./%.cpp
	$(call COMPILE_FILE,$<,$@)

#$(OBJDIR) $(OBJS)

$(NAME): $(OBJDIR) $(OBJS)
	@echo "\n"
	@echo $(CYAN)"Compiling program"$(EOC)
	@$(COMPILE) $(OBJS) -o $(NAME)

clean:
ifeq ($(OS),Windows_NT)
		$(RMF) $(OBJS_TO_DEL)
else
		$(RMF) $(OBJS)
endif
		$(RMDIR) $(OBJDIR)

fclean: clean
ifeq ($(OS),Windows_NT)
	$(RMF) $(NAME).exe
else
	$(RMF) $(NAME)
endif

re: fclean all

run:
	./$(NAME)

sure: all run
