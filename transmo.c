/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transmo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 10:25:56 by fhenri            #+#    #+#             */
/*   Updated: 2016/01/16 14:47:25 by fhenri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int **ft_transmo(char **str)
{
	int a = 0;
	int b = 0;
	int x = 0;
	int y = 0;
	int w = 0;
	int **grid;
	char *tmp;
	a = 0;

	tmp = ft_strnew(12);
	grid = (int**)malloc(sizeof(str));
	while(str[a])
	{
		grid[a] = (int*)malloc(sizeof(*str));
		a++;
	}
	a = 0;
	while(str[a])
	{
		b = 0;
		y = 0;
		while (str[a][b])
		{
			if (str[a][b] == ' ' && str[a][b + 2] != '\0')
			{
				if(str[a][b + 2] != ' ')
				{
					b++;
					w = 0;
					while(str[a][b] != ' ' && str[a][b] != '\0')
					{
						tmp[w] = str[a][b];
						b++;
						w++;
					}
					grid[x][y] = ft_atoi(tmp);
					tmp = NULL;
					tmp = ft_strnew(12);
					ft_putnbr(grid[x][y]);
					ft_putchar(' ');
				}
			}
			else
			{
				w = 0;
				tmp[w] = str[a][b];
				grid[x][y] = ft_atoi(tmp);
				ft_putnbr(grid[x][y]);
				ft_putchar(' ');
			}
			y++;
			b++;
		}
		ft_putstr("\n");
		a++;
		x++;
	}
	//	display(grid,x,y);
	return (0);
}
