/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouelw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 23:34:29 by cabouelw          #+#    #+#             */
/*   Updated: 2019/12/26 23:36:03 by cabouelw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_print_width_prec_zero_str(char *format, int width, int prec)
{
	int idx;
	int nbr_chr;
	int nbr_zero;

	if (prec < 0)
		return (ft_print_str("", prec));
	if (width < 0)
		return (ft_print_width_prec_str(format, width, prec));
	if (format == NULL)
		format = "(null)";
	nbr_zero = (prec < (int)ft_strlen(format)) ? prec : (int)ft_strlen(format);
	nbr_zero = nbr_zero < 0 ? 0 : nbr_zero;
	idx = 0;
	nbr_chr = 0;
	while (idx++ < width - nbr_zero)
		nbr_chr += ft_putchar_fd('0', 1);
	idx = 0;
	while (idx < nbr_zero)
		nbr_chr += ft_putchar_fd(format[idx++], 1);
	return (nbr_chr);
}

int		ft_print_width_zero_str(char *input, int width)
{
	int idx;
	int nbr_chr;
	int nbr_zero;

	idx = 0;
	nbr_chr = 0;
	nbr_zero = width >= (int)ft_strlen(input) ?
	width - (int)ft_strlen(input) : 0;
	while (width > 0 && idx++ < nbr_zero)
		nbr_chr += ft_putchar_fd('0', 1);
	if (width < 0)
		nbr_chr += ft_print_str(input, width);
	else
		nbr_chr += ft_putstr_fd(input, 1);
	return (nbr_chr);
}

int		ft_print_str(char *input, int width)
{
	int nbr_chr;
	int idx;

	if (input == NULL)
		input = "(null)";
	nbr_chr = 0;
	idx = ft_strlen(input);
	if (width > 0 && width > idx)
		while (idx++ < width)
			nbr_chr += ft_putchar_fd(' ', 1);
	nbr_chr += ft_putstr_fd(input, 1);
	if (width < 0)
	{
		width = width * -1;
		while (idx++ < width)
			nbr_chr += ft_putchar_fd(' ', 1);
	}
	return (nbr_chr);
}

int		ft_print_width_prec_str(char *input, int width, int prec)
{
	int idx;
	int nbr_esp;
	int nbr_chr;

	idx = 0;
	if (input == NULL)
		input = "(null)";
	nbr_chr = 0;
	nbr_esp = (prec > (int)ft_strlen(input) ? (int)ft_strlen(input) : prec);
	while (nbr_esp + idx++ < width && width > 0)
		nbr_chr += ft_putchar_fd(' ', 1);
	idx = 0;
	while (idx < nbr_esp)
		nbr_chr += ft_putchar_fd(input[idx++], 1);
	idx = 0;
	if (width < 0)
		while (nbr_esp + idx++ < (width * -1))
			nbr_chr += ft_putchar_fd(' ', 1);
	return (nbr_chr);
}
