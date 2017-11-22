# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maduhoux <maduhoux@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/22 15:54:41 by maduhoux          #+#    #+#              #
#    Updated: 2017/11/22 16:17:39 by maduhoux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS	=	-Wall -Wextra -Werror
NAME	=	fillit
OBJDIR	=	obj/
SRCDIR	=	srcs/
FILES	=	file_checker.c \
			handle_file.c \
			resolve.c
INCLUDE	=	includes/
SRC		=	$(FILES:%.c=$(SRCDIR)%.c)
OBJ		=	$(FILES:%.c=$(OBJDIR)%.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	gcc -o $(NAME) $(OBJ) -Llibft -lft

maintest: $(OBJ)
	make -C libft/
	gcc -o $(NAME) $(OBJ) main/main_test_error.c -I $(INCLUDE) -Llibft -lft

$(OBJDIR)%.o: $(SRCDIR)%.c
	@mkdir -p $(OBJDIR)
	gcc -o $@ -c $< $(CFLAGS) -I $(INCLUDE)

clean:
	rm -rf $(OBJDIR)
	make clean -C libft/

fclean: clean
	rm -rf $(NAME)
	make fclean -C libft/

re: fclean all
