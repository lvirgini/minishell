# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/21 18:13:44 by lvirgini          #+#    #+#              #
#    Updated: 2021/11/03 15:40:11 by lvirgini         ###   ########.fr        #
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

SRCS 	= $(SRCS_ALLOCATION) $(SRCS_CONVERTION) $(SRCS_IS_SOMETHING) $(SRCS_LIST)
SRCS	   += $(SRCS_MEMORY) $(SRCS_FT_PRINT) $(SRCS_STRING) $(SRCS_GNL) $(SRCS_LITTLE_MATHS) 

SRCS_ALLOCATION = ft_calloc.c \

SRCS_CONVERTION = 	ft_atof.c		ft_atoi_base.c	ft_atoi.c		ft_itoa.c  \
					ft_lltoa.c 		ft_ulltoa.c		ft_utoa.c

SRCS_IS_SOMETHING = ft_isalnum.c	ft_isalpha.c	ft_isascii.c	ft_isdigit.c \
					ft_isprint.c	ft_isspace.c	ft_tolower.c	ft_toupper.c

SRCS_LIST = 		list_free.c		list_len.c		list_malloc.c	list_duplicate.c \
					list_move.c		list_print.c	list_print.c 	

SRCS_MEMORY	=		ft_bzero.c		ft_memccpy.c	ft_memchr.c		ft_memcmp.c \
					ft_memmove.c	ft_memset.c 

SRCS_FT_PRINT = 	ft_putchar_fd.c	ft_putchar.c	ft_putendl.c	ft_putnbr_base_fd.c \
					ft_putendl_fd.c	ft_putnbr_fd.c	ft_putnbr.c		ft_putstr_fd.c \
					ft_putstr.c

SRCS_STRING	=		ft_split.c		ft_split_set.c	ft_strchr_len.c	ft_strchr_set.c	\
					ft_strchr.c		ft_strcmp.c		ft_strcut.c		ft_strdup.c		\
					ft_strjoin.c	ft_strlcat.c	\
					ft_strlcpy.c	ft_strlen.c		ft_strmapi.c	ft_strncmp.c	\
					ft_strncpy.c	ft_strnstr.c	ft_substr.c
				
SRCS_GNL = 			get_next_line.c 

SRCS_LITTLE_MATHS = ft_abs.c 

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
			@$(CC) -g -Wall -Wextra $(IFLAG) $(OBJ) test/list_test.c

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