NAME=pipex
#CDEBUG = -g3 -fsanitize=address
CDEBUG = -g3
CFLAGS=-Wall -Wextra -Werror -MMD -MP ${CDEBUG}

SRC_DIR=./src
OBJ_DIR=./obj
INC_DIR=./inc

BONUS_SRC_DIR=./bonus_src
BONUS_INC_DIR=./bonus_inc

LIBFT_DIR=./libft
LIBFT_INC_DIR=${LIBFT_DIR}/inc
LIBFT_LIB=${LIBFT_DIR}/libft.a

SRC_FILES=	pipex.c				\
			ft_child.c			\
			ft_environment.c	\
			ft_error.c			\
			ft_exec.c			\
			ft_fd.c				\
			ft_files.c			\
			ft_parent.c			\
			ft_ptr.c			\
			ft_utils.c

BONUS_SRC_FILES=	pipex_bonus.c				\
					ft_child_bonus.c			\
					ft_environment_bonus.c		\
					ft_error_bonus.c			\
					ft_exec_bonus.c				\
					ft_fd_bonus.c				\
					ft_files_bonus.c			\
					ft_parent_bonus.c			\
					ft_ptr_bonus.c				\
					ft_utils_bonus.c

OBJ_FILES=$(SRC_FILES:%.c=$(OBJ_DIR)/%.o)
DEP_FILES=$(SRC_FILES:%.c=$(OBJ_DIR)/%.d)

OBJ_BONUS_FILES=$(BONUS_SRC_FILES:%.c=$(OBJ_DIR)/%.o)
DEP_BONUS_FILES=$(BONUS_SRC_FILES:%.c=$(OBJ_DIR)/%.d)

all: $(NAME)

bonus: $(OBJ_DIR) ${LIBFT_LIB} ${OBJ_BONUS_FILES}
	cc ${OBJ_BONUS_FILES} -o ${NAME} ${LIBFT_LIB}
	@touch bonus

$(NAME): $(OBJ_DIR) ${LIBFT_LIB} $(OBJ_FILES) 
	cc ${OBJ_FILES} -o ${NAME} ${LIBFT_LIB}

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c Makefile
	cc $(CFLAGS) -I${INC_DIR} -I${LIBFT_INC_DIR} -c $< -o $@

$(OBJ_DIR)/%.o: $(BONUS_SRC_DIR)/%.c Makefile
	cc $(CFLAGS) -I${BONUS_INC_DIR} -I${LIBFT_INC_DIR} -c $< -o $@

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
-include $(DEP_BONUS_FILES)

.PHONY: all clean fclean re