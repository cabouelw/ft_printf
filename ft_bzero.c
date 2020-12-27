/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouelw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 16:52:55 by cabouelw          #+#    #+#             */
/*   Updated: 2019/10/31 20:51:09 by cabouelw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char *ptr;

	if (n == 0)
		return ;
	ptr = (unsigned char*)s;
	while (n--)
	{
		*ptr = '\0';
		if (n)
			ptr++;
	}
}
