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

# -r - recursive.
# I'm sure there's a better way, but still... this is a working one.
#
# The following Makefile will recompile only the modified files from src and
# includes all headers -r from includes (and for my case, libft/includes -r)
#
# Use make -s (quiet mode).
# If you want to compile without flags, change $(COMPILE):
#	$(CC) $(INCLUDES) $(FLAGS).
#
# How it works ?
#	1) SRC finds all c files in 'src' (with full path).
#	2) SRC_FILES finds the name of each c file (without path).
#	3) INCLUDES includes all headers form all directories form the current
#		project includes and libft's includes.
#	4) Creates a rule for each '.o' file (here's the trick with compile
#		the modified only).

NAME		=	executable
LIBNAME		=	hashtablib.a
FLAGS		=	-Wall -Wextra -Werror
CC			=	gcc

LIBS_ROOT	=	../../
LIBS		=											\
				$(LIBS_ROOT)/hashtablib/hashtablib.a	\
				$(LIBS_ROOT)/listlib/listlib.a			\
				$(LIBS_ROOT)/libft/libft.a				\
				$(LIBS_ROOT)/unittestlib/utestlib.a		\
				$(LIBS_ROOT)/eventlib/eventlib.a

INC_DIRS	=	$(shell find includes -type d)
INC_PROJ	=	$(foreach d, $(INC_DIRS), -I $d)
INC_FILES	=	$(shell find src -name '*.h')

INCLUDES	=	$(INC_PROJ)								\
				-I $(LIBS_ROOT)/hashtablib/includes		\
				-I $(LIBS_ROOT)/libft/includes			\
				-I $(LIBS_ROOT)/listlib/includes		\
				-I $(LIBS_ROOT)/unittestlib/includes	\
				-I $(LIBS_ROOT)/eventlib/includes

# Compile can include flags or other stuff, so it can be useful when I
# want to compile without flags

# COMPILE		=	$(CC) $(FLAGS) $(INCLUDES)
COMPILE		=	$(CC) $(INCLUDES)

# Finds all '.c' files in 'src'

SRC			=	$(shell find src -name '*.c')
LIBSRC		=	$(shell find src -name '*.c' ! -iname 'main.c')

# This will contain an array of all SRC files without path.
# Ex: src/dir1/file.c --> file.c
# This functionality is used for OBJS

SRC_FILES	=	$(notdir $(SRC))

OBJDIR		=	objs
OBJS_NAMES	=	$(SRC_FILES:.c=.o)
OBJS		=	$(addprefix $(OBJDIR)/,$(OBJS_NAMES))

LIB_SRCFILES=	$(notdir $(LIBSRC))
LIB_OBJSNAME=	$(LIB_SRCFILES:.c=.o)
LIBOBJS		=	$(addprefix $(OBJDIR)/,$(LIB_OBJSNAME))

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

GREEN 		=	'\033[0;32m'
RED			=	'\033[0;31m'
CYAN 		=	'\033[0;36m'
EOC			=	'\033[0m'

define COMPILE_FILE
	@$(COMPILE) -c $(1) -o $(2)
	@(if [ $$? -eq 0 ] ; \
		then echo $(GREEN)$(1)$(EOC) ; fi)
endef

$(OBJDIR)/%.o: src/%.c
	$(call COMPILE_FILE,$<,$@)

$(OBJDIR)/%.o: src/*/%.c
	$(call COMPILE_FILE,$<,$@)

$(OBJDIR)/%.o: src/*/*/%.c
	$(call COMPILE_FILE,$<,$@)

$(OBJDIR)/%.o: src/*/*/*/%.c
	$(call COMPILE_FILE,$<,$@)

$(OBJDIR)/%.o: src/*/*/*/*/%.c
	$(call COMPILE_FILE,$<,$@)

$(OBJDIR)/%.o: src/*/*/*/*/*/%.c
	$(call COMPILE_FILE,$<,$@)

$(OBJDIR)/%.o: src/*/*/*/*/*/%.c
	$(call COMPILE_FILE,$<,$@)

# The main rule
# First, it makes sure that $(OBJDIR) exists.
# I pass as prerequisites all OBJS (and right above, I wrote a rule for each
#	'.o' file).


$(NAME): $(OBJDIR) $(OBJS) $(INC_FILES)
	@echo "\n"
	@echo $(CYAN)"Compiling program"$(EOC)
	@$(COMPILE) $(OBJS) $(LIBS) -o $(NAME) $(LIBS)

clean:
	rm -f $(OBJS)
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBNAME)

re: fclean all

recomp_libft:
	make re -C libft

rere: fclean recomp_libft all
	
lib: $(OBJDIR) $(LIBOBJS)
	@ar rc $(LIBNAME) $(LIBOBJS)
	ranlib $(LIBNAME)

run:
	./$(NAME)

sure: all run
