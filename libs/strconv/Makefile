LIB_NAME	=   strconv
NAME		=	$(LIB_NAME).a
FLAGS 		=	-g -Wall -Wextra -Werror
CC			=   gcc

DIR_OBJECTS	=	./obj
DIR_INCLUDE	=   ../includes
DIR_FILES	=   ./src
DIR_COMMON	=	../common

LIB_COMMON	=	$(DIR_COMMON)/common.a

FILE_NAMES 	=	ft_atoi_base.c		\
				ft_atoi.c			\
				ft_atoll.c			\
				ft_itoa.c			\
				ft_szttoa.c			\
				ft_ulltoa_base.c

#FILE_NAMES	=	ft_atoi_base.c

FILES	=	$(addprefix $(DIR_FILES)/, $(FILE_NAMES))
OBJECTS	=	$(addprefix $(DIR_OBJECTS)/, $(FILE_NAMES:.c=.o))

all : $(NAME)

$(NAME) : $(OBJECTS) $(DIR_INCLUDE)/strconv.h
			@make -C $(DIR_COMMON)
			@echo -n "Compiling $(LIB_NAME) files "
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
			@make -C $(DIR_COMMON) clean

fclean : clean
			@echo -n "remove $(NAME) library"
			@rm -f $(NAME)
			@echo "\t -- \033[32mDone\033[m"
			@make -C $(DIR_COMMON) fclean

.PHONY: all, clean, fclean, re

re: fclean all
