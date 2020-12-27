/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouelw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 15:39:00 by cabouelw          #+#    #+#             */
/*   Updated: 2019/12/26 15:42:46 by cabouelw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_print_width_prec_zero_chr(char *output, int width, int prec)
{
	int idx;
	int nbr_chr;
	int nbr_zero;

	if (output == NULL)
		output = "(null)";
	nbr_zero = (prec < (int)ft_strlen(output)) ? prec : (int)ft_strlen(output);
	nbr_zero = nbr_zero < 0 ? 0 : nbr_zero;
	idx = 0;
	nbr_chr = 0;
	while (idx++ < width - nbr_zero)
		nbr_chr += ft_putchar_fd('0', 1);
	idx = 0;
	while (idx < nbr_zero)
		nbr_chr += ft_putchar_fd(output[idx++], 1);
	return (nbr_chr);
}

int		ft_print_zero_chr(char output, int width)
{
	int idx;
	int nbr_chr;
	int nbr_zero;

	idx = 0;
	nbr_chr = 0;
	if (width < 0)
		return (ft_print_chr(output, width));
	nbr_zero = width >= 1 ? width - 1 : 0;
	while (width > 0 && idx++ < nbr_zero)
		nbr_chr += ft_putchar_fd('0', 1);
	nbr_chr += ft_putchar_fd(output, 1);
	return (nbr_chr);
}

int		ft_print_chr(char output, int width)
{
	int nbr_chr;
	int idx;

	nbr_chr = 0;
	idx = 1;
	if (width > 1)
		while (idx++ < width)
			nbr_chr += ft_putchar_fd(' ', 1);
	nbr_chr += ft_putchar_fd(output, 1);
	if (width < 0)
	{
		width *= -1;
		while (idx++ < width)
			nbr_chr += ft_putchar_fd(' ', 1);
	}
	return (nbr_chr);
}
