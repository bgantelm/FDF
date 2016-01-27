/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 20:38:53 by fhenri            #+#    #+#             */
/*   Updated: 2016/01/27 16:48:31 by fhenri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_point(int cx, int cy, t_point *p, t_data *val)
{
	float s = sin(val->angle);
	float c = cos(val->angle);
	float xnew = 0;
	float ynew = 0;

	p->x -= cx;
	p->y -= cy;
	xnew = p->x * c - p->y * s;
	ynew = p->x * s + p->y * c;
	p->x = xnew + cx;
	p->y = ynew + cy;
}
