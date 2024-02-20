NAME=pipex
#CDEBUG = -g3 -fsanitize=address
CDEBUG = -g3
CFLAGS=-Wall -Wextra -Werror ${CDEBUG}

SRC_DIR=./src
OBJ_DIR=./obj
INC_DIR=./inc

LIBFT_DIR=./libft
LIBFT_INC_DIR=${LIBFT_DIR}/inc
LIBFT_LIB=${LIBFT_DIR}/libft.a

SRC_FILES=	pipex.c	\
			ft_command.c	\
			ft_pipe.c		\
			ft_error.c		

OBJ_FILES=$(SRC_FILES:%.c=$(OBJ_DIR)/%.o)
DEP_FILES=$(SRC_FILES:%.c=$(OBJ_DIR)/%.d)

all: $(NAME)

$(NAME): $(OBJ_DIR) $(MLX_LIB) ${LIBFT_LIB} $(OBJ_FILES) 
#	cc $(OBJ_FILES) -Lmlx_Linux -lmlx_Linux -L/usr/lib -Imlx_Linux -lXext -lX11 -lm -lz -o $(NAME)
	cc ${OBJ_FILES} -o ${NAME} ${LIBFT_LIB}


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c Makefile
		cc $(CFLAGS) -I${INC_DIR} -I${LIBFT_INC_DIR} -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

${LIBFT_LIB}:
	make -C ${LIBFT_DIR}

clean:
	rm -f $(OBJ_DIR)/*.o
	rm -f $(OBJ_DIR)/*.d
#	make clean -C ${LIBFT_DIR}

fclean: clean
	rm -f $(NAME)
#	make fclean  -C ${MLX_DIR}
#	make fclean  -C ${LIBFT_DIR}

re: fclean all

-include $(DEP_FILES)

.PHONY: all clean fclean re