/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 18:40:26 by fhenri            #+#    #+#             */
/*   Updated: 2016/01/19 18:47:13 by fhenri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "mlx.h"
# include <stdlib.h>
# include <time.h>
# include <fcntl.h>
# define BUFF_SIZE 4096
# define WIDHT 1000
# define HEIGHT 1000
typedef struct	s_my_mlx
{
	void		*mlx;
	void		*win;
}				t_my_mlx;

typedef struct s_point
{
	int			x;
	int			y;
	int			z;
}				t_point;

typedef struct	s_data
{
	int			x;
	int			y;
	int			a;
	int			b;
	int			conteur;
	int			conteur_bis;
	int**		grid;
	t_point**	tab_final;
}				t_data;

int			ft_affine(int ** grid, t_data val);
int			**ft_transmo(char **grid);
int			my_quit(int keycode, t_my_mlx env);
void		display(int **grid, int x, int  y);
int			mlx_display(t_data val,t_data *test);
t_data 		**tab_pos(t_data val, t_data *test);
void		ft_line(t_my_mlx, int a, int b);
void		mise_en_reliefe(t_my_mlx env, int **grid, t_data val);
void		ft_collone(t_my_mlx env, int a, int b);
void ft_draw_line(int a, int b, t_my_mlx env, t_data *test);
void ft_draw_collone(int a, int b, t_my_mlx env, t_data * test);
void trace_back_line(int x, int y, int x_prime, int y_prime, t_my_mlx env);
#endif
