/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transmo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 10:25:56 by fhenri            #+#    #+#             */
/*   Updated: 2016/01/16 19:41:40 by fhenri           ###   ########.fr       */
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
	grid = (int**)malloc(sizeof(int) *ft_strlen(*str));
	while (str[a] != 0)
	{
		b = 0;
		while(str[a][b] != '\0')
			b++;
		grid[a] = (int*)malloc(sizeof(int*) * b);
		a++;
	}
	a = 0;
	while (str[a] != 0)
	{
		b = 0;
		y = 0;
		while (str[a][b] != '\0')
		{
			if (str[a][b] == ' ' && str[a][b + 2] != '\0' && str[a][b + 2] != ' ')
			{
					b++;
					w = 0;
					while(str[a][b] != '\0' && str[a][b] != ' ')
					{
						tmp[w] = str[a][b];
						b++;
						w++;
					}
					grid[x][y] = ft_atoi(tmp);
					free(tmp);
					tmp = ft_strnew(12);
					ft_putnbr(grid[x][y]);
					ft_putchar('K');
			}
			else
			{
				w = 0;
				tmp[w] = str[a][b];
				grid[x][y] = ft_atoi(tmp);
				free(tmp);
				tmp = ft_strnew(12);
				ft_putnbr(grid[x][y]);
				ft_putchar(' ');
				b++;
			}
			y++;
			b++;
		}
		ft_putstr("\n");
		a++;
		x++;
	}
	mlx_display(grid,x,y);
	return (0);
}
