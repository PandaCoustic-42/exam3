/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_paint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpanneau <jpanneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 12:33:29 by jpanneau          #+#    #+#             */
/*   Updated: 2019/12/12 09:22:49 by jpanneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_paint.h"

int		error(char *s,int len)
{
	write(1, s, len);
	write(1, "\n", 1);
	return (1);
}

int		main(int c, char **v)
{
	FILE 	*file;
	char	line[40];
	char	buf[2];
	t_stock	stock;
	int i;
	int x;
	int y;

	x = 0;
	y = 0;
	i = 0;
	line[0] = '\0';
	buf[1] = '\0';
	if (c < 2 || c > 2)
		return (error("Error: argument", 15));
	if ((file = fopen(v[1], "r")) == NULL)
		return (error("Error: file corrupted", 21));
	if (fscanf(file, "%i %i %c", &stock.w, &stock.h, &stock.back) == 0)
		return (error("Error: file corrupted", 21));
	if (stock.w > 300 || stock.w < 0 || stock.h > 300 || stock.h < 0)
		return (error("Error: file corrupted", 21));
	if ((stock.tab = malloc(sizeof(char *) * (stock.h + 1))) == NULL)
		return (error("Error: fail malloc", 18));
	while (i < stock.h)
	{
		if ((stock.tab[i] = malloc(sizeof(char) * (stock.w + 1))) == NULL)
			return (error("Error: fail malloc", 18));
		stock.tab[i] = memset(stock.tab[i], stock.back, stock.w);
		stock.tab[i][stock.w] = '\0';
		i++;
	}
	stock.tab[i] = NULL;
	while (fscanf(file, "%c %f %f %f %c", &stock.back, &stock.x, &stock.y, &stock.rad, &stock.c) != EOF)
	{
		if (stock.back == 'c')
			cerclevide(&stock);
		else if (stock.back == 'C')
			cercleplein(&stock);
		else if (stock.back != '\n')
			return (error("Error: file corrupted", 21));

	}
	while (stock.tab[y])
	{
		write(1, stock.tab[y], stock.w);
		write(1, "\n", 1);
		y++;
	}
	return (0);
}
