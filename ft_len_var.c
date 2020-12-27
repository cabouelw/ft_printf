/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouelw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 16:14:29 by cabouelw          #+#    #+#             */
/*   Updated: 2019/12/28 19:52:02 by cabouelw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		len_int(long long nbr)
{
	int			idx;
	long long	tmp_int;

	tmp_int = nbr;
	idx = 0;
	if (tmp_int < 0 && ((idx++)))
		tmp_int = tmp_int * -1;
	if (nbr == 0)
		return (1);
	while (tmp_int != 0)
	{
		tmp_int = tmp_int / 10;
		idx++;
	}
	return (idx);
}

int		len_int_in_chr(char *format)
{
	int nbr_chr;

	nbr_chr = 0;
	while (format[nbr_chr] != '.' && format[nbr_chr] != '\0'
	&& !ft_isalpha(format[nbr_chr]))
		nbr_chr++;
	return (nbr_chr);
}

int		len_flag(char *format, int start)
{
	while (format[start] != ' ' || format[start] != '\0')
	{
		start++;
		if (ft_isalpha(format[start]) || format[start] == '%')
			return (start);
	}
	return (0);
}

int		get_width_chr(char *format)
{
	int idx;
	int s;

	s = 1;
	idx = 1;
	while (format[idx] == '-')
	{
		s = -1;
		idx++;
	}
	while (format[idx] == '0')
		idx++;
	if (format[idx] == '.' || ft_isalpha(format[idx])
	|| format[idx] == '%' || format[idx] == '\0')
		return (0);
	if (ft_atoi(format + idx) != 0)
	{
		if (ft_atoi(format + idx) > 0)
			return (ft_atoi(format + idx) * s);
		else
			return (ft_atoi(format + idx));
	}
	return (ft_atoi(format + idx));
}
