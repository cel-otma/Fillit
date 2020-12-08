# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-imra <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/28 16:28:59 by ael-imra          #+#    #+#              #
#    Updated: 2019/07/28 16:30:50 by ael-imra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SOURCE = Fillit_C/fillit.c Fillit_C/main.c \
		Fillit_C/verrifier_file.c Fillit_C/decalage_resulta.c \
		Fillit_C/charge_map.c Fillit_C/get_resulta.c

OBJS = $(SOURCE:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)
	@make -C libft
	@$(CC) $(CFLAGS) $(OBJS) libft/libft.a -o $(NAME)

clean :
	@make -C libft clean
	@rm -rf $(OBJS)

fclean : clean
	@make -C libft fclean
	@rm -rf $(NAME)

re : fclean all

