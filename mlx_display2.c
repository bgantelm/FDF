/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 14:50:41 by fhenri            #+#    #+#             */
/*   Updated: 2016/01/17 18:06:46 by fhenri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


int mlx_display(int **grid, t_data val)
{
	int conteur = 0;
	int conteur_bis = 0;
	t_my_mlx env;

	val.a = 0;
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx,1000,1000,"FDF MA GEUL"); // afficher la fennetre10

	//	ft_affine(grid,val);
	while (val.a <= val.x)
	{
		val.b = 0;
		conteur = 0;
		while (val.b <= val.y)
		{

			if( val.a < val.x && val.b < val.y && grid[val.a][val.b] != 0)
			{
				ft_line_bleu(env,  conteur_bis,  conteur);
				ft_collone_bleu(env,  conteur_bis,  conteur);
			}
			else
			{
				ft_line(env,  conteur_bis,  conteur);
				ft_collone(env,  conteur_bis,  conteur);
			}
			val.b++;
			if (val.b <= val.y)
				conteur += 40;
		}

		conteur_bis += 40;
		val.a++;
	}
	//	mise_en_reliefe(env,grid, val);
	if (mlx_key_hook(env.win,my_quit, 0) != 0)
		mlx_loop(env.mlx);
	exit(0);
	return(0);
}

void ft_collone(t_my_mlx env, int a, int b)
{
	int i = a;
	while (i < a + 40)
	{
		mlx_pixel_put(env.mlx,env.win,b,i, 0x00996600);
		i++;
	}
}

void ft_line(t_my_mlx env, int a, int b)
{	
	int i = b;
	while (i < b + 40 )
	{
		mlx_pixel_put(env.mlx,env.win,i,a, 0x00996600);
		i++;
	}
}

void ft_collone_bleu(t_my_mlx env, int a, int b)
{
	int i = a;
	int y = a;
	while (i < a + 40)
	{
		y = y + 0.5 * 5;
		mlx_pixel_put(env.mlx,env.win,b,y, 0x0066FFFF);
		i++;
		b--;
	}
}

void ft_line_bleu(t_my_mlx env, int a, int b)
{	
	int x = b;
	int i = b;
	int cst = 1;
	while (i < b + 40)
	{
		x = x + 1 * 5;
		mlx_pixel_put(env.mlx,env.win,i,x,0x0066FFFF);
		i++;
		a++;
	}
}

void mise_en_reliefe(t_my_mlx env, int **grid, t_data val)
{
	int conteur = 0;
	int conteur1 = 0;
	val.a = 0;
	val.b = 0;
	while (val.a < val.x)
	{
		val.b = 0;
		conteur1 = 0;
		while (val.b < val.y)
		{
			if (grid[val.a][val.b] != 0)
			{	
				ft_line_bleu(env,  conteur,  conteur1);
				ft_collone_bleu(env,  conteur,  conteur1);

								ft_line_bleu(env,  conteur + 40,  conteur1);
					ft_collone_bleu(env,  conteur,  conteur1 + 40);
			}
			conteur1 += 40;
			val.b++;
		}
		conteur += 40;
		val.a++;
	}
}
