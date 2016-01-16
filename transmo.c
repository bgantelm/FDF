/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transmo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 10:25:56 by fhenri            #+#    #+#             */
/*   Updated: 2016/01/16 11:58:09 by fhenri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int **ft_transmo(char **str)
{
	int a;
	int b;
	int **grid;
	a = 0;

	grid =(int**)malloc(sizeof(str) + 1);
	*grid = (int*)malloc(sizeof(*str) + 1);

	while (str[a] != 0)
	{
		b = 0;
		while(str[a][b] != '\n')
		{
			if(str[a][b] == '\n')
			{
	//			grid[a][b] = -1;
	//			a++;
	//			b = 0;
			}
			grid[a][b] = ft_atoi(&str[a][b]);
			b++;
		}
		a++;
	} 
//	grid[a][b] = '-343';
//	display(grid);
	return (0);
}
