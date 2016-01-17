/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 14:50:41 by fhenri            #+#    #+#             */
/*   Updated: 2016/01/17 15:47:51 by fhenri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


int mlx_display(int **grid, int x, int y)
{
	int a = 0;
	int b = 0;
	int conteur = 0;
	int conteur_bis = 0;
	t_my_mlx env;

	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx,1000,1000,"FDF MA GEUL"); // afficher la fennetre10
	while (a <= x)
	{
		b = 0;
		conteur = 0;
		while (b <= y)
		{

			ft_line(env,  conteur_bis,  conteur);
			ft_collone(env,  conteur_bis,  conteur);
			b++;
			if (b <= y)
				conteur += 40;
		}
		conteur_bis += 40;
		a++;
	}
	mise_en_reliefe(env,grid,x,y);

 if (mlx_key_hook(env.win,my_quit, 0) != 0)
	mlx_loop(env.mlx);
	 exit(0);
	return(0);
}

void ft_collone(t_my_mlx env, int a, int b)
{
	int i = 0;
	while (i < a)
	{
		mlx_pixel_put(env.mlx,env.win,b,i, 0x00996600);
		i++;
	}
}

void ft_line(t_my_mlx env, int a, int b)
{	
	int i = 0;

	while (i < b)
	{
		mlx_pixel_put(env.mlx,env.win,i,a, 0x00996600);
		i++;
	}
}

void ft_collone_bleu(t_my_mlx env, int a, int b)
{
	int i = a;
	while (i < a + 40)
	{
		mlx_pixel_put(env.mlx,env.win,b,i, 0x0066FFFF);
		i++;
	}
}

void ft_line_bleu(t_my_mlx env, int a, int b)
{	
	int i = b;

	while (i < b + 40)
	{
		mlx_pixel_put(env.mlx,env.win,i,a,0x0066FFFF);
		i++;
	}
}

void mise_en_reliefe(t_my_mlx env, int **grid, int x, int y)
{
	int a = 0;
	int b = 0;
	int conteur = 0;
	int conteur1 = 0;
	while (a < x)
	{
		b = 0;
		conteur1 = 0;
		while (b < y)
		{
			if (grid[a][b] != 0)
			{	
				ft_line_bleu(env,  conteur,  conteur1);
				ft_collone_bleu(env,  conteur,  conteur1);

				ft_line_bleu(env,  conteur + 40,  conteur1);
				ft_collone_bleu(env,  conteur,  conteur1 + 40);
			}
			conteur1 += 40;
			b++;
		}
		conteur += 40;
		a++;
	}
}
