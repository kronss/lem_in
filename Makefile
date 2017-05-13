#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ochayche <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/18 18:15:02 by ochayche          #+#    #+#              #
#    Updated: 2017/03/05 22:47:28 by ochayche         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

GCC = gcc

# F = -Wall -Wextra -Werror

NAME = lem-in

INCL = libft/libft.a ft_printf/libftprintf.a

OBJECT = main.o \
		error_lem_in.o \
		read_data.o \
		__construct.o \
		__destruct.o \
		read_n_ants.o \
		is_it_room.o \
		node_push_back.o \
		linked_list_len.o \
		make_matrix.o \
		read_rooms.o \
		read_connection.o \
		root_push_back.o \
		build_ways.o \
		sort_ways.o \
		choose_roads.o \
		go_ants.o


.PHONY: all clean fclean re bug debug

all: $(NAME)
	@make -C libft/
	@make -C ft_printf/

$(NAME): $(OBJECT)
		@make -C libft/
		@make -C ft_printf/
		$(GCC) $(F) -o $(NAME) $(OBJECT) $(INCL)

clean:
	@make clean -C libft/
	@make clean -C ft_printf/
	rm -rf $(OBJECT)

fclean: clean
	@make fclean -C libft/
	@make fclean -C ft_printf/
	@rm -rf $(NAME) a.out

re: fclean all

r: all
	./$(NAME) < test7

bug:
	gcc -g $(F) -o $(NAME) main.c error_lem_in.c read_data.c __construct.c  __destruct.c read_n_ants.c is_it_room.c node_push_back.c \
	linked_list_len.c make_matrix.c read_rooms.c read_connection.c root_push_back.c build_ways.c sort_ways.c choose_roads.c go_ants.c libft/libft.a ft_printf/libftprintf.a $(INCL)

debug: bug
	lldb -- $(NAME) -f test2

%.o: ./%.c
	$(GCC) $(F) -o $@ -c $< -I ./
