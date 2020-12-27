/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouelw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 16:48:51 by cabouelw          #+#    #+#             */
/*   Updated: 2019/10/31 21:28:02 by cabouelw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_putstr_fd(char *s, int fd)
{
	int len;

	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
	return (len);
}
