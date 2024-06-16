# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jde-orma <jde-orma@42urduliz.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/23 08:02:50 by jde-orma          #+#    #+#              #
#    Updated: 2023/03/23 08:02:50 by jde-orma         ###   ########.fr        #
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
LIBFT_DIR     = libraries/libft/
LIBFT_INC_DIR = libraries/libft/include/
OBJ_DIR       = source/
BIN_DIR       = ./

# Source files
SRC_FILE      = philo_main.c philo_actions.c philo_monitor.c philo_threads.c philo_init.c
SRC           = $(addprefix $(SRC_DIR), $(SRC_FILE))
OBJ_FILE      = $(SRC_FILE:.c=.o)
OBJ           = $(addprefix $(OBJ_DIR), $(OBJ_FILE))

# Code implementation NAME

CODE		  =	philo

# Binary name for your program
CODE_BIN      = $(BIN_DIR)$(CODE)

# Static library
LIBFT         = $(LIBFT_DIR)libft.a

# Output executable
NAME          = $(CODE)

# Create the obj/ and bin/ directories if they don't exist
#$(shell mkdir -p $(OBJ_DIR) $(BIN_DIR))

# Variable to control if the library has been built
LIBFT_BUILT   = no

# $(info $(BLUE) SRC_DIR is $(GREEN) $(SRC_DIR) $(DEF_COLOR))
# $(info $(BLUE) SRC_FILE is $(GREEN) $(SRC_FILE) $(DEF_COLOR))
# $(info $(BLUE) OBJ_DIR is $(GREEN) $(OBJ_DIR) $(DEF_COLOR))
# $(info $(BLUE) OBJ_FILE is $(GREEN) $(OBJ_FILE) $(DEF_COLOR))

all: $(CODE_BIN)

# APUNTES
# $^ Evalua todos archivos puestos tras la regla.
# Ejemplo: 
# 			all: library.cpp main.cpp
#				 $@ evaluates to all
#				 $< evaluates to library.cpp
#				 $^ evaluates to library.cpp main.cpp
# patsubt  ...	$(patsubst pattern,replacement,text)
#				Busca un "patron" y lo substituye por el "remplazo" propuesto en el directorio "text"
# sort     ...	$(sort list)
#				Ordena alfabeticamente la "lista" dada evitando duplicados separandolas por un espacio en blanco
# wildcard ...	$(wildcard pattern…)
#				Se usa para remplazar el texto buscado "proxy/convencional/*.cc" por una lista de todos los archivos 
#				que encajan con el patron separados por espacios en blanco

# -I para indicar directorio de includes
# -L para indicar directorio de librerias
# -lft para que el enlazador busque una biblioteca que siga la convención de nombramiento estándar (lib + nombre), en este caso, libft.
# -o $@ para indicar el nombre de salida del ejecutable. -o indica que el siguiente nombre es el del ejecutable y $@ para que sea lo que se guarda en la variable CODE_BIN

$(CODE_BIN): $(LIBFT) $(OBJ)
	@$(CC) $(CCFLAGS) -o $@ $(OBJ) -I $(INC_DIR) -I $(LIBFT_INC_DIR) -L $(LIBFT_DIR) -lft 
	@echo "$(GREEN)✔ $(BLUE)$(USER_NAME)'s $(CODE_BIN) compilation$(DEF_COLOR)"

$(LIBFT):
	@if [ "$(LIBFT_BUILT)" = "no" ]; then \
		make -C $(LIBFT_DIR); \
		LIBFT_BUILT=yes; \
	fi

# % es un comodín que indica que la regla se aplicará a todo archivo que termine por .o en el directorio $(OBJ_DIR)
# $< hace referencia al primer requisito de la regla, en nuestro caso, $(SRC_DIR)%.c
# $@ hace referencia al nombre del archivo .o creado cada vez. Junto a $< va asignando nombre a cada .o creado
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(CCFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)
	@echo "$(GREEN)✔ $(BLUE)$(USER_NAME)'s $(CODE_BIN) .o files removal$(DEF_COLOR)"
	@make -C $(LIBFT_DIR) fclean

fclean: clean
	@$(RM) $(CODE_BIN)
	@echo "$(GREEN)✔ $(BLUE)$(USER_NAME)'s $(CODE_BIN) executable and .o files removal$(DEF_COLOR)"
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re