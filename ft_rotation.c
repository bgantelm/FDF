/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 20:38:53 by fhenri            #+#    #+#             */
/*   Updated: 2016/01/22 10:58:52 by fhenri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int rotate_point(int x, int y, int angle)
{
	float s = sin(angle);
	float c = cos(angle);
	float cx = 500;
	float cy = 300;
	
	x -= cx;
	y -= cy;

	float xnew = x * c - y * s;
	float ynew = x * s + y * c;

	x = xnew + cx;
	y = ynew + cy;
	return (y);
}
int rotate_point_x (int x, int y, int angle)
{

	float s = sin(angle);
	float c = cos(angle);
	float cx = 500;
	float cy = 300;
	
	x -= cx;
	y -= cy;

	float xnew = x * c - y * s;
	float ynew = x * s + y * c;

	x = xnew + cx;
	y = ynew + cy;
	return (x);
}
