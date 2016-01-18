/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 14:50:41 by fhenri            #+#    #+#             */
/*   Updated: 2016/01/18 17:49:12 by fhenri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int mlx_display(t_data val, t_data *test)
{
	int a = 0;
	int b = 0;

	t_my_mlx env;
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx,1400,850,"FDF MA GEUL");

	while (a < val.x)
	{
		b = 0;
		while (b < val.y)
		{
			ft_draw_line(a,b,env, test);
			if (a + 1 < val.x)
				ft_draw_collone(a,b,env,test);
			b++;
		}
		a++; 
	}
	if (mlx_key_hook(env.win,my_quit, 0) != 0)
		mlx_loop(env.mlx);
	exit(0);
	return(0);
}

void ft_draw_line(int a, int b, t_my_mlx env, t_data *test)
{
	int x_prime;
	int y_prime;
	int x;
	int coef;
	int coef_prime =0;
	int y;


	x_prime =test->tab_final[a][b + 1].x;
	y_prime =test->tab_final[a][b + 1].y;
	x = test->tab_final[a][b].x;
	y = test->tab_final[a][b].y;
	//	coef =(y_prime / y);
	coef = 15;
	//	ft_putnbr(coef);
	//	ft_putstr("\n:::");
	if (x < x_prime)
	{
		while (x < x_prime)
		{
			if (coef_prime == coef && y < y_prime)
			{
				y++;
				coef_prime = 0;
			}
			if (test->tab_final[a][b].z != 0)
			{
				mlx_pixel_put(env.mlx,env.win,x,y, 0x0066FFFF);

			}
			else
				mlx_pixel_put(env.mlx,env.win,x,y,0x00996600);
			x++;
			coef_prime++;
		}
	}
	/*
	else
	{
		while (x_prime < x)
		{
			if (coef_prime == coef && y < y_prime)
			{
				y++;
				coef_prime = 0;
			}
			if (test->tab_final[a][b].z != 0)
			{
				mlx_pixel_put(env.mlx,env.win,x,y, 0x0066FFFF);

			}
			else
				mlx_pixel_put(env.mlx,env.win,x,y,0x00996600);
			x--;
			coef_prime++;
		}
	} 
	*/
}

void ft_draw_collone(int a, int b, t_my_mlx env, t_data * test)
{
	int x_prime;
	int y_prime;
	int coef;
	int coef_prime = 0;
	int x;
	int y;


	x_prime =test->tab_final[a + 1][b].x;
	y_prime =test->tab_final[a + 1][b].y;
	x = test->tab_final[a][b].x;
	y = test->tab_final[a][b].y;
	coef = (x_prime / x);
	coef = 15;
	if (y < y_prime)
	{
		while (y < y_prime)
		{
			if (coef_prime == coef && x < x_prime)
			{
				x++;
				coef_prime = 0;
			}
			if (test->tab_final[a][b].z != 0)
			{
				if (test->tab_final[a][b - 1].z != 0)
					trace_back_line(test->tab[a-1][b], test->tab[a - 1][b], x, y, env)
				mlx_pixel_put(env.mlx,env.win,x,y, 0x0066FFFF);
			}
			else
				mlx_pixel_put(env.mlx,env.win,x,y,0x00996600);
			y++;
			coef_prime++;
		}
	}
	/*
	else
	{
		while (y_prime < y)
		{
			if (coef_prime == coef && x < x_prime)
			{
				x++;
				coef_prime = 0;
			}
			if (test->tab_final[a][b].z != 0)
				mlx_pixel_put(env.mlx,env.win,x,y, 0x0066FFFF);
			else
				mlx_pixel_put(env.mlx,env.win,x,y,0x00996600);
			y--;
			coef_prime++;
		}
	} */
}
void track_back_line(int a, int b, env, t_data *test)
{	
	
}
