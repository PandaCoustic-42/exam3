#include "mini_paint.h"

int	error(char *s, int len)
{
	write(1, s, len);
	write(1, "\n", 1);
	return(1);
}

int	main(int c, char **v)
{
	FILE *file;
	t_stock stock;
	int x;

	x = 0;
	if (c < 2 || c > 2)
		return (error("Error: arguments", 16));
	if ((file = fopen(v[1], "r")) == NULL)
		return (error("file corrupted", 14));
	if (fscanf(file, "%i %i %c", &stock.w, &stock.h, &stock.back) == EOF)
		return (error("file corrupted", 14));
	if (stock.w < 0 || stock.w > 300 || stock.h < 0 || stock.h > 300)
		return(error("file corrupted", 14));
	if ((stock.tab = malloc(sizeof(char *) * (stock.h + 1))) == NULL)
		return (error("Error: fail malloc", 18));
	while (x < stock.h)
	{
		if ((stock.tab[x] = malloc(sizeof(char) * (stock.w + 1))) == NULL)
			return (error("Error: fail malloc", 18));
		stock.tab[x] = memset(stock.tab[x], stock.back, stock.w);
		stock.tab[x][stock.w] = '\0';
		x++;
	}
	stock.tab[x] = NULL;
	x = 0;
	while (fscanf(file, " %c %f %f %f %c", &stock.back, &stock.x, &stock.y, &stock.rad, &stock.c) != EOF)
	{
		if (stock.back == 'c')
			cerclevide(&stock);
		else if (stock.back == 'C')
			cercleplein(&stock);
		else if (stock.back == '\n')
			return (error("file corrupted", 14));
	}
	while (stock.tab[x])
	{
		write(1, stock.tab[x], stock.w);
		write(1, "\n", 1);
		x++;
	}
	return (0);
}
