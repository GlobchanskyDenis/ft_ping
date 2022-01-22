LIB_NAME	=   ft_ping
NAME		=	$(LIB_NAME)
FLAGS 		=	-g -Wall -Wextra -Werror
CC			=   gcc

DIR_OBJECTS	=	./obj
DIR_INCLUDE	=   ./
DIR_FILES	=   ./src
DIR_STRCONV =   ./libs/strconv/
DIR_COMMON  =   ./libs/common/

FILE_NAMES 	=	main.c

FILES	=	$(addprefix $(DIR_FILES)/, $(FILE_NAMES))
OBJECTS	=	$(addprefix $(DIR_OBJECTS)/, $(FILE_NAMES:.c=.o))

# TEST_FILES	=  $(shell (make -C $(DIR_STRCONV) get))

GET_STRCONV_FILES	=	$(addprefix $(DIR_STRCONV), $(shell (make --no-print-directory -C $(DIR_STRCONV) get)))
GET_STRCONV_FILES	=	$(addprefix $(DIR_COMMON), $(shell (make --no-print-directory -C $(DIR_COMMON) get)))

LIB_STRCONV	=	$(DIR_STRCONV)strconv.a
LIB_COMMON	=	$(DIR_COMMON)common.a

all : $(NAME)

# $(CC) $(FLAGS) -o $(NAME) $(OBJECTS) $(LIB_COMMON) $(LIB_STRCONV)

$(NAME) : $(OBJECTS) $(DIR_INCLUDE)/ft_ping.h
			@make -C $(DIR_COMMON)
			@make -C $(DIR_STRCONV)
			@ar -x $(LIB_COMMON) --output $(DIR_OBJECTS)
			@ar -x $(LIB_STRCONV) --output $(DIR_OBJECTS)
			@echo -n "Compiling $(LIB_NAME) project"
			$(CC) $(FLAGS) -o $(NAME) $(DIR_OBJECTS)/*.o
			@echo "\t -- \033[32mDone\033[m"

$(DIR_OBJECTS)/%.o : $(FILES)
			@mkdir -p $(DIR_OBJECTS)
			@$(CC) -c $(FLAGS) -I $(DIR_INCLUDE)/ $< -o $@

clean :
			@echo -n "removing $(LIB_NAME) objects"
			@rm -rf $(DIR_OBJECTS)
			@rm -rf .DS_Store
			@echo "\t -- \033[32mDone\033[m"
			@make -C $(DIR_STRCONV) clean
			@make -C $(DIR_COMMON) clean

fclean : clean
			@echo -n "remove $(NAME) library"
			@rm -f $(NAME)
			@echo "\t -- \033[32mDone\033[m"
			@make -C $(DIR_STRCONV) fclean
			@make -C $(DIR_COMMON) fclean

.PHONY: all, clean, fclean, re

test :
			@echo $(TEST_TEST_FILES)
#echo $(@make -C $(DIR_STRCONV) get)

re: fclean all
