#include "ft_printf.h"

int main()
{
	int i,j,y,x;

	i = -5;
	while (i < 5)
	{
		j = -5;
		while (j < 5)
		{
			ft_printf("\n\n");
			ft_printf("\033[0;33m[]\033[0m");
			ft_printf("[%d]--[%d]\n", i, j);
			x = ft_printf("|%*.*%|", i, j);
			ft_printf("\nreturn : %d\n", x);
			j++;
		}
		i++;
	}

	i = -5;
	while (i < 5)
	{
		j = -5;
		while (j < 5)
		{
			ft_printf("\n\n");
			ft_printf("\033[0;33m[0]\033[0m");
			ft_printf("[%d]--[%d]\n", i, j);
			x = ft_printf("|%0*.*%|", i, j);
			ft_printf("\nreturn : %d\n", x);
			j++;
		}
		i++;
	}

	i = -5;
	while (i < 5)
	{
		j = -5;
		while (j < 5)
		{
			ft_printf("\n\n");
			ft_printf("\033[0;33m[-]\033[0m");
			ft_printf("[%d]--[%d]\n", i, j);
			x = ft_printf("|%-*.*%|", i, j);
			ft_printf("\nreturn : %d\n", x);
			j++;
		}
		i++;
	}

	i = -5;
	while (i < 5)
	{
		j = -5;
		while (j < 5)
		{
			ft_printf("\n\n");
			ft_printf("\033[0;33m[-0]\033[0m");
			ft_printf("[%d]--[%d]\n", i, j);
			x = ft_printf("|%-0*.*%|", i, j);
			ft_printf("\nreturn : %d\n", x);
			j++;
		}
		i++;
	}

	return (0);
}
