/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouelw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 17:56:20 by cabouelw          #+#    #+#             */
/*   Updated: 2019/12/29 17:08:30 by cabouelw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_flags_zero(char *format, void *input)
{
	char	type;
	int		width;
	int		prec;

	width = get_width_chr(format);
	type = format[len_flag(format, 0)];
	if (format[len_int_in_chr(format + 1) + 1] != '.')
		return (ft_flag_width_zero(input, width, type));
	else if (format[len_int_in_chr(format + 1) + 1] == '.')
	{
		prec = get_width_chr(format + len_int_in_chr(format + 1) + 1);
		if (prec < 0 && type != 's')
			return (ft_flag_width_zero(input, width, type));
		return (ft_flag_width_prec_zero(input, width, prec, type));
	}
	return (0);
}

int		find_flags(char *format, void *input)
{
	int idx;

	idx = 1;
	if (ft_isalpha(format[idx]))
		return (ft_simpl_flag(format[idx], input));
	else if (format[idx] == '0')
		return (ft_flags_zero(format + idx, input));
	else if (format[len_int_in_chr(format + idx) + idx] != '.')
		return (ft_flag_width(format, get_width_chr(format), input));
	else if (format[len_int_in_chr(format + idx) + idx] == '.')
		return (ft_flag_width_prec(format, input));
	return (0);
}

int		ft_print(va_list ap, int idx, int nbr_chr, char *format)
{
	char *temp_format;

	while (format[idx] != '\0')
		if (format[idx] == '%')
		{
			if (ft_isetoile(format + idx))
			{
				temp_format = ft_find_remp(format + idx, va_arg(ap, int));
				if (ft_isetoile(temp_format))
					temp_format = ft_find_remp(temp_format, va_arg(ap, int));
				if (temp_format[len_flag(temp_format, 0)] == '%')
					nbr_chr += ft_flag_modulo(temp_format);
				else
					nbr_chr += find_flags(temp_format, va_arg(ap, void*));
				free(temp_format);
			}
			else if (format[len_flag(format, idx)] == '%')
				nbr_chr += ft_flag_modulo(format + idx);
			else
				nbr_chr += find_flags(format + idx, va_arg(ap, void*));
			idx = len_flag(format, idx) + 1;
		}
		else
			nbr_chr += ft_putchar_fd(format[idx++], 1);
	return (nbr_chr);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int			idx;
	int			nbr_chr;

	idx = 0;
	nbr_chr = 0;
	va_start(ap, (char*)format);
	while (format[idx])
	{
		if (format[idx] == '%')
		{
			if (ft_atoi(format + idx + 1) == 2147483647 && idx != 0)
				return (-1);
			idx = len_flag((char*)format, idx) + 1;
		}
		else
			idx++;
	}
	nbr_chr = ft_print(ap, 0, nbr_chr, (char*)format);
	va_end(ap);
	return (nbr_chr);
}
