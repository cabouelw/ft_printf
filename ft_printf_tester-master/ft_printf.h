/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouelw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 15:06:38 by cabouelw          #+#    #+#             */
/*   Updated: 2019/12/31 04:11:18 by cabouelw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int				ft_atoi(const char *format);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
void			ft_bzero(void *s, size_t n);
int				ft_putchar_fd(char c, int fd);
void			ft_putnbr_fd(long int nb, int fd);
int				ft_putstr_fd(char *format, int fd);
size_t			ft_strlen(const char *format);
char			*ft_itoa(int nbr);
int				ft_printf(const char *format, ...);
int				len_int(long long nb);
char			*ft_strdup(const char *s1);
int				len_int_in_chr(char *nb);
int				len_flag(char *format, int start);
int				ft_simpl_flag(char type, void *input);
int				decimal_to_hexa(unsigned int nb);
int				get_address_without_0x(unsigned long int input);
int				get_address_with_0x(unsigned long int input);
int				decimal_to_up_hexa(unsigned long int input);
int				len_hexa(unsigned long int x);
int				ft_flag_width(char *format, int width, void *input);
int				ft_flag_width_prec(char *format, void *input);
int				ft_print_str(char *input, int width);
int				ft_print_chr(char input, int width);
int				ft_flags_zero(char *format, void *input);
int				ft_print_int(int input, int width);
int				ft_print_hexa(unsigned int input, int width);
int				ft_print_up_hexa(unsigned int input, int width);
int				ft_print_width_address(unsigned long int input, int width);
int				ft_flag_width_zero(void *input, int width, char type);
int				ft_flag_width_prec_zero(void *input, int width,
		int prec, char type);
int				ft_print_width_prec_str(char *input, int width, int prec);
int				ft_print_width_prec(int input, int width, int prec);
int				ft_print_width_prec_unsig(unsigned int input,
		int width, int prec);
int				ft_print_width_prec_up_hexa(unsigned int input,
		int width, int prec);
int				ft_print_width_prec_hexa(unsigned int input,
		int width, int prec);
int				ft_print_width_prec_add(unsigned long int input,
		int width, int prec);
int				ft_print_width_unsig(unsigned int input, int width);
int				ft_print_zero_chr(char input, int nb);
int				ft_isetoile(char *format);
char			*ft_find_remp(char *format, int str1);
int				ft_print_width_prec_zero_int(int input, int width, int prec);
int				ft_print_width_zero_int(int input, int nb);
int				ft_print_width_prec_zero_str(char *input, int width, int prec);
int				ft_print_width_zero_str(char *input, int nb);
int				ft_print_zero_unsig(unsigned int input, int nb);
int				ft_print_width_prec_zero_unsig(unsigned int input,
		int width, int prec);
int				ft_nbr_is_pos_seg(int ln_var, int width,
		int input, int nbc, int prec);
int				ft_print_width_prec_zero_add(unsigned long int input,
		int width, int prec);
int				ft_print_width_zero_add(unsigned long int input, int nb);
int				ft_print_width_prec_zero_chr(char *input, int width, int prec);
int				ft_print_width_chr(char input, int nb);
int				ft_print_width_prec_zero_hexa(long int input,
		int width, int prec);
int				ft_print_width_zero_up_hexa(unsigned int input, int nb);
int				ft_print_width_zero_hexa(unsigned int input, int nb);
int				ft_print_width_prec_zero_up_hexa(long int input,
		int width, int prec);
int				ft_flag_modulo(char *format);
void			initilazier(int *nbr1, int *nbr2);
int				get_prec(long int prec, long int input);
int				get_width(long int width, long int prec, long int input);
int				get_prec_hexa(long int prec, unsigned long int input);
int				get_width_hexa(long int width, long int prec,
		unsigned long int input);
int				get_width_chr(char *format);

#endif
