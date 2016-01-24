/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_touch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 10:27:15 by fhenri            #+#    #+#             */
/*   Updated: 2016/01/21 15:02:31 by fhenri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int my_quit(int keycode, t_my_mlx env)
{
	if (keycode == 53)
	{
		//		mlx_clear_window(env.mlx,env.win);
		mlx_destroy_window(env.mlx,env.win);
		exit(0);
	}
	return (1);
}

int touch_rotate(int keycode)
{
	static int		angle = 0;

	if (keycode == 0)
	{
		ft_putstr("HELLO");
		if (angle < 360);
		else
			angle = 0;
	}
	/*	if (keycode == 0)
		{
		env.angle += 10;
		}
		ft_putnbr(keycode);
		*/	ft_putstr("\n");
	return (100);
}
