/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouelw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 17:41:07 by cabouelw          #+#    #+#             */
/*   Updated: 2019/12/28 19:23:34 by cabouelw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		decimal_to_hexa(unsigned int input)
{
	char				*puthexa;
	unsigned long int	temp_hexa;
	unsigned long int	result;
	int					nbr_chr;
	int					idx;

	if (input == 0 || input == (unsigned int)NULL)
		return (ft_putchar_fd('0', 1));
	temp_hexa = input;
	idx = 0;
	nbr_chr = 0;
	puthexa = (char*)malloc(len_hexa(temp_hexa));
	ft_bzero(puthexa, ft_strlen(puthexa));
	while (temp_hexa != 0)
	{
		result = temp_hexa % 16;
		puthexa[idx++] = (result < 10) ? result + 48 : result + 55;
		temp_hexa /= 16;
	}
	while (--idx >= 0)
		nbr_chr += ft_putchar_fd((puthexa[idx] > 47 && puthexa[idx] < 58)
				? puthexa[idx] : (puthexa[idx] + 32), 1);
	free(puthexa);
	return (nbr_chr);
}

int		get_address_without_0x(unsigned long int input)
{
	char				*puthexa;
	unsigned long int	temp_hexa;
	unsigned long int	result;
	int					nbr_chr;
	int					idx;

	if (input == 0)
		return (ft_putchar_fd('0', 1));
	temp_hexa = input;
	idx = 0;
	nbr_chr = 0;
	puthexa = (char*)malloc(len_hexa(temp_hexa));
	ft_bzero(puthexa, ft_strlen(puthexa));
	while (temp_hexa != 0)
	{
		result = temp_hexa % 16;
		puthexa[idx++] = (result < 10) ? result + 48 : result + 55;
		temp_hexa /= 16;
	}
	while (--idx >= 0)
		nbr_chr += ft_putchar_fd((puthexa[idx] > 47 && puthexa[idx] < 58)
				? puthexa[idx] : (puthexa[idx] + 32), 1);
	free(puthexa);
	return (nbr_chr);
}

int		get_address_with_0x(unsigned long int input)
{
	char				*puthexa;
	unsigned long int	temp_hexa;
	unsigned long int	result;
	int					nbr_chr;
	int					idx;

	temp_hexa = input;
	initilazier(&idx, &nbr_chr);
	puthexa = (char*)malloc(len_hexa(temp_hexa));
	ft_bzero(puthexa, ft_strlen(puthexa));
	while (temp_hexa != 0)
	{
		result = temp_hexa % 16;
		puthexa[idx++] = (result < 10) ? result + 48 : result + 55;
		temp_hexa /= 16;
	}
	nbr_chr = ft_putstr_fd("0x", 1);
	if (input == 0 || input == (long int)NULL)
		return (ft_putchar_fd('0', 1) + 2);
	while (--idx >= 0)
		nbr_chr += ft_putchar_fd((puthexa[idx] > 47 && puthexa[idx] < 58)
				? puthexa[idx] : (puthexa[idx] + 32), 1);
	free(puthexa);
	return (nbr_chr);
}

int		decimal_to_up_hexa(unsigned long int input)
{
	char				*puthexa;
	unsigned long int	temp_hexa;
	unsigned long int	result;
	int					nbr_chr;
	int					idx;

	if (input == 0 || input == (unsigned int)NULL)
		return (ft_putchar_fd('0', 1));
	temp_hexa = input;
	idx = 0;
	nbr_chr = 0;
	puthexa = (char*)malloc(len_hexa(temp_hexa));
	ft_bzero(puthexa, ft_strlen(puthexa));
	while (temp_hexa != 0)
	{
		result = temp_hexa % 16;
		puthexa[idx++] = (result < 10) ? result + 48 : result + 55;
		temp_hexa /= 16;
	}
	while (idx-- > 0)
		nbr_chr += ft_putchar_fd(puthexa[idx], 1);
	free(puthexa);
	return (nbr_chr);
}

int		len_hexa(unsigned long int hexa)
{
	unsigned long int len;

	len = 0;
	if (hexa == 0 || hexa == (unsigned long int)NULL)
		return (1);
	while (hexa != 0)
	{
		hexa /= 16;
		len++;
	}
	return (len);
}
