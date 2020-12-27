/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_etoile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouelw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 23:24:13 by cabouelw          #+#    #+#             */
/*   Updated: 2019/12/26 23:28:26 by cabouelw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_ispos_or_neg(char *format, int prec)
{
	if (format[ft_isetoile(format) - 1] == '.')
	{
		if (format[len_flag(format, 0)] == 's')
			prec = prec < 0 ? 159999 : prec;
		if (format[len_flag(format, 0)] == '%')
			prec = 0;
		if (format[1] == '0')
			return (prec);
		else
			prec = prec < 0 ? 1 : prec;
	}
	return (prec);
}

char	*ft_find_remp(char *format, int width_prec)
{
	int		idx;
	int		idx_i;
	int		idx_j;
	char	*new_format;
	char	*input_value;

	width_prec = ft_ispos_or_neg(format, width_prec);
	input_value = ft_itoa(width_prec);
	idx = 0;
	idx_i = 0;
	idx_j = 0;
	new_format = (char*)malloc(ft_strlen(format) +
	ft_strlen(input_value) * (sizeof(char*)));
	ft_bzero(new_format, ft_strlen(format) + ft_strlen(input_value));
	while (format[idx] != '*')
		new_format[idx_i++] = format[idx++];
	idx++;
	while (input_value[idx_j] != '\0')
		new_format[idx_i++] = input_value[idx_j++];
	while (!ft_isalpha(format[idx]))
		new_format[idx_i++] = format[idx++];
	new_format[idx_i++] = format[idx];
	new_format[idx_i] = '\0';
	free(input_value);
	return (new_format);
}

int		ft_isetoile(char *format)
{
	int i;

	i = 1;
	while (!ft_isalpha(format[i]) && format[i] != '%')
	{
		if (format[i] == '*')
			return (i);
		i++;
	}
	return (0);
}
