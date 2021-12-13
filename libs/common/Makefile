LIB_NAME	=   common
NAME		=	$(LIB_NAME).a
FLAGS 		=	-g -Wall -Wextra -Werror
CC			=   gcc

DIR_OBJECTS	=	./obj
DIR_INCLUDE	=   ../includes
DIR_FILES	=   ./src

# FILE_NAMES 	=	ft_isalnum.c		\
				ft_isalpha.c		\
				ft_isascii.c		\
				ft_isdigit.c		\
				ft_isprint.c		\
				isalldigit.c		\
				isallhex.c			\
				ishex.c

FILE_NAMES	=	ft_isalnum.c	ft_isdigit.c 

FILES	=	$(addprefix $(DIR_FILES)/, $(FILE_NAMES))
OBJECTS	=	$(addprefix $(DIR_OBJECTS)/, $(FILE_NAMES:.c=.o))

all : $(NAME)

$(NAME) : $(OBJECTS) $(DIR_INCLUDE)/common.h
			@echo -n "Compiling $(LIB_NAME) files"
			@ar rc $(NAME) $(OBJECTS)
			@ranlib $(NAME)
			@echo "\t -- \033[32mDone\033[m"

$(DIR_OBJECTS)/%.o : $(FILES)
			@mkdir -p $(DIR_OBJECTS)
			@$(CC) -c $(FLAGS) -I $(DIR_INCLUDE)/ $< -o $@

clean :
			@echo -n "removing $(LIB_NAME) objects"
			@rm -rf $(DIR_OBJECTS)
			@rm -rf .DS_Store
			@echo "\t -- \033[32mDone\033[m"

fclean : clean
			@echo -n "remove $(NAME) library"
			@rm -f $(NAME)
			@echo "\t -- \033[32mDone\033[m"

.PHONY: all, clean, fclean, re

re: fclean all
