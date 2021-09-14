# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/21 18:13:44 by lvirgini          #+#    #+#              #
#    Updated: 2021/06/21 21:40:24 by lvirgini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ----------------- #
#	 VARIABLES		#
# ----------------- #

NAME =		libft.a

HEADERS = 	./includes/libft.h

OBJ_DIR =	obj/
INC_DIR = 	$(shell find includes -type d)
SRC_DIR = 	$(shell find srcs -type d)

vpath %.c $(foreach dir, $(SRC_DIR), $(dir):)

SRC		= 	$(foreach dir, $(SRC_DIR), $(foreach file, $(wildcard $(dir)/*.c), $(notdir $(file))))
OBJ 	=	$(addprefix $(OBJ_DIR), $(SRC:%.c=%.o))

#TEST_DIR=	test/
#TEST_SRC=	$(foreach dir, $(TEST_DIR), $(foreach file, $(wildcard $(dir)/*.c), $(notdir $(file))))
#TEST_OBJ=	$(addprefix $(TEST_DIR), $(TEST_SRC:%.c=%.o))

# ----------------- #
#	 COMPILATION	#
# ----------------- #

CC = 		gcc

CFLAG =		-Wall -Werror -Wextra
IFLAG = 	$(foreach dir, $(INC_DIR), -I $(dir))
 

# ----------------- #
#	  FONCTIONS		#
# ----------------- #

$(OBJ_DIR)%.o: %.c $(HEADERS)
			@mkdir -p $(OBJ_DIR)
			@echo "\033[32mCompilation de ... $(foreach file, $< , $(notdir $<))"
			@$(CC) $(CFLAG) $(IFLAG) -o $@ -c $<
			
$(NAME):	$(OBJ) $(INC_DIR) Makefile
			@echo "\n\t\033[36;1m*.............................*"
			@echo "\n\t*     Compilation $(NAME)     *\t   \033[32;1m--------->>> \033[4;5mComplete\033[0m"
			@echo "\n\t\033[036;1m*.............................*\033[0m"
			@ar rcs ${NAME} ${OBJ}
	
all:		${NAME}

debug :		$(OBJ) $(INC_DIR) Makefile
			@$(CC) $(CFLAG) $(IFLAG) $(OBJ) test/main_test.c test/itoa_test.c

show	:
			@echo "SRC_DIR : $(SRC_DIR)\n"
			@echo "LIB_DIR : $(LIB_DIR)\n"
			@echo "INC_DIR : $(INC_DIR)\n"
			@echo "CFLAG : $(CFLAG)\n"
			@echo "IFLAG : $(IFLAG)\n"
			@echo "LFLAG : $(LFLAG)\n"
			@echo "HEADERS : $(foreach file, $(HEADERS),\n\t$(file))\n"
			@echo "SRC :$(foreach file, $(SRC),\n\t$(file))\n"
			@echo "OBJ :$(foreach file, $(OBJ),\n\t$(file))\n"


# ----------------- #
# 		CLEAN		#
# ----------------- #

clean:
			@rm -rf $(OBJ_DIR)
			@echo "\033[36;1m ------>>  clean\033[0m"

fclean:		clean
			@rm -f $(NAME) a.out
			@echo "\033[36;1m ------>> fclean\033[0m"

re:			fclean all

.PHONY: 	all clean fclean re