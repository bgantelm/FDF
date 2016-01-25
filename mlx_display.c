/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 15:02:57 by fhenri            #+#    #+#             */
/*   Updated: 2016/01/25 15:33:41 by fhenri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void ft_draw_line(t_point a, t_point b, t_data *val)
{
	int y;
	int x;
	double  coef;
	double origin;
	t_point *p;

	p = malloc(sizeof(t_point));
	if (a.x != b.x)
	{
		coef = ((b.y - a.y) / (b.x - a.x));
		origin = (a.y - ((b.y - a.y) / (b.x - a.x)) * a.x);
		x = (a.x < b.x) ? (a.x) : (b.x);
		while (x <= a.x || x < b.x)  
		{
			y = coef * x + origin;
			p->x = x;
			p->y = y;
			rotate_point(600,500,p,val);
			if (a.z != 0)
				mlx_pixel_put(val->mlx,val->win,p->x,p->y,0x00996600);
			else
				mlx_pixel_put(val->mlx,val->win,p->x,p->y,0x0066FFF);
			x++;
		//	ft_putnbr(p->x);
		}
	}
	else
	{
		y = (a.y < b.y) ? (a.y) : (b.y);
		while (y <= b.y || y <= a.y)
		{
			p->x = a.x;
			p->y = y;
			rotate_point(600,500,p,val);
			if (a.z != 0)
				mlx_pixel_put(val->mlx,val->win,p->x,p->y,0x00996600);
			else
				mlx_pixel_put(val->mlx,val->win,p->x,p->y,0x0066FFF);
			y++;
		}
	} 
} 

void	mlx_display(t_data *val)
{
	int a;
	int b;

	a = 0;
	while(a < val->x)
	{
		b = 0;
		while (b < val->y)
		{
			if (b != 0)
				ft_draw_line(val->final[a][b - 1], val->final[a][b],val);
			if (a != 0)
			{
				if (a <val->y)
					ft_draw_line(val->final[a - 1][b],val->final[a][b],val);
			}
			b++;
		}
		a++;
	}
}
