# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmiceli <pmiceli@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 14:44:04 by pmiceli           #+#    #+#              #
#    Updated: 2017/11/27 15:07:06 by pmiceli          ###   ########.fr        #
#    Updated: 2017/11/27 14:56:06 by pmiceli          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS =	ft_parse.c\
	 	ft_solver.c\
		ft_place.c\
		ft_read.c\
		ft_map.c\

OBJ = $(SRCS:.c=.o)

SRC_PATH = srcs/

SRC_POS = $(addprefix $(SRC_PATH),$(SRC))

INC = -I includes

LIBFT = libft/libft.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LIBFT)

%.o : $(SRC_PATH)/%.c
	$(CC) -o $@ -c $< $(FLAGS)

$(LIBFT):
	@make -C ./libft/
	@echo "\033[32mBuilt librairie.\033[0m"

clean :
	@rm -rf $(OBJ)
	@make clean -C ./libft/
	@echo "\033[36mCleaned up object files.\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C ./libft/
	@echo "\033[34mCleaned up compiled files.\033[0m"

re: fclean all

.PHONY : all re clean fclean
