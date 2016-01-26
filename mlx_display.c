/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 15:02:57 by fhenri            #+#    #+#             */
/*   Updated: 2016/01/26 15:28:45 by fhenri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
void ft_draw_line(t_point a, t_point b, t_data *val)
{
	int dx;
	int dy;
	int i;
	int xinc;
	int yinc;
	int cumul;
	int x;
	int y;
	x = a.x ;
	y = a.y ;
	dx = b.x - a.x ;
	dy = b.y - a.y ;
	xinc = ( dx > 0 ) ? 1 : -1 ;
	yinc = ( dy > 0 ) ? 1 : -1 ;
	dx = abs(dx) ;
	dy = abs(dy) ;
	t_point *p;

	p = malloc(sizeof(t_point));
	//	mlx_pixel_put(val->mlx,val->win,x,y,0x00996600);
	if ( dx > dy ) {
		cumul = dx / 2 ;
		for ( i = 1 ; i <= dx ; i++ ) {
			x += xinc ;
			cumul += dy ;
			if ( cumul >= dx ) 
			{
				cumul -= dx;
				y += yinc; 
			}
			p->x = x;
			p->y = y;
			rotate_point(600,500,p,val);
			if (b.z != 0)
				mlx_pixel_put(val->mlx,val->win,p->x,p->y,0x00CC9999);
			else if (a.z != 0)
				mlx_pixel_put(val->mlx,val->win,p->x,p->y,0x00CC9999);
			else
				mlx_pixel_put(val->mlx,val->win,p->x,p->y,0x00666666);
		} 
	}
	else {
		cumul = dy / 2 ;
		for ( i = 1 ; i <= dy ; i++ ) {
			y += yinc ;
			cumul += dx ;
			if ( cumul >= dy ) {
				cumul -= dy ;
				x += xinc ; 
			}
			p->x = x;
			p->y = y;
			rotate_point(600,500,p,val);
			if (b.z != 0)
				mlx_pixel_put(val->mlx,val->win,p->x,p->y,0x00CC9999);
			else if(a.z != 0)
				mlx_pixel_put(val->mlx,val->win,p->x,p->y,0x00CC9999);
			else
				mlx_pixel_put(val->mlx,val->win,p->x,p->y,0x00666666);
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
