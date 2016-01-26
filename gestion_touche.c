/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_touche.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 10:37:27 by fhenri            #+#    #+#             */
/*   Updated: 2016/01/26 17:47:15 by fhenri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int  my_quit(int keycode)
{
	if (keycode == 53)
	{
		exit(0);
	}
	return (1);
}

int touch_rotate(int keycode, t_data *val)
{
	if (keycode == 0)
	{
		mlx_clear_window(val->mlx,val->win);
		val->angle+=1;
		mlx_display(val);
		return(0);
	}
	if(keycode == 1)
	{
		mlx_clear_window(val->mlx,val->win);
		val->angle-=1;
		mlx_display(val);
	}
	if(keycode == 124)
	{
		mlx_clear_window(val->mlx,val->win);
		val->droite +=50;
		val = tab_pos(val);
		mlx_display(val);
	}
	if(keycode == 123)
	{
		mlx_clear_window(val->mlx,val->win);
		val->droite -=50;
		val = tab_pos(val);
		mlx_display(val);
	}
	if(keycode == 126)
	{
		mlx_clear_window(val->mlx,val->win);
		val->haut -=50;
		val = tab_pos(val);
		mlx_display(val);
	}
	if(keycode == 125)
	{
	
		mlx_clear_window(val->mlx,val->win);
		val->haut +=50;
		val = tab_pos(val);
		mlx_display(val);
	}
	if (keycode == 12)
	{
		mlx_clear_window(val->mlx,val->win);
		val->cte +=1;
		val = tab_pos(val);
		mlx_display(val);
	}
	if (keycode == 13)
	{
		mlx_clear_window(val->mlx,val->win);
		val->cte -=1;
		val = tab_pos(val);
		mlx_display(val);
	}

	if (keycode == 18)
	{
		mlx_clear_window(val->mlx,val->win);
		val->largeur -=10;
		val->longeur -=10;
		val = tab_pos(val);
		mlx_display(val);
	}
	if (keycode == 19)
	{
		mlx_clear_window(val->mlx,val->win);
		val->largeur +=10;
		val->longeur +=10;
		val = tab_pos(val);
		mlx_display(val);
	}
	if (keycode == 20)
	{
		mlx_clear_window(val->mlx,val->win);
		val->rota_droite +=100;
		val->cte_bis +=1;
		val = tab_pos(val);
		mlx_display(val);
	}
	if (keycode == 21)
	{
		mlx_clear_window(val->mlx,val->win);
		val->rota_droite -=100;
		val->cte_bis -=1;
		val = tab_pos(val);
		mlx_display(val);
	}
	if (keycode == 22)
	{
		mlx_clear_window(val->mlx,val->win);
		val->rota_gauche +=100;
		val = tab_pos(val);
		mlx_display(val);
	}
	if (keycode == 23)
	{
		mlx_clear_window(val->mlx,val->win);
		val->rota_gauche -=100;
		val = tab_pos(val);
		mlx_display(val);
	}
	if (keycode == 53)
		exit(0);
	ft_putnbr(keycode);
	return(0);
}
