/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 18:39:12 by fhenri            #+#    #+#             */
/*   Updated: 2016/01/26 15:43:45 by fhenri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//-lmlx -framework OpenGL -framework AppKit
int error()
{
	ft_putendl("error");
	return(0);
}
int ft_rong_map (char *str)
{
	int a = 0;
	while (str[a])
	{
		if (ft_isdigit(str[a]) != 1 && str[a] != '-' && str[a] != ' ' && str[a] != '\n')
		{
			error();
			return (1);
		}
		
		a++;
	}
	return(0);
 }
static int ft_display(char *name, t_data *val)
{

	val->angle = 0;
	val->mlx = mlx_init();
	val->win = mlx_new_window(val->mlx,1400,850,name);
	mlx_display(val);
	mlx_key_hook(val->win, touch_rotate, val);
	mlx_loop(val->mlx);

	return (0);
}

int main (int argc, char **argv)
{

	int		file;
	char	*buf;
	int		index;
	char	**grid;
	t_data *val;

	if (argc != 2)
		return (error());
	buf = malloc(sizeof(char) * BUFF_SIZE);
	file = open(argv[1], O_RDONLY);
	index = read(file, buf, BUFF_SIZE);
	buf[index] = '\0';
	close(file);
	if (file == -1)
		return (error());
//	if (ft_rong_map (buf) != 0)
//		return (0);
	grid = ft_strsplit(buf,'\n');
	val = ft_transmo(grid);
	return (ft_display(argv[1],val));
} 
