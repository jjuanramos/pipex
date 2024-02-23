# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/15 16:43:25 by juramos           #+#    #+#              #
#    Updated: 2023/12/07 10:55:12 by juramos          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables

NAME 		= 	libftprintf.a
INCLUDE 	= 	include
CC 			= 	gcc
CFLAGS 		= 	-Wall -Werror -Wextra -I
SRC_DIR 	= 	src/
OBJ_DIR 	= 	obj/
LIBFT_DIR 	= 	libft
MAKEFLAGS 	+=	 --no-print-directory
.SILENT:

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

# Sources

SRC_FILES 	= 	ft_printf ft_write_s ft_write_d ft_write_c \
				ft_write_ptr ft_write_u ft_write_x \
				ft_printf_utils

SRC 		=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
OBJF 		=	.cache_exists

###

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT_DIR)
	@cp libft/libft.a .
	@mv libft.a $(NAME)
	ar rcs $(NAME) $(OBJ)
	@echo "$(GREEN)ft_printf compiled!$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJF):
	@mkdir -p $(OBJ_DIR)

libft:
	@make -C $(LIBFT_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR)
	@echo "$(BLUE)ft_printf object files cleaned!$(DEF_COLOR)"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@echo "$(CYAN)ft_printf executable files cleaned!$(DEF_COLOR)"
	@echo "$(CYAN)libft executable files cleaned!$(DEF_COLOR)"

re: fclean all
	@echo "$(GREEN)Cleaned and rebuilt everything for ft_printf!$(DEF_COLOR)"

so: $(OBJ)
	$(CC) -nostartfiles -fPIC $(CFLAGS) -I$(LIBFT_DIR) -c $(SRC)
	$(CC) -nostartfiles -shared -o libftprintf.so $(OBJ) $(LINK_FLAGS)

norm:
	@norminette $(SRC) $(LIBFT_DIR) | grep -v Norme -B1 || true

.PHONY: all clean fclean re so libft norm