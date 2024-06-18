# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jde-orma <jde-orma@42urduliz.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/23 08:02:50 by jde-orma          #+#    #+#              #
#    Updated: 2023/06/18 16:28:00 by jde-orma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Coder Alias

USER_NAME     = jde-orma

# Compiler and flags

CC            = gcc
CCFLAGS       = -Wall -Wextra -Werror -pthread

#Colors:

DEF_COLOR	=	\033[0;39m
BLUE		=	\033[0;94m
GREEN		=	\033[0;92m

# Directories
SRC_DIR       = source/
INC_DIR       = source/
OBJ_DIR       = source/
BIN_DIR       = ./

# Source files
SRC_FILE      = philo_main.c philo_actions.c philo_monitor.c philo_threads.c philo_init.c philo_utils.c
SRC           = $(addprefix $(SRC_DIR), $(SRC_FILE))
OBJ_FILE      = $(SRC_FILE:.c=.o)
OBJ           = $(addprefix $(OBJ_DIR), $(OBJ_FILE))

# Code implementation NAME

CODE		  =	philo

# Binary name for your program
CODE_BIN      = $(BIN_DIR)$(CODE)

# Output executable
NAME          = $(CODE)

all: $(CODE_BIN)

$(CODE_BIN): $(OBJ)
	@$(CC) $(CCFLAGS) -o $@ $(OBJ) -I $(INC_DIR) 
	@echo "$(GREEN)✔ $(BLUE)$(USER_NAME)'s $(CODE_BIN) compilation$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(CCFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)
	@echo "$(GREEN)✔ $(BLUE)$(USER_NAME)'s $(CODE_BIN) .o files removal$(DEF_COLOR)"

fclean: clean
	@$(RM) $(CODE_BIN)
	@echo "$(GREEN)✔ $(BLUE)$(USER_NAME)'s $(CODE_BIN) executable and .o files removal$(DEF_COLOR)"

re: fclean all

.PHONY: all clean fclean re