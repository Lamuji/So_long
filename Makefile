CC = gcc -g
AR = ar -rcs
FLAGS = -g -fsanitize=address
NAME = so_long.a
PROGRAM_NAME = so_long
SRC = so_long.c \
	ft_strjjoin.c \
	ft_error.c \
	check_map_error.c \
	parse_map.c \
	build_map.c \
	print_texture.c \
	ft_move.c
	

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