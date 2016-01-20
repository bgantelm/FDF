/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 14:50:41 by fhenri            #+#    #+#             */
/*   Updated: 2016/01/20 14:20:16 by fhenri           ###   ########.fr       */
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
	double  x_prime;
	double y_prime;
	double x;
	double coef;
	int coef_prime =0;
	double y;


	y_prime = test->tab_final[a][b + 1].y;
	x_prime =test->tab_final[a][b + 1].x;
	x = test->tab_final[a][b].x;
	y = test->tab_final[a][b].y;
	coef = 14;
//	if (test->tab_final[a][b].z != 0)
//	{

//	coef = (x_prime - x )/ test->tab_final[a][b].z;
//	ft_putnbr(coef);
		/*
	ft_putstr("x_prime = ");
	ft_putnbr((x_prime));
	ft_putstr("  y_prime =");
	ft_putnbr((y_prime));
	ft_putstr("  x =");
	ft_putnbr((x));
	ft_putstr("  y =");
	ft_putnbr((y));
	ft_putstr("  z =");
	ft_putnbr((test->tab_final[a][b].z));
	*/
//	ft_putstr("\n"); 
//	}
	if (test->tab_final[a][b+1].z != 0 && test->tab_final[a][b].z != test->tab_final[a][b + 1].z)
	{
		while (x < x_prime)
		{
			if (coef_prime == coef && y > y_prime)
			{
				y--;
				coef_prime = 0;
			}
			if (test->tab_final[a][b].z != 0 || test->tab_final[a][b + 1].z != 0)
			{
				mlx_pixel_put(env.mlx,env.win,x,y, 0x0066FFFF);
			}
			else
				mlx_pixel_put(env.mlx,env.win,x,y,0x00996600);
			x++;
			coef_prime++;
		}
	}
	else
	{
		while (x < x_prime)
		{
			if (coef_prime == coef && y < y_prime)
			{
				y++;
				coef_prime = 0;
			}
			if (test->tab_final[a][b].z != 0 || test->tab_final[a][b + 1].z != 0)
			{
				mlx_pixel_put(env.mlx,env.win,x,y, 0x0066FFFF);
			}
			else
				mlx_pixel_put(env.mlx,env.win,x,y,0x00996600);
			x++;
			coef_prime++;
		}
	}
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
//	coef = (y_prime - y )/ test->tab_final[a][b].z;
//	if (coef < 0)
		coef = 16;
	if (test->tab_final[a + 1][b].z != 0 && test->tab_final[a][b].z != test->tab_final[a + 1][b].z)
	{


		while (y < y_prime)
		{
			if (coef_prime == coef && x > x_prime)
			{
				x--;
				coef_prime = 0;
			}
			if (test->tab_final[a][b].z != 0 || test->tab_final[a + 1][b].z != 0)
			{
				mlx_pixel_put(env.mlx,env.win,x,y, 0x0066FFFF);
			}
			else
				mlx_pixel_put(env.mlx,env.win,x,y,0x00996600);
			y++;
			coef_prime++;
		}
	}
	else
	{
		while (y < y_prime)
		{
			if (coef_prime == coef && x < x_prime)
			{
				x++;
				coef_prime = 0;
			}
			if (test->tab_final[a][b].z != 0 || test->tab_final[a + 1][b].z != 0)
			{
				mlx_pixel_put(env.mlx,env.win,x,y, 0x0066FFFF);
			}
			else
				mlx_pixel_put(env.mlx,env.win,x,y,0x00996600);
			y++;
			coef_prime++;
		}
	}
}
