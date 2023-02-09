# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/01 15:35:58 by nomoulin          #+#    #+#              #
#    Updated: 2023/02/06 18:09:13 by nomoulin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFILES = render fractol complex mendelbrot julia main configuration \
			lines_rendering rendering routines sugar transforms events \
			colorevents event
SRCS = $(addsuffix .c, $(CFILES))
OBJS_FILES = $(addsuffix .o, $(CFILES))

CODE_DIR = code
SRCS_DIR = $(CODE_DIR)/srcs
OBJS_DIR = $(CODE_DIR)/objs

SRCS_PATHS = $(addprefix $(SRCS_DIR)/, $(SRCS))
OBJS = $(addprefix $(OBJS_DIR)/, $(OBJS_FILES))

MLX_PATH = $(CODE_DIR)/minilibx-linux
LIBFT_PATH = $(CODE_DIR)/libft

CC = clang
CFLAGS = -Wall -Wextra -Werror

MLINKS = -I $(MLX_PATH) -L $(MLX_PATH) -lmlx -lXext -lX11 -lm
LINKSFT = -I $(LIBFT_PATH) -L $(LIBFT_PATH) -lft

MLX = $(MLX_PATH)/libmlx.a
LIBFT = $(LIBFT_PATH)/libft.a
NAME = fract-ol

all : $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS_DIR) $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) $(LINKSFT) $(MLINKS) -o $(NAME)

$(OBJS):
	@make $(OBJS_FILES)

%.o : $(SRCS_DIR)/%.c
	$(CC) -c $< $(CFLAGS) -o $(OBJS_DIR)/$@

$(OBJS_DIR):
	@mkdir $(OBJS_DIR)

$(LIBFT):
	@make -C $(LIBFT_PATH)

$(MLX):
	@make -C $(MLX_PATH)

clean : 
	@rm -rf $(OBJS_DIR)
	@make clean -C $(LIBFT_PATH)
	@make clean -C $(MLX_PATH)

fclean : clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH)
	@make fclean -C $(MLX_PATH)

re : fclean all

norminette :
	@norminette code/srcs
	@norminette code/libft
	@norminette code/*.h

.PHONY : all clean fclean re norminette
