# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/10 21:48:28 by bmugnol-          #+#    #+#              #
#    Updated: 2022/11/24 20:44:34 by bmugnol-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# GENERAL OPTIONS
# C Compiler
CC		:=	clang
# Compiler flags
CFLAGS	:=	-Wall -Wextra -Werror -pthread
# Removal tool
RM		:=	rm -rf


# PROGRAM
# Program name
NAME		:=	philo

# Header that includes all headers
H_MASTER	:=	master.h
# Headers
HEADER_DIR	:=	inc
HEADER		:=	defines.h

HEADER_DIR	+=	src/setup
HEADER		+=	setup.h

HEADER_DIR	+=	src/simulation
HEADER		+=	simulation.h

HEADER_DIR	+=	src/simulation/actions
HEADER		+=	actions.h

HEADER_DIR	+=	src/utilities
HEADER		+=	error.h	time.h	utils.h

H_INCLUDE	:=	$(addprefix -I, $(HEADER_DIR))

# Source
SRC_DIR	:=	src
SRC		:=	main.c

SRC_DIR	+=	src/setup
SRC		+=	dismount.c	init.c	setup.c

SRC_DIR	+=	src/simulation
SRC		+=	simulation.c	simulation_utils.c

SRC_DIR	+=	src/simulation/actions
SRC		+=	actions.c	action_utils.c

SRC_DIR	+=	src/utilities
SRC		+=	error.c	time.c	utils.c

# Object
OBJ_DIR		:=	obj
OBJ			:=	$(SRC:%.c=$(OBJ_DIR)/%.o)

# Precompiled header
C_HEADER	:=	$(H_MASTER:%.h=$(OBJ_DIR)/%.h.gch)
C_INCLUDE	:=	$(addprefix -include-pch , $(C_HEADER))

# Inclusions:
INCLUDE		:=	$(C_INCLUDE) $(H_INCLUDE)

# vpath
vpath	%.h		$(HEADER_DIR)
vpath	%.c		$(SRC_DIR)

# -----------------------RULES------------------------------------------------ #
.PHONY: all norm clean fclean re

# Creates NAME
all: $(NAME)

# Compiles OBJ and LIBFT into the program NAME
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(INCLUDE)

# Compiles SRC into OBJ
$(OBJ): $(OBJ_DIR)/%.o: %.c $(C_HEADER) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDE)

# Header precompiling
$(C_HEADER): $(OBJ_DIR)/%.h.gch: %.h $(HEADER) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ $< $(H_INCLUDE)

# Directory making
$(OBJ_DIR):
	@mkdir -p $@

# Norm: checks code for norm errors
norm:
	@norminette | grep "Error" | cat

# Clean: removes objects' directory
clean:
	$(RM) $(OBJ_DIR) $(C_HEADER_DIR)

# Full clean: removes objects' directory and generated libs/programs
fclean: clean
	$(RM) $(NAME)

# Remake: full cleans and runs 'all' rule
re: fclean all
