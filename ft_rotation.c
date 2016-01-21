/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 20:38:53 by fhenri            #+#    #+#             */
/*   Updated: 2016/01/21 10:23:57 by fhenri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
# define ANGLE -100
int rotate_point(int x, int y)
{
	float s = sin(ANGLE);
	float c = cos(ANGLE);
	float cx = 0;
	float cy = 0;
	
	x -= cx;
	y -= cy;

	float xnew = x * c - y * s;
	float ynew = x * s + y * c;

	x = xnew + cx;
	y = ynew + cy;
	return (y);
}
int rotate_point_x (int x, int y)
{

	float s = sin(ANGLE);
	float c = cos(ANGLE);
	float cx = 0;
	float cy = 0;
	
	x -= cx;
	y -= cy;

	float xnew = x * c - y * s;
	float ynew = x * s + y * c;

	x = xnew + cx;
	y = ynew + cy;
	return (x);
}
