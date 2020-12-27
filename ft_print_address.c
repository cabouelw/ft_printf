/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouelw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 15:34:13 by cabouelw          #+#    #+#             */
/*   Updated: 2019/12/28 19:55:24 by cabouelw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	initilazier(int *nbr1, int *nbr2)
{
	*nbr1 = 0;
	*nbr2 = 0;
}

int		ft_print_width_prec_add(unsigned long int output, int width, int prec)
{
	int idx;
	int nbr_c;
	int temp_width;
	int nbr_zero;
	int nbr_esp;

	idx = (output == 0 && width > 2) ? -1 : 0;
	nbr_c = 0;
	nbr_zero = prec <= len_hexa(output) ? 0 : prec - len_hexa(output);
	temp_width = width > 0 ? width : width * -1;
	nbr_esp = temp_width > len_hexa(output) + nbr_zero + 2
		? temp_width - len_hexa(output) - nbr_zero - 2 : 0;
	while (idx++ < nbr_esp && width > 0)
		nbr_c += ft_putchar_fd(' ', 1);
	idx = 0;
	nbr_c += ft_putstr_fd("0x", 1);
	while (idx++ < nbr_zero)
		nbr_c += ft_putchar_fd('0', 1);
	if (output != 0)
		nbr_c += get_address_without_0x(output);
	idx = (output == 0 && width < -2) ? -1 : 0;
	while (idx++ < nbr_esp && width < 0)
		nbr_c += ft_putchar_fd(' ', 1);
	return (nbr_c);
}

int		ft_print_width_address(unsigned long int output, int width)
{
	int nbr_c;
	int idx;

	nbr_c = 0;
	idx = len_hexa(output) + 2;
	if (width > idx)
		while (idx++ < width)
			nbr_c += ft_putchar_fd(' ', 1);
	nbr_c += get_address_with_0x(output);
	if (width < 0)
	{
		width *= -1;
		while (idx++ < width)
			nbr_c += ft_putchar_fd(' ', 1);
	}
	return (nbr_c);
}

int		ft_print_width_zero_add(unsigned long int output, int width)
{
	int idx;
	int nbr_c;
	int nbr_zero;

	if (width < 0)
		return (ft_print_width_address(output, width));
	initilazier(&idx, &nbr_c);
	nbr_zero = width >= len_hexa(output) - 2 ? width - len_hexa(output) - 2 : 0;
	nbr_c += ft_putstr_fd("0x", 1);
	while (width > 0 && idx++ < nbr_zero)
		nbr_c += ft_putchar_fd('0', 1);
	get_address_without_0x(output);
	nbr_c += len_hexa(output);
	return (nbr_c);
}
