/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uper_hexa_print.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouelw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 23:39:04 by cabouelw          #+#    #+#             */
/*   Updated: 2019/12/26 23:41:46 by cabouelw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_print_width_prec_up_hexa(unsigned int input, int width, int prec)
{
	int nbr_chr;
	int idx;

	nbr_chr = 0;
	idx = 0;
	if (width > 0)
		while (idx++ < get_width_hexa(width, prec, input))
			nbr_chr += ft_putchar_fd(' ', 1);
	idx = 0;
	while (idx++ < get_prec_hexa(prec, input))
		nbr_chr += ft_putchar_fd('0', 1);
	if (prec != 0 || input != 0)
		nbr_chr += decimal_to_up_hexa(input);
	else if (prec == 0 && width != 0)
		nbr_chr += ft_putchar_fd(' ', 1);
	idx = 0;
	if (width < 0)
		while (idx++ < get_width_hexa(width, prec, input))
			nbr_chr += ft_putchar_fd(' ', 1);
	return (nbr_chr);
}

int		ft_print_up_hexa(unsigned int input, int width)
{
	int nbr_chr;
	int idx;

	if (width == 0 && input == 0)
		return (0);
	nbr_chr = 0;
	idx = len_hexa(input);
	if (width > idx)
		while (idx++ < width)
			nbr_chr += ft_putchar_fd(' ', 1);
	nbr_chr += len_hexa(input);
	decimal_to_up_hexa(input);
	if (width < 0)
	{
		width *= -1;
		while (idx++ < width)
			nbr_chr += ft_putchar_fd(' ', 1);
	}
	return (nbr_chr);
}

int		ft_print_width_zero_up_hexa(unsigned int input, int width)
{
	int idx;
	int nbc;
	int nb_c;

	idx = 0;
	nbc = 0;
	if (width < 0)
		return (ft_print_up_hexa(input, width));
	nb_c = width >= len_hexa(input) ? width - len_hexa(input) : 0;
	while (width > 0 && idx++ < nb_c)
		nbc += ft_putchar_fd('0', 1);
	decimal_to_up_hexa(input);
	nbc += len_hexa(input);
	return (nbc);
}

int		ft_print_width_prec_zero_up_hexa(long int input, int width, int prec)
{
	int nbc;
	int idx;

	nbc = 0;
	idx = 0;
	if (width > 0)
		while (idx++ < get_width_hexa(width, prec, input))
			nbc += ft_putchar_fd(' ', 1);
	idx = 0;
	while (idx++ < get_prec_hexa(prec, input))
		nbc += ft_putchar_fd('0', 1);
	if (input != 0 || prec != 0)
		nbc += decimal_to_up_hexa(input);
	else if (prec == 0 && width != 0)
		nbc += ft_putchar_fd(' ', 1);
	idx = 0;
	if (width < 0)
		while (idx++ < get_width_hexa(width, prec, input))
			nbc += ft_putchar_fd(' ', 1);
	return (nbc);
}
