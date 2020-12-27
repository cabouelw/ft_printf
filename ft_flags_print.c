/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouelw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 15:43:37 by cabouelw          #+#    #+#             */
/*   Updated: 2019/12/28 19:48:18 by cabouelw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_flag_width_prec(char *format, void *input)
{
	char	type;
	int		width;
	int		prec;

	type = format[len_flag(format, 0)];
	width = get_width_chr(format);
	prec = ft_atoi(format + len_int_in_chr(format + 1) + 2);
	if (type == 'd' || type == 'i')
		return ((prec < 0) ? ft_print_int((int)input, width) :
				ft_print_width_prec((int)input, width, prec));
	else if (type == 'c')
		return (ft_print_chr((int)input, width));
	else if (type == 'u')
		return (ft_print_width_prec_unsig((unsigned int)input, width, prec));
	else if (type == 'X')
		return (ft_print_width_prec_up_hexa((unsigned int)input, width, prec));
	else if (type == 'x')
		return (ft_print_width_prec_hexa((unsigned int)input, width, prec));
	else if (type == 'p')
		return (ft_print_width_prec_add((unsigned long int)input, width, prec));
	if (type == 's' && prec >= 0)
		return (ft_print_width_prec_str((char*)input, width, prec));
	else
		return (ft_print_str("", prec));
}

int		ft_flag_width(char *str, int width, void *input)
{
	char	type;

	type = str[len_flag(str, 0)];
	if (type == 's')
		return (ft_print_str((char*)input, width));
	else if (type == 'd' || type == 'i')
		return (ft_print_int((int)input, width));
	else if (type == 'c')
		return (ft_print_chr((int)input, width));
	else if (type == 'u')
		return (ft_print_width_unsig((unsigned int)input, width));
	else if (type == 'X')
		return (ft_print_up_hexa((unsigned int)input, width));
	else if (type == 'x')
		return (ft_print_hexa((unsigned int)input, width));
	else if (type == 'p')
		return (ft_print_width_address((long int)input, width));
	return (0);
}

int		ft_flag_width_zero(void *input, int width, char type)
{
	if (type == 's')
		return (ft_print_width_zero_str((char*)input, width));
	else if (type == 'd' || type == 'i')
		return (ft_print_width_zero_int((int)input, width));
	else if (type == 'c')
		return (ft_print_zero_chr((int)input, width));
	else if (type == 'u')
		return (ft_print_zero_unsig((unsigned int)input, width));
	else if (type == 'X')
		return (ft_print_width_zero_up_hexa((unsigned int)input, width));
	else if (type == 'x')
		return (ft_print_width_zero_hexa((unsigned int)input, width));
	else if (type == 'p')
		return (ft_print_width_zero_add((long int)input, width));
	return (0);
}

int		ft_flag_width_prec_zero(void *input, int width, int prec, char type)
{
	if (type == 's')
		return (ft_print_width_prec_zero_str((char*)input, width, prec));
	if (type == 'd' || type == 'i')
		return ((prec < 0) ? ft_print_int((int)input, prec) :
		ft_print_width_prec_zero_int((int)input, width, prec));
	else if (type == 'c')
		return (ft_print_zero_chr((int)input, width));
	else if (type == 'u')
		return ((prec > 0) ? ft_print_width_prec_unsig((unsigned int)input,
		width, prec) : ft_print_width_prec_zero_unsig((unsigned int)input,
		width, prec));
	else if (type == 'X')
		return ((prec > 0) ? ft_print_width_prec_up_hexa((unsigned int)input,
		width, prec) : ft_print_width_prec_zero_up_hexa((unsigned int)input,
		width, prec));
	else if (type == 'x')
		return ((prec > 0) ? ft_print_width_prec_hexa((unsigned int)input,
		width, prec)
		: ft_print_width_prec_zero_hexa((unsigned int)input, width, prec));
	else if (type == 'p')
		return (ft_print_width_prec_add((long int)input, width, prec));
	return (0);
}

int		ft_simpl_flag(char type, void *input)
{
	int i;

	i = 0;
	if (type == 's')
		i = ft_putstr_fd(input, 1);
	else if (type == 'd' || type == 'i')
	{
		ft_putnbr_fd((int)input, 1);
		i = len_int((int)input);
	}
	else if (type == 'c')
		return (ft_putchar_fd((char)input, 1));
	else if (type == 'u')
	{
		ft_putnbr_fd((unsigned int)input, 1);
		i = len_int((unsigned int)input);
	}
	else if (type == 'X')
		i = decimal_to_up_hexa((unsigned int)input);
	else if (type == 'x')
		i = decimal_to_hexa((unsigned int)input);
	else if (type == 'p')
		i = get_address_with_0x((unsigned long int)input);
	return (i);
}
