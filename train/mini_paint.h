/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_paint.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpanneau <jpanneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 12:33:45 by jpanneau          #+#    #+#             */
/*   Updated: 2019/12/10 14:50:00 by jpanneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_PAINT_H
# define MINI_PAINT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

typedef struct s_stock
{
	int		w;
	int		h;
	char	back;
	float	x;
	float	y;
	float	rad;
	char	c;
	char	**tab;
}			t_stock;

void	cerclevide(t_stock *stock);
void	cercleplein(t_stock *stock);

#endif
