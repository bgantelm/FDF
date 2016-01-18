/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_postion.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 19:34:13 by fhenri            #+#    #+#             */
/*   Updated: 2016/01/18 15:39:40 by fhenri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void ft_affichage( t_data *test, t_data val)
{
	int a = 0;
	int b = 0;
	while(a < val.x)
	{
		b = 0;
		while (b < val.y)
		{
			ft_putnbr(test->tab_final[a][b].x);
			ft_putstr(" ");
			ft_putnbr(test->tab_final[a][b].y);
			b++;
		}

			ft_putchar('\n');
		a++;
	}
}
t_data **tab_pos(t_data val, t_data *test)
{
	int a;
	int b;
	int z;
	float cte = 1.5;
	z = 0;
	a = 0;
	b = 0;

	test->tab_final = (t_point**)malloc(sizeof(t_point *) *val.x);
	while(a <val.x)
	{
		b = 0;
		test->tab_final[a] = (t_point*)malloc(sizeof(t_point) * val.y);
		while(b < val.y)
		{
			test->tab_final[a][b].z = test->grid[a][b];
			z = test->tab_final[a][b].z;
			//ft_putstr("z : ");
			//ft_putnbr(test->tab_final[a][b].z);
			test->tab_final[a][b].x = (b * (1400 - 100) /val.y) + cte * (-1 * z) + 50;
			test->tab_final[a][b].y = (a * (850 - 100) / val.x) + (cte/2 ) * (-1 * z)  + 50;
			ft_putstr(" | x : ");
			ft_putnbr(test->tab_final[a][b].x);
			ft_putstr(" | y : ");
			ft_putnbr(test->tab_final[a][b].y);
			ft_putstr("\n");
			b++;
		}
		ft_putstr("\n");
		a++;
	}
		//	ft_putnbr(test->tab_final[3][3].y);
//	ft_affichage(test,val);
	return(test->tab_final);
}