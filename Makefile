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

NAME = lem_in

INCL = libft/libft.a ft_printf/libftprintf.a

OBJECT = main.o error_lem_in.o

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
	gcc -g $(F) -o $(NAME_1) list_push_back.c ps_error.c print_stacks.c make_ss.c make_rr.c make_rrr.c pre_validate.c \
	init_var.c read_flags.c operation_push_back.c checker.c reading_commands.c $(INCL)

debug: bug
	lldb -- $(NAME) $(TEST)

%.o: ./%.c
	$(GCC) $(F) -o $@ -c $< -I ./
