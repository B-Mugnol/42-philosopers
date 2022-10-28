# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/10 21:48:28 by bmugnol-          #+#    #+#              #
#    Updated: 2022/10/20 17:14:44 by bmugnol-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# GENERAL OPTIONS
# C Compiler
CC		:=	clang
# Compiler flags
CFLAGS	:=	-Wall -Wextra -Werror
# Removal tool
RM		:=	rm -rf


# PROGRAM
# Program name
NAME		:=	philo

# Header that includes all headers
H_MASTER	:=	master.h
# Headers
HEADER_DIR	:=	inc
HEADER		:=	philosophers.h
H_INCLUDE	:=	$(addprefix -I, $(HEADER_DIR))

# Source
SRC_DIR		:=	src
SRC			:=	main.c	error.c	verify.c	setup.c

# Object
OBJ_DIR		:=	obj
OBJ			:=	$(SRC:%.c=$(OBJ_DIR)/%.o)

# Precompiled header
C_HEADER	:=	$(H_MASTER:%.h=$(OBJ_DIR)/%.h.gch)
C_INCLUDE	:=	$(addprefix -include-pch , $(C_HEADER))


# LIBFT
LIBFT_DIR	:=	../../../fase_1/libft
LIBFT_H_INC	:=	-I$(LIBFT_DIR)/inc
LIBFT		:=	$(LIBFT_DIR)/libft.a

# Inclusions:
INCLUDE		:=	$(C_INCLUDE) $(H_INCLUDE) $(LIBFT_H_INC)

# vpath
vpath	%.h		$(HEADER_DIR)
vpath	%.c		$(SRC_DIR)

# -----------------------RULES------------------------------------------------ #
.PHONY: all vg norm clean fclean re

# Creates NAME
all: $(NAME)

# Compiles OBJ and LIBFT into the program NAME
$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LIBFT) $(INCLUDE)

# Compiles SRC into OBJ
$(OBJ): $(OBJ_DIR)/%.o: %.c $(C_HEADER) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDE)

# Header precompiling
$(C_HEADER): $(OBJ_DIR)/%.h.gch: %.h $(HEADER) | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -o $@ $< $(LIBFT_H_INC) $(H_INCLUDE)

# Directory making
$(OBJ_DIR):
	@mkdir -p $@

# Libft compiling
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Run program using valgrind
ifeq (vg,$(firstword $(MAKECMDGOALS)))
VG_ARGS := $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))
$(eval $(VG_ARGS):;@:)
endif
vg: all
	valgrind -q --tool=helgrind ./$(NAME) $(VG_ARGS)

# Norm: checks code for norm errors
norm:
	@norminette | grep "Error" | cat
	@$(MAKE) -C $(LIBFT_DIR) norm

# Clean: removes objects' directory
clean:
	@$(RM) $(OBJ_DIR) $(C_HEADER_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean

# Full clean: removes objects' directory and generated libs/programs
fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

# Remake: full cleans and runs 'all' rule
re: fclean all
