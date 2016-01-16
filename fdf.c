/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 18:39:12 by fhenri            #+#    #+#             */
/*   Updated: 2016/01/16 11:59:11 by fhenri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <time.h>
#include <stdio.h>

//-lmlx -framework OpenGL -framework AppKit
int error()
{
	ft_putendl("error");
	return(0);
}
/*
int main (int argc, char **argv)
 
  {
  int a = 0;
  void *mlx;
  void *win;
  char *buf;
  int x = 0;
  int y = 0;

  buf = malloc(sizeof(char)* 10);
  mlx = mlx_init();
  win = mlx_new_window(mlx,800,800,"test"); // afficher la fennetre
  while (a < 100)
  {
  mlx_pixel_put(mlx,win, x, y,0x00FFFFFF);// affficher un pixel
//	sleep(1);	
x++;
if (x == 400)
x = 0;
if (y == 400)
y = 0;
y++;
}
mlx_loop(mlx); //gestion d'evenement
return (0);
} 
*/

void display (int **grid)
{
	int a = 0;
	int b;

	while (grid[a][b] != -343)
	{
		b = 0;
		while(grid[a][b] != -1)
		{
			ft_putnbr(grid[a][b]);
			b++;
		}
		a++;
	}
}
int main (int argc, char **argv)
{
	
		int		file;
		char	buf[BUFF_SIZE];
		int		index;
		char	**grid;

		if (argc != 2)
			return (error());
		file = open(argv[1], O_RDONLY);
		index = read(file, buf, BUFF_SIZE);
		buf[index] = '\0';
		close(file);
		if (file == -1)
			return (error());
		grid = ft_strsplit(buf,'\n');
		ft_putstr(grid[4]);
		//ft_transmo(grid);
		return (0);
}
