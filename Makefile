NAME      := so_long
CC        := cc
FLAGS     := -Wall -Wextra -Werror -g
SRCS      :=    check_entities.c  input.c \
				map_shape_checks.c path_finder.c \
				map_utils.c error.c \
				window_stuff.c\
                          
OBJS      := $(SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
			@ make -C ./mlx
			@ cp ./mlx/libmlx.a .
			@ cd libft && make all
			$(CC) $(CFLAGS) $(OBJS) main.c -o $(NAME) libft/libft.a libmlx.a  -Imlx -Lmlx -lmlx -lm -framework OpenGL -framework AppKit
			@echo "$(NAME) created[0m ✔️"

all:		${NAME}

clean:
			@ ${RM} *.o */*.o */*/*.o
			@ rm -rf so_long
			@ cd libft && make clean
			@ echo "Deleting $(NAME) $(CLR_RMV)objs ✔️"

fclean:		clean
			@ ${RM} ${NAME}
			@ rm -rf libmlx.a
			@ rm -rf libft.a
			@ cd libft && make fclean
			@ echo "Deleting $(NAME) $(CLR_RMV)binary ✔️"

re:			fclean all

.PHONY:		all clean fclean re