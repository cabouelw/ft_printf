#include "stdio.h"

int main()
{
	int i,j,y,n,x;

	n = -7;
	while (n < 7)
	{
		i = -5;
		while (i < 5)
		{
			j = -5;
			while (j < 5)
			{
				printf("\n\n");
				printf("\033[0;33m[]\033[0m");
				printf("[%d]--[%d]--[%d]\n", i, j, n);
				x = printf("|%*.*d|", i, j, n);
				printf("\nreturn : %d\n", x);
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
				printf("\n\n");
				printf("\033[0;33m[0]\033[0m");
				printf("[%d]--[%d]--[%d]\n", i, j, n);
				x = printf("|%0*.*d|", i, j, n);
				printf("\nreturn : %d\n", x);
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
				printf("\n\n");
				printf("\033[0;33m[-]\033[0m");
				printf("[%d]--[%d]--[%d]\n", i, j, n);
				x = printf("|%-*.*d|", i, j, n);
				printf("\nreturn : %d\n", x);
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
				printf("\n\n");
				printf("\033[0;33m[-0]\033[0m");
				printf("[%d]--[%d]--[%d]\n", i, j, n);
				x = printf("|%-0*.*d|", i, j, n);
				printf("\nreturn : %d\n", x);
				j++;
			}
			i++;
		}
		n++;
	}
	return (0);
}
