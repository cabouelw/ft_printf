# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cabouelw <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/02 18:55:27 by cabouelw          #+#    #+#              #
#    Updated: 2019/12/31 15:19:21 by cabouelw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FUNCTIONS = ft_print_address.c ft_atoi.c ft_get_width_and_prec.c ft_bzero.c ft_flag_modulo.c ft_char_print.c ft_conv_hexa.c ft_etoile.c ft_flags_print.c ft_hexa_print.c ft_integer_print.c ft_isalpha.c ft_isdigit.c ft_itoa.c ft_len_var.c ft_printf.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_str_print.c ft_strdup.c ft_strlen.c ft_unsigned_print.c ft_uper_hexa_print.c

FLAGS = -Wall -Wextra -Werror -c
BINS = ft_print_address.o ft_atoi.o ft_bzero.o ft_get_width_and_prec.o ft_flag_modulo.o ft_char_print.o ft_conv_hexa.o ft_etoile.o ft_flags_print.o ft_hexa_print.o ft_integer_print.o ft_isalpha.o ft_isdigit.o ft_itoa.o ft_len_var.o ft_printf.o ft_putchar_fd.o ft_putstr_fd.o ft_putnbr_fd.o ft_str_print.o ft_strdup.o ft_strlen.o ft_unsigned_print.o ft_uper_hexa_print.o


all: $(NAME)

$(NAME): $(BINS)
	ar rc $(NAME) $(BINS)
	ranlib $(NAME)

%.o:%.c
	cc $(FLAGS) $< -o $@

clean:
	@rm -f $(BINS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

