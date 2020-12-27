/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouelw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 14:57:58 by cabouelw          #+#    #+#             */
/*   Updated: 2019/12/29 15:15:59 by cabouelw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_modulo_width(int width)
{
	int idx;
	int nbr_chr;

	idx = 0;
	nbr_chr = 0;
	while (width > 0 && idx++ < width - 1)
		nbr_chr += ft_putchar_fd(' ', 1);
	nbr_chr += ft_putchar_fd('%', 1);
	if (width < 0)
	{
		width *= -1;
		while (width > 0 && idx++ < width - 1)
			nbr_chr += ft_putchar_fd(' ', 1);
	}
	return (nbr_chr);
}

int		ft_modulo_zero(int width)
{
	int idx;
	int nbr_chr;

	idx = 0;
	nbr_chr = 0;
	while (width > 0 && idx++ < width - 1)
		nbr_chr += ft_putchar_fd('0', 1);
	nbr_chr += ft_putchar_fd('%', 1);
	if (width < 0)
	{
		width *= -1;
		while (width > 0 && idx++ < width - 1)
			nbr_chr += ft_putchar_fd(' ', 1);
	}
	return (nbr_chr);
}

int		ft_modulo_zero_perc(int perc)
{
	int nbr_chr;
	int idx;

	nbr_chr = 0;
	idx = 0;
	if (perc > 0)
		while (idx++ < perc - 1)
			nbr_chr += ft_putchar_fd('0', 1);
	nbr_chr += ft_putchar_fd('%', 1);
	idx = 0;
	if (perc < 0)
	{
		perc *= -1;
		while (idx++ < perc - 1)
			nbr_chr += ft_putchar_fd(' ', 1);
	}
	return (nbr_chr);
}

int		ft_modulo_perc(int perc)
{
	int nbr_chr;
	int idx;

	nbr_chr = 0;
	idx = 0;
	if (perc > 0)
		while (idx++ < perc - 1)
			nbr_chr += ft_putchar_fd(' ', 1);
	nbr_chr += ft_putchar_fd('%', 1);
	idx = 0;
	if (perc < 0)
	{
		perc *= -1;
		while (idx++ < perc - 1)
			nbr_chr += ft_putchar_fd(' ', 1);
	}
	return (nbr_chr);
}

int		ft_flag_modulo(char *format)
{
	int idx;
	int perc;

	idx = 0;
	if (format[1] == '0' && format[len_int_in_chr(format + 1) + 1] == '.')
	{
		perc = get_width_chr(format + len_int_in_chr(format + 1) + 1);
		return ((perc >= 0) ? ft_modulo_zero_perc(get_width_chr(format))
		: ft_modulo_width(perc));
	}
	else if (format[len_int_in_chr(format + 1) + 1] == '.')
	{
		perc = get_width_chr(format + len_int_in_chr(format + 1) + 1);
		return ((perc >= 0) ? ft_modulo_perc(get_width_chr(format))
		: ft_modulo_width(perc));
	}
	else if (format[1] == '0')
		return (ft_modulo_zero(get_width_chr(format + 1)));
	else if (get_width_chr(format) != 0)
		return (ft_modulo_width(get_width_chr(format)));
	else
		return (ft_putchar_fd('%', 1));
	return (0);
}
