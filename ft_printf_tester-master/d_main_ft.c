#include "ft_printf.h"

int main()
{
	int i,j,y,x,n;

	n = -7;
	while (n < 7)
	{
		i = -5;
		while (i < 5)
		{
			j = -5;
			while (j < 5)
			{
				ft_printf("\n\n");
				ft_printf("\033[0;33m[]\033[0m");
				ft_printf("[%d]--[%d]--[%d]\n", i, j, n);
				x = ft_printf("|%*.*d|", i, j, n);
				ft_printf("\nreturn : %d\n", x);
				j++;
			}
			i++;
		}
		n++;
	}

	n = -7;
	while (n < 7)
	{
		i = -5;
		while (i < 5)
		{
			j = -5;
			while (j < 5)
			{
				ft_printf("\n\n");
				ft_printf("\033[0;33m[0]\033[0m");
				ft_printf("[%d]--[%d]--[%d]\n", i, j, n);
				x = ft_printf("|%0*.*d|", i, j, n);
				ft_printf("\nreturn : %d\n", x);
				j++;
			}
			i++;
		}
		n++;
	}

	n = -7;
	while (n < 7)
	{
		i = -5;
		while (i < 5)
		{
			j = -5;
			while (j < 5)
			{
				ft_printf("\n\n");
				ft_printf("\033[0;33m[-]\033[0m");
				ft_printf("[%d]--[%d]--[%d]\n", i, j, n);
				x = ft_printf("|%-*.*d|", i, j, n);
				ft_printf("\nreturn : %d\n", x);
				j++;
			}
			i++;
		}
		n++;
	}

	n = -7;
	while (n < 7)
	{
		i = -5;
		while (i < 5)
		{
			j = -5;
			while (j < 5)
			{
				ft_printf("\n\n");
				ft_printf("\033[0;33m[-0]\033[0m");
				ft_printf("[%d]--[%d]--[%d]\n", i, j, n);
				x = ft_printf("|%-0*.*d|", i, j, n);
				ft_printf("\nreturn : %d\n", x);
				j++;
			}
			i++;
		}
		n++;
	}
	return (0);
}
