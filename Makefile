# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/13 17:13:57 by bramalho@st       #+#    #+#              #
#    Updated: 2026/01/21 17:16:46 by bramalho@st      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                   COLORS                                     #
# **************************************************************************** #

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

# **************************************************************************** #
#                                   NAMES                                      #
# **************************************************************************** #

NAME = push_swap

# **************************************************************************** #
#                                 COMPILER                                     #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

# **************************************************************************** #
#                                DIRECTORIES                                   #
# **************************************************************************** #

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = includes

LIBFT_DIR = libft
PRINTF_DIR = ft_printf  # Optional - if you want to use it

# **************************************************************************** #
#                                  FILES                                       #
# **************************************************************************** #

SRCS = 	$(SRC_DIR)/main.c \
		$(SRC_DIR)/init.c \
		$(SRC_DIR)/parsing.c \
		$(SRC_DIR)/stack_utils.c \
		$(SRC_DIR)/operations/push.c \
		$(SRC_DIR)/operations/swap.c \
		$(SRC_DIR)/operations/rotate.c \
		$(SRC_DIR)/operations/reverse_rotate.c \
		$(SRC_DIR)/algorithm/sort_three.c \
		$(SRC_DIR)/algorithm/sort_small.c \
		$(SRC_DIR)/algorithm/sort_large.c \
		$(SRC_DIR)/utils/error.c \
		$(SRC_DIR)/utils/free.c

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# **************************************************************************** #
#                                 LIBRARIES                                    #
# **************************************************************************** #

LIBFT = $(LIBFT_DIR)/libft.a
# PRINTF = $(PRINTF_DIR)/libftprintf.a  # Uncomment if using ft_printf

# **************************************************************************** #
#                                  FLAGS                                       #
# **************************************************************************** #

INCLUDES = -I$(INC_DIR) -I$(LIBFT_DIR)
# INCLUDES += -I$(PRINTF_DIR)  # Uncomment if using ft_printf

LIBS = -L$(LIBFT_DIR) -lft
# LIBS += -L$(PRINTF_DIR) -lftprintf  # Uncomment if using ft_printf

# **************************************************************************** #
#                                  RULES                                       #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)
	@echo "$(GREEN)✅ push_swap compiled successfully!$(RESET)"

$(LIBFT):
	@make -C $(LIBFT_DIR)

# $(PRINTF):
# 	@make -C $(PRINTF_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(GREEN)Compiled: $<$(RESET)"

clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean
	@echo "$(RED)🗑️  Object files removed$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo "$(RED)🗑️  Executable removed$(RESET)"

re: fclean all

.PHONY: all clean fclean re
