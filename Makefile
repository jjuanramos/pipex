# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/15 16:43:25 by juramos           #+#    #+#              #
#    Updated: 2024/04/03 13:52:40 by juramos          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name
NAME 		= 	pipex
B_NAME		=	pipex_bonus

# Compiler
CC 			= 	gcc
CFLAGS 		= 	-Wall -Werror -Wextra

# Sources
SRC_DIR 	= 	src/
SRC_FILES 	= 	main utils
SRC 		=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))

# Objects
OBJ_DIR 	= 	obj/
OBJ 		=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

# Bonus SRC
B_DIR 		= 	bonus/
B_FILES 	= 	main utils
BONUS_SRC 	=	$(addprefix $(B_DIR), $(addsuffix .c, $(B_FILES)))

# Bonus OBJ
B_OBJ_DIR 	= 	bonus_obj/
B_OBJ 		=	$(addprefix $(B_OBJ_DIR), $(addsuffix .o, $(B_FILES)))

# ft_printf
FT_PRINTF_PATH	= 	ft_printf/
FT_PRINTF_NAME	= 	libftprintf.a
FT_PRINTF		= 	$(FT_PRINTF_PATH)$(FT_PRINTF_NAME)

# Includes
INC			=	-I ./ft_printf

# Colors
DEF_COLOR 	= 	\033[0;39m
GRAY 		= 	\033[0;90m
RED 		= 	\033[0;91m
GREEN 		=	\033[0;92m
YELLOW 		=	\033[0;93m
BLUE 		=	\033[0;94m
MAGENTA 	=	\033[0;95m
CYAN 		= 	\033[0;96m
WHITE 		= 	\033[0;97m

# Config
OBJF 		=	.cache_exists
MAKEFLAGS 	+=	--no-print-directory
.SILENT:

###

all: $(FT_PRINTF) $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(OBJF):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(FT_PRINTF) $(INC)
	@echo "$(GREEN)pipex compiled!$(DEF_COLOR)"

bonus: $(FT_PRINTF) $(B_NAME)

$(B_OBJ_DIR)%.o: $(B_DIR)%.c
	@mkdir -p $(B_OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(B_NAME): $(B_OBJ)
	@$(CC) $(CFLAGS) -o $(B_NAME) $(B_OBJ) $(FT_PRINTF) $(INC)
	@echo "$(GREEN)pipex bonus compiled!$(DEF_COLOR)"

$(FT_PRINTF):
	@echo "Making ft_printf..."
	@make -sC $(FT_PRINTF_PATH)

ft_printf:
	@make -sC $(FT_PRINTF_PATH)

clean:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(B_OBJ_DIR)
	@make clean -sC $(FT_PRINTF_PATH)
	@echo "$(BLUE)pipex object files cleaned!$(DEF_COLOR)"

fclean: clean
	@rm -f $(NAME)
	@rm -f $(B_NAME)
	@make fclean -sC $(FT_PRINTF_PATH)
	@echo "$(CYAN)pipex executable files cleaned!$(DEF_COLOR)"

re: fclean all
	@echo "$(GREEN)Cleaned and rebuilt everything for pipex!$(DEF_COLOR)"

norm:
	@norminette $(SRC) | grep -v Norme -B1 || true

.PHONY: all clean fclean re norm ft_printf