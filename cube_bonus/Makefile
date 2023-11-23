# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sfernand <sfernand@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/09 19:15:17 by sfernand          #+#    #+#              #
#    Updated: 2023/11/23 17:24:07 by sfernand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cube_bonus

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

FILES = cube_bonus \
		parce_path_bonus \
		init_data_bonus \
		init_file_bonus \
		verif_file_bonus \
		ft_game_bonus \
		moves_bonus \
		textures_bonus \
		hooks_bonus \
		utils_bonus \
		calculations_bonus \
		set_pixel_color_bonus \
		put_pixel_bonus \
		parcing_utils_bonus \
		check_map_bonus \
		parce_file_bonus

GNL_FILE = get_next_line \
			get_next_line_utils

PRINTF_PATH = ./ft_printf/
PRINTF_FILE = libftprintf.a

LIBFT_PATH = ./libft/
LIBFT_FILE = libft.a

MLX_PATH = ./mlx/
MLX_FILE = libmlx.a

FTPRINTF_PRINTF = $(addprefix $(PRINTF_PATH), $(PRINTF_FILE))

LIBFT_LIB = $(addprefix $(LIBFT_PATH), $(LIBFT_FILE))

MLX_MLX = $(addprefix $(MLX_PATH), $(MLX_FILE))

GNL_DIR = ./get_next_line/
GNL = $(addprefix $(GNL_DIR), $(addsuffix .c, $(GNL_FILE)))

OBJS_GNL_DIR = ./get_next_line/
OBJS_GNL = $(addprefix $(OBJS_GNL_DIR), $(addsuffix .o, $(GNL_FILE)))

SRCS_DIR = ./src/
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = ./src/
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

.c.o: $(SRCS), $(GNL)
	$(CC) $(CFLAGS) -D BUFFER_SIZE=1 -c -o $@ $<

$(NAME): $(OBJS) $(OBJS_GNL)
	make -sC $(LIBFT_PATH)
	make -sC $(PRINTF_PATH)
	make -sC $(MLX_PATH)
	gcc $(CFLAGS) $(OBJS) $(OBJS_GNL) $(LIBFT_LIB) $(FTPRINTF_PRINTF) $(MLX_MLX) -Lmlx -lmlx -framework OpenGL -framework Appkit -o $(NAME)

all: $(NAME)

ft_printf:
	make -sC $(PRINTF_PATH)

lib:
	@make -sC $(LIBFT_PATH)

norminette:
	@norminette ./src/

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS_GNL)
	@make clean -sC $(LIBFT_PATH)
	@make clean -sC $(PRINTF_PATH)
	@make clean -sC $(MLX_PATH)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(OBJS)
	$(RM) $(OBJS_GNL)
	make fclean -sC $(LIBFT_PATH)
	make fclean -sC $(PRINTF_PATH)
	make clean -sC $(MLX_PATH)

re: clean all
