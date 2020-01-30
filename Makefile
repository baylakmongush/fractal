# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npetrell <npetrell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/28 21:46:02 by npetrell          #+#    #+#              #
#    Updated: 2020/01/30 14:33:22 by npetrell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

GCC = gcc -Wall -Wextra -Werror 

LIBFT = libft

MINILIBX = minilibx

LFLAG = -L $(LIBFT) -lft

MLFLAG = -framework OpenGL -framework Appkit

SRCS = ./main.c ./key_mouse_press.c ./mandelbrot.c ./julia.c ./celtic_mandelbar.c \
		./mandelbar.c ./color.c ./pthread.c\

HEADERS = libft/

vpath %.c srcs/
vpath %.h includes/

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME):	$(OBJS)
			make -C $(LIBFT)
			$(GCC) -o $(NAME) $(OBJS) $(LFLAG) $(MLFLAG) -lmlx

%.o: %.c $(HEADER)
	$(GCC) -I $(HEADERS) -c $<

clean:
	rm -rf $(OBJS)
	make -C $(LIBFT) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re