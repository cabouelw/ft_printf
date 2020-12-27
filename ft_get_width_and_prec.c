/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_nbs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouelw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 15:16:36 by cabouelw          #+#    #+#             */
/*   Updated: 2019/12/29 15:19:19 by cabouelw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		get_prec(long int prec, long int input)
{
	long int new_prec;

	new_prec = 0;
	prec = (prec > 0) ? prec : prec * -1;
	if (prec > len_int((input < 0) ? input * -1 : input))
		new_prec = prec - len_int((input < 0) ? input * -1 : input);
	else
		new_prec = 0;
	return (new_prec);
}

int		get_width(long int width, long int prec, long int input)
{
	long int new_width;
	long int prec_tm;

	new_width = 0;
	prec_tm = get_prec(prec, input);
	width = (width > 0) ? width : width * -1;
	if (width > len_int(input) + prec_tm)
		new_width = width - (len_int(input) + prec_tm);
	return (new_width);
}

int		get_prec_hexa(long int prec, unsigned long int input)
{
	long int new_prec;

	new_prec = 0;
	prec = (prec > 0) ? prec : prec * -1;
	if (prec > len_hexa(input))
		new_prec = prec - len_hexa(input);
	else
		new_prec = 0;
	return (new_prec);
}

int		get_width_hexa(long int width, long int prec, unsigned long int input)
{
	long int new_nb1;
	long int prec_tm;

	new_nb1 = 0;
	prec_tm = get_prec_hexa(prec, input);
	width = (width > 0) ? width : width * -1;
	if (width > len_hexa(input) + prec_tm)
		new_nb1 = width - (len_hexa(input) + prec_tm);
	return (new_nb1);
}
