/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_postion.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 19:34:13 by fhenri            #+#    #+#             */
/*   Updated: 2016/01/25 15:42:34 by fhenri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_data *tab_pos(t_data *val)
{
	int a;
	int b;
	int z;
	float cte = 1.5;
	z = 0;
	a = 0;
	val->final = (t_point**)malloc(sizeof(t_point *) *val->x);
	while(a <val->x)
	{
		b = 0;
		val->final[a] = (t_point*)malloc(sizeof(t_point) * val->y);
		while(b < val->y)
		{
			val->final[a][b].z = val->grid[a][b];
			z = val->final[a][b].z;
			//ft_putstr("z : ");
			//ft_putnbr(test->tab_final[a][b].z);
			val->final[a][b].x = (b * (1000 - 300) /val->y) + cte * (-1 * z) + val->droite;
			val->final[a][b].y = (a * (500 - 150) / val->x) + (cte/2 ) * (-1 * z)  + val->haut;
			ft_putstr(" | x : ");
			ft_putnbr(val->final[a][b].x);
			ft_putstr(" | y : ");
			ft_putnbr(val->final[a][b].y);
			ft_putstr("\n");
			b++;
		}
		ft_putstr("\n");
		a++;
	}
	return(val);
}
