CC = gcc -g
AR = ar -rcs
FLAGS = -g -fsanitize=address
NAME = so_long.a
PROGRAM_NAME = so_long
SRC = srcs/so_long.c \
	srcs/ft_strjjoin.c \
	srcs/ft_error.c \
	srcs/check_map_error.c \
	srcs/parse_map.c \
	srcs/build_map.c \
	srcs/print_texture.c \
	srcs/ft_move.c
	

OBJ = $(SRC:.c=.o)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@ 

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@$(AR) $(NAME) $(OBJ) 
	@$(CC) $(FLAGS) -lmlx -framework OpenGL -framework AppKit $(NAME) libft/libft.a -o $(PROGRAM_NAME) $?

clean:
	@make -C libft/ clean
	rm -f $(OBJ)

fclean: clean
	@make -C libft/ fclean
	rm -f $(NAME) $(PROGRAM_NAME)
	
re: fclean all