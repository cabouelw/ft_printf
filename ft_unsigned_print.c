/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uinteger_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouelw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 23:36:54 by cabouelw          #+#    #+#             */
/*   Updated: 2019/12/31 04:12:00 by cabouelw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_print_width_prec_unsig(unsigned int input, int width, int prec)
{
	int nbr_chr;
	int idx;

	nbr_chr = 0;
	idx = 0;
	if (width > 0)
		while (idx++ < get_width(width, prec, input))
			nbr_chr += ft_putchar_fd(' ', 1);
	idx = 0;
	while (idx++ < get_prec(prec, input))
		nbr_chr += ft_putchar_fd('0', 1);
	if (prec != 0 || input != 0)
		ft_putnbr_fd(input, 1);
	else if (prec == 0 && width != 0)
		nbr_chr += ft_putchar_fd(' ', 1);
	idx = 0;
	if (width < 0)
		while (idx++ < get_width(width, prec, input))
			nbr_chr += ft_putchar_fd(' ', 1);
	nbr_chr += (input != 0 || prec != 0) ? len_int(input) : 0;
	return (nbr_chr);
}

int		ft_print_width_unsig(unsigned int input, int width)
{
	int nbc;
	int idx;

	nbc = 0;
	idx = len_int(input);
	if (width > idx)
		while (idx++ < width)
			nbc += ft_putchar_fd(' ', 1);
	ft_putnbr_fd(input, 1);
	nbc += len_int(input);
	if (width < 0)
	{
		width *= -1;
		while (idx++ < width)
			nbc += ft_putchar_fd(' ', 1);
	}
	return (nbc);
}

int		ft_print_zero_unsig(unsigned int input, int width)
{
	int idx;
	int nbr_chr;
	int nbr_zero;

	idx = 0;
	nbr_chr = 0;
	if (width < 0)
		return (ft_print_width_unsig(input, width));
	nbr_zero = width >= len_int(input) ? width - len_int(input) : 0;
	while (width > 0 && idx++ < nbr_zero)
		nbr_chr += ft_putchar_fd('0', 1);
	ft_putnbr_fd(input, 1);
	nbr_chr += len_int(input);
	return (nbr_chr);
}

int		ft_print_width_prec_zero_unsig(unsigned int input, int width, int prec)
{
	int			nbr_chr;
	int			idx;

	nbr_chr = 0;
	idx = 0;
	if (width > 0)
		while (idx++ < get_width(width, prec, input))
			nbr_chr += ft_putchar_fd(' ', 1);
	idx = 0;
	while (idx++ < get_prec(prec, input))
		nbr_chr += ft_putchar_fd('0', 1);
	if (input != 0 || prec != 0)
		ft_putnbr_fd(input, 1);
	else if (prec == 0 && width != 0)
		nbr_chr += ft_putchar_fd(' ', 1);
	idx = 0;
	if (width < 0)
		while (idx++ < get_width(width, prec, input))
			nbr_chr += ft_putchar_fd(' ', 1);
	nbr_chr += (input != 0 || prec != 0) ? len_int(input) : 0;
	return (nbr_chr);
}
