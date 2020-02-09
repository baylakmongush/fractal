# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npetrell <npetrell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/28 21:46:02 by npetrell          #+#    #+#              #
#    Updated: 2020/02/09 18:13:21 by npetrell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

GCC = gcc -O3 -Wall -Wextra -Werror 

LIBFT = libft

MINILIBX = minilibx

LFLAG = -L $(LIBFT) -lft

MLFLAG = -framework OpenGL -framework Appkit

SRCS = main.c key_mouse_press.c mandelbrot.c julia.c celtic_mandelbar.c \
		celtic_mandelbrot.c mandelbar.c color.c pthread.c init.c \
		perpen_burning_ship.c burning_ship.c perpen_mandelbrot.c \

HEADERS = libft/

vpath %.c srcs/
vpath %.h includes/

all: $(NAME)

OBJS = $(SRCS:%.c=%.o)

#Compile
$(NAME):	$(OBJS)
			@make -C $(LIBFT)
			@$(GCC) -o $(NAME) $(OBJS) $(LFLAG) $(MLFLAG) -lmlx
			#@mkdir objects
			#@mv $(OBJS) objects/
%.o: %.c
	@$(GCC) -I $(HEADERS) -o $@ -c $<

#Clean only Objects
clean:
	@rm -rf $(OBJS)#objects/
	@make -C $(LIBFT) clean

#Clean objects and execution files
fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re