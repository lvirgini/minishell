# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/31 17:38:13 by lvirgini          #+#    #+#              #
#    Updated: 2021/10/28 13:22:56 by lvirgini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ----------------- #
#	 VARIABLES		#
# ----------------- #

NAME =		minishell

OBJ_DIR =	obj/
LIB_DIR =	libft/ 
INC_DIR =	includes/	libft/includes/

SRC_DIR_TEST = srcs/testing 

# CI DESSOUS METTRE TOUS LES DOSSIER CONTENANT DES SOURCES !!!!!!!
#SRC_DIR =	$(SRC_DIR_TEST) \
			srcs			\
			srcs/env		\
			srcs/prompt		\
			srcs/terminal	\
			srcs/lexer		\
			srcs/lexer/ft_get_token_by_type \
			srcs/lexer/init_token \
			srcs/error \
			srcs/structures/t_cmd \
			srcs/structures/t_redir \
			srcs/structures/t_token \
			srcs/parser \
			srcs/parser/parse_redirections \
#			


SRC_DIR =	$(shell find srcs -type d)
#INC_DIR = 	$(shell find includes -type d) libft/includes 

LIB		=	ft ncurses readline

SRC 	=	$(foreach dir, $(SRC_DIR), $(foreach file, $(wildcard $(dir)/*.c), $(notdir $(file))))
OBJ 	=	$(addprefix $(OBJ_DIR),$(SRC:%.c=%.o))


#SRC_TEST 		= $(SRC) main_test.c
#SRC_MINISHELL	= $(SRC) minishell.c


#OBJ_TEST 		=	$(addprefix $(OBJ_DIR),$(SRC_TEST:%.c=%.o))
#OBJ_MINISHELL	=	$(addprefix $(OBJ_DIR),$(SRC_MINISHELL:%.c=%.o))


HEADERS = 	$(foreach dir, $(INC_DIR), $(wildcard $(dir)/*.h))


vpath %.c $(foreach dir, $(SRC_DIR)/, $(dir):)
vpath %.h $(foreach dir, $(INC_DIR)/, $(dir):)


# ----------------- #
#	 COMPILATION	#
# ----------------- #

CC 		=	gcc

CFLAG 	= 	-Wall -Wextra -g
# add -Werror
IFLAG 	= 	$(foreach dir, $(INC_DIR), -I $(dir) )
LFLAG 	=	$(foreach lib, $(LIB), -l $(lib) ) $(foreach dir, $(LIB_DIR), -L $(dir) ) 


# ----------------- #
#	  FONCTIONS		#
# ----------------- #



$(OBJ_DIR)%.o: %.c $(HEADERS)
			@mkdir -p $(OBJ_DIR)
			@echo "\033[32mCompilation de ... $(foreach file, $< , $(notdir $<))"
			$(CC) $(CFLAG) $(IFLAG) -o $@ -c $< 

$(NAME):	install $(OBJ)
			$(CC) $(CFLAG) $(IFLAG) $(OBJ) $(LFLAG) -o $@
			@echo "\n*     Compilation $(NAME)     *\t   \033[32;1m--> \033[4;5mComplete\033[0m"

all:		$(NAME)

#$(NAME): 	install $(OBJ)
#			@$(CC) $(CFLAG) $(IFLAG) $(OBJ) $(LFLAG)-o $@
#			@echo "\n*     Compilation $(NAME)     *\t   \033[32;1m--> \033[4;5mComplete\033[0m"

test:		install $(OBJ_TEST)		
			@$(CC) $(CFLAG) $(IFLAG) $(OBJ_TEST) $(LFLAG) -o $@
			@echo "\n*     Compilation test     *\t   \033[32;1m--> \033[4;5mComplete\033[0m"


install :
			@make -C libft/

re-install :
			@make -C libft/ re
				
bonus : 	all

show :
			@echo "SRC_DIR : $(SRC_DIR)\n"
			@echo "LIB_DIR : $(LIB_DIR)\n"
			@echo "INC_DIR : $(INC_DIR)\n"
			@echo "CFLAG : $(CFLAG)\n"
			@echo "IFLAG : $(IFLAG)\n"
			@echo "LFLAG : $(LFLAG)\n"
			@echo "HEADERS : $(foreach file, $(HEADERS),\n\t$(file))\n"
			@echo "SRC :$(foreach file, $(SRC_MINISHELL),\n\t$(file))\n"
			@echo "OBJ :$(foreach file, $(OBJ_MINISHELL),\n\t$(file))\n"


# ----------------- #
# 		CLEAN		#
# ----------------- #

clean:
			rm -rf $(OBJ_DIR)

fclean: clean
			rm -f $(NAME) test

re: 	fclean all

.PHONY: all clean flcean re
