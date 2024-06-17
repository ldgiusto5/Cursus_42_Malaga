NAME = so_long
FLAGS = -Wall -Wextra -Wextra -g
MLX42 = ../MLX42/build/libmlx42.a
LIBFT = ../libft/libft.a
PRINTF = ../printf/libftprintf.a
LIBS = -ldl -lglfw3 -pthread -lm $(MLX42)/libmlx42.a
SRCS = *.c
OBJS = *.o
DATE = $(shell /usr/bin/date)

all: $(NAME)

$(NAME): $(LIBFT) $(PRINTF) $(MLX42) $(OBJS)
	@gcc $(FLAGS) $(OBJS) $(MLX42) $(LIBFT) $(PRINTF) -Iinclude -ldl -lglfw -pthread -lm -o $(NAME)

$(OBJS): $(SRCS)
	gcc $(FLAGS) -c $(SRCS)
$(MLX42):
	make -C MLX42
$(LIBFT):
	make -C ../libft
$(PRINTF):
	make -C ../printf

clean:
	@rm -f $(OBJS)
	make -C MLX42 clean
	make -C ../libft clean
	make -C ../printf clean

fclean:
	@rm -f $(OBJS) $(NAME) $(BONUS_OBJS)
	make -C MLX42 fclean
	make -C ../libft fclean
	make -C ../printf fclean

re: fclean all

git:
	git add .
	git commit -m "Auto commit makefile $(DATE)"
	git push

.PHONY: all clean fclean re bonus git