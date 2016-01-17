/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transmo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 10:25:56 by fhenri            #+#    #+#             */
/*   Updated: 2016/01/17 16:22:16 by fhenri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int **ft_transmo(char **str)
{
	t_data val;
	int w = 0;
	int **grid;
	char *tmp;
	
	val.a = 0;
	val.x = 0;
	tmp = ft_strnew(12);
	grid = (int**)malloc(sizeof(int) *ft_strlen(*str));
	while (str[val.a] != 0)
	{
		val.b = 0;
		while(str[val.a][val.b] != '\0')
			val.b++;
		grid[val.a] = (int*)malloc(sizeof(int*) * val.b);
		val.a++;
	}
	val.a = 0;
	while (str[val.a] != 0)
	{
		val.b = 0;
		val.y = 0;
		while (str[val.a][val.b] != '\0')
		{
			if (str[val.a][val.b] == ' ' && str[val.a][val.b + 2] != '\0' && str[val.a][val.b + 2] != ' ')
			{
					val.b++;
					w = 0;
					while(str[val.a][val.b] != '\0' && str[val.a][val.b] != ' ')
					{
						tmp[w] = str[val.a][val.b];
						val.b++;
						w++;
					}
					grid[val.x][val.y] = ft_atoi(tmp);
					free(tmp);
					tmp = ft_strnew(12);
					ft_putnbr(grid[val.x][val.y]);
					ft_putchar('K');
			}
			else
			{
				w = 0;
				tmp[w] = str[val.a][val.b];
				grid[val.x][val.y] = ft_atoi(tmp);
				free(tmp);
				tmp = ft_strnew(12);
				ft_putnbr(grid[val.x][val.y]);
				ft_putchar(' ');
				val.b++;
			}
			val.y++;
			val.b++;
		}
		ft_putstr("\n");
		val.a++;
		val.x++;
	}
	mlx_display(grid,val);
	return (0);
}
