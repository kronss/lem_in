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
		construct.o \
		read_n_ants.o \
		is_it_room.o \
		node_push_back.o \
		linked_list_len.o \
		make_matrix.o \
		read_rooms.o


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
	./$(NAME)

bug:
	gcc -g $(F) -o $(NAME) main.c error_lem_in.c read_data.c $(INCL)

debug: bug
	lldb -- $(NAME)

%.o: ./%.c
	$(GCC) $(F) -o $@ -c $< -I ./
