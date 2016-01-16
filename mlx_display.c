/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 14:50:41 by fhenri            #+#    #+#             */
/*   Updated: 2016/01/16 19:41:36 by fhenri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int mlx_display(int **grid, int x, int y)
{
	int a = 0;
	int b = 0;
	int conteur = 0;
	void *mlx;
	void *win;

	mlx = mlx_init();
	win = mlx_new_window(mlx,800,800,"FDF MA GEUL"); // afficher la fennetre10
	while (a < x)
	{
		b = 0;
		while (b < y)
		{
			ft_line(mlx,win,a + conteur,b);
			b++;
		}
		ft_collone(mlx,win,a,b + conteur);
		conteur += 10;
		a++;
	}  
	mlx_loop(mlx);
	return(0);
}

void ft_collone(void *mlx, void *win, int a, int b)
{
	int i = a;
	while (i < a + 40)
	{
			mlx_pixel_put(mlx,win,i,b, 0x00FFFFFF);
		i++;
	}
}

void ft_line(void *mlx, void *win, int a, int b)
{	
	int  i = b;

	while (i < b + 40)
	{
		mlx_pixel_put(mlx,win,a,i, 0x00FF0000);
		i++;
	}

}
