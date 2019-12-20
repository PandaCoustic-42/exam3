/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpanneau <jpanneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 12:33:57 by jpanneau          #+#    #+#             */
/*   Updated: 2019/12/12 17:05:32 by jpanneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_paint.h"

void	cerclevide(t_stock *stock)
{
	float x;
	float y;
	float s;

	x = 0;
	y = 0;
	while (stock->tab[(int)y])
	{
		while (stock->tab[(int)y][(int)x])
		{
			s = sqrt((x - stock->x) * (x - stock->x) + (y - stock->y) * (y - stock->y));
			if (s <= stock->rad && s > stock->rad - 1)
				stock->tab[(int)y][(int)x] = stock->c;
			x++;
		}
		x = 0;
		y++;
	}
}

void	cercleplein(t_stock *stock)
{
	float x;
	float y;
	float s;

	x = 0;
	y = 0;
	while (stock->tab[(int)y])
	{
		while (stock->tab[(int)y][(int)x])
		{
			s = sqrt(pow(x - stock->x, 2) + pow(y - stock->y, 2));
			if (s <= stock->rad)
				stock->tab[(int)y][(int)x] = stock->c;
			x++;
		}
		x = 0;
		y++;
	}
}
