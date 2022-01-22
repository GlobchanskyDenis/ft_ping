LIB_NAME	=   libft.a
FLAGS 		=	-g -Wall -Wextra -Werror

DIR_INCLUDE	=   ./
DIR_STRCONV =   ./strconv/
DIR_COMMON  =   ./common/

GET_STRCONV_OBJECTS	=	$(addprefix $(DIR_STRCONV), $(shell (make --no-print-directory -C $(DIR_STRCONV) get)))
GET_COMMON_OBJECTS	=	$(addprefix $(DIR_COMMON), $(shell (make --no-print-directory -C $(DIR_COMMON) get)))

$(LIB_NAME) : $(OBJECTS)
			@echo "Compiling libft files -- Start"
			@echo $(GET_STRCONV_OBJECTS)
			@echo ""
			@echo $(GET_COMMON_OBJECTS)
			@echo ""
			@ar rc $(LIB_NAME) $(GET_STRCONV_OBJECTS) $(GET_STRCONV_OBJECTS)
			@ranlib $(LIB_NAME)
			@echo "Compiling libft files -- Done"

#$(DIR_OBJECTS)/%.o : $(FILES)
#			@mkdir -p $(DIR_OBJECTS)
#			@$(CC) -c $(FLAGS) -I $(DIR_INCLUDE)/ $< -o $@

# $(DIR_O)/%.o : %.c libft.h
#			@mkdir -p $(DIR_O)
#			@gcc $(FLAGS) -o $@ -c $<

clean :
			@rm -f $(OBJECTS)
			@rm -rf $(DIR_O)
			@rm -rf .DS_Store

fclean : clean
			@echo "remove $(LIB_NAME)"
			@rm -f $(LIB_NAME)

.PHONY: all, clean, fclean, re

all : $(LIB_NAME)

re: fclean all