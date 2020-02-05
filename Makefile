# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npetrell <npetrell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/28 21:46:02 by npetrell          #+#    #+#              #
#    Updated: 2020/01/31 19:32:46 by npetrell         ###   ########.fr        #
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

HEADERS = libft/

OBJDIR = objects/

vpath %.c srcs/
vpath %.h includes/

all: $(NAME)

OBJS = $(SRCS:%.c=%.o)

#Compile
$(NAME):	$(OBJS)
			mkdir $(OBJDIR)
			make -C $(LIBFT)
			$(GCC) -o $(NAME) $(OBJS) $(LFLAG) $(MLFLAG) -lmlx $@


#Link
$(OBJDIR)%.o: %.c
	$(GCC) -I $(HEADERS) -o $@ -c $<

#Clean only Objects
clean:
	rm -rf $(OBJDIR)
	make -C $(LIBFT) clean

#Clean objects and execution files
fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re