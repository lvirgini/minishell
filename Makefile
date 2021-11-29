# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/31 17:38:13 by lvirgini          #+#    #+#              #
#    Updated: 2021/11/29 14:29:12 by lvirgini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ----------------- #
#	 VARIABLES		#
# ----------------- #

NAME =		minishell

OBJ_DIR =	obj/
LIB_DIR =	libft/ 
INC_DIR =	includes/	libft/includes/
SRC_DIR =	$(shell find srcs -type d)

LIB		=	ft ncurses readline

SRC		= 	cd.c \
			cd_home.c \
			echo.c \
			env.c \
			exec_builtin.c \
			exit.c \
			export.c \
			export_init_values.c \
			getdir_builtin.c \
			is_builtin.c \
			pwd.c \
			unset.c \
			add_env.c \
			get_env_utils.c \
			recover_complete_env.c \
			cmd_error.c \
			syntax_error.c \
			executer.c \
			execve_and_fork.c \
			setup_cmd_path_with_envpath.c \
			setup_cmd_path.c \
			signals.c \
			expand_argv.c \
			expand_heredoc.c \
			expand_redirection.c \
			expand_utils.c \
			expanser.c \
			dollar_is_dollar.c \
			expand_dollar.c \
			expand_dollar_usefull.c \
			expand_double_quotes.c \
			expand_simple_quotes.c \
			expand_str.c \
			fusion_list_argv.c \
			fusion_str_and_expansion.c \
			add_token.c \
			char_is_something.c \
			lexer.c \
			get_next_cmd.c \
			is_token_something.c \
			parse_argv.c \
			parse_control_operator.c \
			parser_general.c \
			close.c \
			heredoc_setup.c \
			heredoc_maker.c \
			pipe.c \
			redirection.c \
			setup_redirection.c \
			get_line.c \
			str.c \
			get_token_pipe.c \
			get_token_tild.c \
			get_token_word.c \
			parse_all_redir.c \
			free_t_cmd.c \
			malloc_t_cmd.c \
			t_expansion_add_back.c \
			t_expansion_free.c \
			t_expansion_malloc.c \
			t_hdoc_create.c \
			t_hdoc_free.c \
			t_hdoc_malloc.c \
			add_t_redir.c \
			free_t_redir.c \
			t_struct_add_back.c \
			t_struct_add_front.c \
			t_struct_len.c \
			t_token_free.c \
			t_token_malloc.c \
			t_token_remove.c \
			init_prompt.c\
			update_prompt.c \
			minishell.c

OBJ 	=	$(addprefix $(OBJ_DIR),$(SRC:%.c=%.o))
HEADERS = 	$(foreach dir, $(INC_DIR), $(wildcard $(dir)/*.h))

vpath %.c $(foreach dir, $(SRC_DIR)/, $(dir):)
vpath %.h $(foreach dir, $(INC_DIR)/, $(dir):)

# ----------------- #
#	 COMPILATION	#
# ----------------- #

CC 		=	gcc

CFLAG 	= 	-Wall -Wextra -Werror -g
IFLAG 	= 	$(foreach dir, $(INC_DIR), -I $(dir) )
LFLAG 	=	$(foreach lib, $(LIB), -l $(lib) ) $(foreach dir, $(LIB_DIR), -L $(dir) ) 

# ----------------- #
#	  FONCTIONS		#
# ----------------- #

$(OBJ_DIR)%.o: %.c $(HEADERS)
			@mkdir -p $(OBJ_DIR)
			@echo "\033[32mCompilation de ... $(foreach file, $< , $(notdir $<))"
			@$(CC) $(CFLAG) $(IFLAG) -o $@ -c $< 

$(NAME):	install $(OBJ)
			@$(CC) $(CFLAG) $(IFLAG) $(OBJ) $(LFLAG) -o $@
			@echo "\n*     Compilation $(NAME)     *\t   \033[32;1m--> \033[4;5mComplete\033[0m"

all:		$(NAME)

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
			rm -f $(NAME)

re: 	fclean all

.PHONY: all clean flcean re
