#ifndef MINI_PAINT_H
# define MINI_PAINT_H

#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

typedef struct	s_stock
{
	int w;
	int h;
	char back;
	float	x;
	float	y;
	float	rad;
	char	c;
	char	**tab;
}				t_stock;

void	cercleplein(t_stock *stock);
void	cerclevide(t_stock *stock);

#endif
