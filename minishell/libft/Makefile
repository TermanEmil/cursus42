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

# -r - recursive.
# I'm sure there's a better way, but still... this is a working one.
#
# The following Makefile will recompile only the modified files from src
#
# Use make -s (quiet mode).
# If you want to compile without flags, change $(COMPILE):
#	$(CC) $(INCLUDES) $(FLAGS).
#
# How it works ?
#	1) SRC finds all c files in 'src' (with full path).
#	2) SRC_FILES finds the name of each c file (without path).
#	3) INCLUDES includes all headers form all directories form the current.
#	4) Creates a rule for each '.o' file (here's the trick with compile
#		the modified only).

NAME		=	libft.a
FLAGS		=	-Wall -Wextra -Werror
CC			=	gcc

INC_DIRS	=	$(shell find includes -type d)
INC_PROJ	=	$(foreach d, $(INC_DIRS), -I $d)

INCLUDES	=	$(INC_PROJ)

# Compile can include flags or other stuff, so it can be useful when I
# want to compile without flags

COMPILE		=	$(CC) $(INCLUDES) $(FLAGS)

# Finds all '.c' files in 'src'

SRC			=	$(shell find src -name '*.c')

# This will contain an array of all SRC files without path.
# Ex: src/dir1/file.c --> file.c
# This functionality is used for OBJS

SRC_FILES	=	$(notdir $(SRC))

OBJDIR		=	objs
OBJS_NAMES	=	$(SRC_FILES:.c=.o)
OBJS		=	$(addprefix $(OBJDIR)/,$(OBJS_NAMES))

all: $(NAME)

# Quietly creates an $(OBJDIR) directory

$(OBJDIR):
	mkdir -p $(OBJDIR)

# Like this, I can make multiple directories in src.
# If it doesn't match the first, it goes to the second, etc ...
# Let's say I'm looking for f1.o and f1.c is located as src/dir0/f1.c:
#	First it will search if there's any match in src -- it won't match.
#	Then it will try to find it in any
#	subdirectory of src, and it's gonna find it.

$(OBJDIR)/%.o: src/%.c
	$(COMPILE) -c $< -o $@

$(OBJDIR)/%.o: src/*/%.c
	$(COMPILE) -c $< -o $@

$(OBJDIR)/%.o: src/*/*/%.c
	$(COMPILE) -c $< -o $@

$(OBJDIR)/%.o: src/*/*/*/%.c
	$(COMPILE) -c $< -o $@

$(OBJDIR)/%.o: src/*/*/*/*/%.c
	$(COMPILE) -c $< -o $@

$(OBJDIR)/%.o: src/*/*/*/*/*/%.c
	$(COMPILE) -c $< -o $@

$(OBJDIR)/%.o: src/*/*/*/*/*/%.c
	$(COMPILE) -c $< -o $@

# The main rule
# First, it makes sure that $(OBJDIR) exists.
# I pass as prerequisites all OBJS (and right above, I wrote a rule for each
#	'.o' file).


$(NAME): $(OBJDIR) $(OBJS)
	@ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -f $(OBJS)
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
