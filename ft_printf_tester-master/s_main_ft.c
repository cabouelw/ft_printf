#include "ft_printf.h"

int main()
{
	int i,j,y,u = 0,x;
	char *str = "hello";

	i = -5;
	ft_printf("%d\n", ft_printf("%09.*d\n", -1, 22));
	while (i < 5)
	{
		j = -5;
		while (j < 5)
		{
			ft_printf("\n\n");
			ft_printf("\033[0;33m[]\033[0m");
			ft_printf("[%d]--[%d]\n", i, j);
			x = ft_printf("|%*.*s|", i, j, "hel");
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
			x = ft_printf("|%0*.*s|", i, j, "hel");
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
			x = ft_printf("|%-*.*s|", i, j, "hel");
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
			x = ft_printf("|%-0*.*s|", i, j, "hel");
			ft_printf("\nreturn : %d\n", x);
			j++;
		}
		i++;
	}

	return (0);
}
