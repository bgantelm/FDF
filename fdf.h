/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 18:40:26 by fhenri            #+#    #+#             */
/*   Updated: 2016/01/17 17:30:31 by fhenri           ###   ########.fr       */
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

typedef struct s_my_mlx
{
	void *mlx;
	void *win;
}			t_my_mlx;

typedef struct s_data
{
	int x;
	int y;
	int a;
	int b;
}				 t_data;

void ft_line_bleu(t_my_mlx env, int a, int b);
void ft_collone_bleu(t_my_mlx env, int a, int b);
int ft_affine(int ** grid, t_data val);
int **ft_transmo(char **grid);
int my_quit(int keycode, t_my_mlx env);
void display(int **grid, int x, int  y);
int mlx_display(int **grid, t_data val);
void ft_line(t_my_mlx, int a, int b);
void mise_en_reliefe(t_my_mlx env, int **grid, t_data val);
void ft_collone(t_my_mlx env, int a, int b);
#endif
