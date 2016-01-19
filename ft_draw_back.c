/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 11:18:57 by fhenri            #+#    #+#             */
/*   Updated: 2016/01/19 17:50:09 by fhenri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void trace_back_line(int x, int y, int x_prime, int y_prime, t_my_mlx env)
{
	int coef = 15;
	int coef_prime = 0;

	if (x < x_prime)
	{
		if (coef_prime == coef && y < y_prime)
		{
			y++;
			coef_prime = 0;
		}
		mlx_pixel_put(env.mlx,env.win,x,y, 0x0066FFFF);
		x++;
		coef_prime++;
	}
}
