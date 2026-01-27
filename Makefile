# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/13 17:13:57 by bramalho@st       #+#    #+#              #
#    Updated: 2026/01/27 04:07:05 by bramalho@st      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

# **************************************************************************** #
#                                   NAMES                                      #
# **************************************************************************** #

NAME = push_swap
CHECKER = checker

# **************************************************************************** #
#                                 COMPILER                                     #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

# **************************************************************************** #
#                                DIRECTORIES                                   #
# **************************************************************************** #

SRC_DIR = src
BONUS_DIR = src_bonus
OBJ_DIR = obj
OBJ_BONUS_DIR = obj_bonus
INC_DIR = includes

LIBFT_DIR = libft
PRINTF_DIR = ft_printf
GNL_DIR = GNL

# **************************************************************************** #
#                                  FILES                                       #
# **************************************************************************** #

SRCS = 	$(SRC_DIR)/main.c \
		$(SRC_DIR)/init.c \
		$(SRC_DIR)/parsing.c \
		$(SRC_DIR)/validation.c \
		$(SRC_DIR)/stack_utils.c \
		$(SRC_DIR)/operations/push.c \
		$(SRC_DIR)/operations/swap.c \
		$(SRC_DIR)/operations/rotate.c \
		$(SRC_DIR)/operations/reverse_rotate.c \
		$(SRC_DIR)/algorithm/sort_three.c \
		$(SRC_DIR)/algorithm/sort_small.c \
		$(SRC_DIR)/algorithm/indexing.c \
		$(SRC_DIR)/algorithm/position.c \
		$(SRC_DIR)/algorithm/lis_sort.c \
		$(SRC_DIR)/algorithm/lis_helpers.c \
		$(SRC_DIR)/algorithm/lis_helpers2.c \
		$(SRC_DIR)/algorithm/lis_helpers3.c \
		$(SRC_DIR)/algorithm/cost.c \
		$(SRC_DIR)/algorithm/execute.c \
		$(SRC_DIR)/utils/errors.c \
		$(SRC_DIR)/utils/free.c

BONUS_SRCS = $(BONUS_DIR)/checker_bonus.c \
			 $(BONUS_DIR)/operations_bonus.c \
			 $(BONUS_DIR)/push_bonus.c \
			 $(BONUS_DIR)/rotate_bonus.c \
			 $(BONUS_DIR)/reverse_rotate_bonus.c \
			 $(BONUS_DIR)/read_operations_bonus.c \
			 $(BONUS_DIR)/operation_helpers_bonus.c \
			 $(SRC_DIR)/init.c \
			 $(SRC_DIR)/parsing.c \
			 $(SRC_DIR)/validation.c \
			 $(SRC_DIR)/stack_utils.c \
			 $(SRC_DIR)/utils/errors.c \
			 $(SRC_DIR)/utils/free.c

GNL_SRCS = $(GNL_DIR)/get_next_line.c \
		   $(GNL_DIR)/get_next_line_utils.c

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
BONUS_OBJS = $(patsubst $(BONUS_DIR)/%.c,$(OBJ_BONUS_DIR)/%.o,$(filter $(BONUS_DIR)/%.c,$(BONUS_SRCS))) \
			 $(patsubst $(SRC_DIR)/%.c,$(OBJ_BONUS_DIR)/%.o,$(filter $(SRC_DIR)/%.c,$(BONUS_SRCS)))
GNL_OBJS = $(GNL_SRCS:$(GNL_DIR)/%.c=$(OBJ_BONUS_DIR)/%.o)

# **************************************************************************** #
#                                 LIBRARIES                                    #
# **************************************************************************** #

LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

# **************************************************************************** #
#                                  FLAGS                                       #
# **************************************************************************** #

INCLUDES = -I$(INC_DIR) -I$(LIBFT_DIR) -I$(PRINTF_DIR) -I$(GNL_DIR)
LIBS = -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf

# **************************************************************************** #
#                                  RULES                                       #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(LIBFT) $(PRINTF) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)
	@echo "$(GREEN)✅ push_swap compiled successfully!$(RESET)"

bonus: $(CHECKER)

$(CHECKER): $(LIBFT) $(PRINTF) $(BONUS_OBJS) $(GNL_OBJS)
	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(GNL_OBJS) $(LIBS) -o $(CHECKER)
	@echo "$(GREEN)✅ checker compiled successfully!$(RESET)"

$(LIBFT):
	@make -C $(LIBFT_DIR) --no-print-directory

$(PRINTF):
	@make -C $(PRINTF_DIR) --no-print-directory

# Mandatory object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(GREEN)Compiled: $<$(RESET)"

# Bonus object files from bonus directory
$(OBJ_BONUS_DIR)/%.o: $(BONUS_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(GREEN)Compiled: $<$(RESET)"

# Bonus object files from src directory (shared files)
$(OBJ_BONUS_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(GREEN)Compiled: $<$(RESET)"

# GNL object files
$(OBJ_BONUS_DIR)/%.o: $(GNL_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(GREEN)Compiled: $<$(RESET)"

clean:
	@rm -rf $(OBJ_DIR) $(OBJ_BONUS_DIR)
	@make -C $(LIBFT_DIR) clean --no-print-directory
	@make -C $(PRINTF_DIR) clean --no-print-directory
	@echo "$(RED)🗑️  Object files removed$(RESET)"

fclean: clean
	@rm -f $(NAME) $(CHECKER)
	@make -C $(LIBFT_DIR) fclean --no-print-directory
	@make -C $(PRINTF_DIR) fclean --no-print-directory
	@echo "$(RED)🗑️  Executables removed$(RESET)"

re: fclean all

.PHONY: all bonus clean fclean re
