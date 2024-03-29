CC = gcc
CLAGC = -Wall -Wextra -Werror
NAME = cub3D
RM = rm -f
SRCS = check_check.c end.c fill_texture.c get_next_line.c init.c key_press.c main.c make_buffer.c make_player.c map_info.c read_map.c start_raycasting.c start_raycasting_2.c start_sprite.c is_map_invaild.c check_check2.c
OBJS = $(SRCS:.c=.o)
LIBS = -L/Users/hyerkim/intra-uuid-c3bafc6c-ed0f-41fb-9e67-2cc98357c6dc-3376279 -lmlx -framework OpenGL -framework Appkit -Llibft -lft
LIBFT = ./libft
$(NAME) : $(OBJS)
	$(MAKE) bonus -C $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)
all : $(NAME)
clean : 
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT) fclean
fclean : clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT) fclean
re : clean all
.PHONY: all clean fclean re
