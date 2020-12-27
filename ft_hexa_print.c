/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouelw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 15:59:28 by cabouelw          #+#    #+#             */
/*   Updated: 2019/12/28 19:44:29 by cabouelw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			ft_print_width_prec_zero_hexa(long int input, int width, int prec)
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
		nbc += decimal_to_hexa(input);
	else if (prec == 0 && width != 0)
		nbc += ft_putchar_fd(' ', 1);
	idx = 0;
	if (width < 0)
		while (idx++ < get_width_hexa(width, prec, input))
			nbc += ft_putchar_fd(' ', 1);
	return (nbc);
}

int			ft_print_width_zero_hexa(unsigned int input, int width)
{
	int idx;
	int nbc;
	int nb_c;

	idx = 0;
	nbc = 0;
	if (width < 0)
		return (ft_print_hexa(input, width));
	nb_c = width >= len_hexa(input) ? width - len_hexa(input) : 0;
	while (width > 0 && idx++ < nb_c)
		nbc += ft_putchar_fd('0', 1);
	decimal_to_hexa(input);
	nbc += len_hexa(input);
	return (nbc);
}

int			ft_print_hexa(unsigned int var, int nb)
{
	int nbc;
	int idx;

	if (nb == 0 && var == 0)
		return (0);
	nbc = 0;
	idx = len_hexa(var);
	if (nb > idx)
		while (idx++ < nb)
			nbc += ft_putchar_fd(' ', 1);
	nbc += len_hexa(var);
	decimal_to_hexa(var);
	if (nb < 0)
	{
		nb *= -1;
		while (idx++ < nb)
			nbc += ft_putchar_fd(' ', 1);
	}
	return (nbc);
}

int			ft_print_width_prec_hexa(unsigned int var, int nb1, int nb2)
{
	int nbc;
	int idx;

	nbc = 0;
	idx = 0;
	if (nb1 > 0)
		while (idx++ < get_width_hexa(nb1, nb2, var))
			nbc += ft_putchar_fd(' ', 1);
	idx = 0;
	while (idx++ < get_prec_hexa(nb2, var))
		nbc += ft_putchar_fd('0', 1);
	if (nb2 != 0 || var != 0)
		nbc += decimal_to_hexa(var);
	else if (nb2 == 0 && nb1 != 0)
		nbc += ft_putchar_fd(' ', 1);
	idx = 0;
	if (nb1 < 0)
		while (idx++ < get_width_hexa(nb1, nb2, var))
			nbc += ft_putchar_fd(' ', 1);
	return (nbc);
}
