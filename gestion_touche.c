/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_touche.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 10:37:27 by fhenri            #+#    #+#             */
/*   Updated: 2016/01/26 13:07:44 by fhenri           ###   ########.fr       */
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
	if (keycode == 53)
		exit(0);
	return(0);
}
