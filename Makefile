# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/14 12:30:55 by mdegache          #+#    #+#              #
#    Updated: 2025/01/22 10:17:46 by mdegache         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED=\033[31m
GREEN=\033[32m
PURPLE=\033[35m
RESET=\033[0m

NAME = pipex

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

PRINTF_FILES = lib/ft_printf/ft_printf.c\
				lib/ft_printf/params.c\
				lib/ft_printf/params2.c\
				lib/ft_printf/side_func.c\
				lib/ft_printf/side_pointer.c
				
GNL_FILES = lib/GNL/get_next_line.c\
        	lib/GNL/get_next_line_utils.c
			
LIBFT_FILES = lib/libft/ft_putstr_fd.c\
				lib/libft/ft_putchar_fd.c

SRC = main.c\
		init.c\
		exec.c\
		parse_arg.c

OBJ = $(SRC:.c=.o)
OBJ_LIB = $(GNL_FILES:.c=.o) $(PRINTF_FILES:.c=.o) $(LIBFT_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_LIB)
		@$(CC) $(SRC) $(LIBFT_FILES) $(GNL_FILES) $(PRINTF_FILES) $(CFLAGS) -o $(NAME)
		@echo "$(RED)SUCCESS$(RESET)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ) $(OBJ_LIB)
	@echo "$(PURPLE)CLEAN$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(GREEN)FCLEAN$(RESET)"

re: fclean all

.PHONY: all clean fclean re