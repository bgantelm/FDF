/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 10:59:39 by fhenri            #+#    #+#             */
/*   Updated: 2016/01/27 16:05:54 by fhenri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

# include "libft/libft.h"
# include "mlx.h"
# include "get_next_line/get_next_line.h"
# include <math.h>
# include <stdlib.h>
# include <time.h>
# include <fcntl.h>

typedef struct s_point
{
	int		x;
	int		y;
	int		z;

}				t_point;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			angle;
	int 		droite;
	int			haut;
	int		largeur;
	int		longeur;
	int rota_droite;
	int rota_gauche;
	int x;
	int y;
	int a;
	int b;
	float cte;
	float cte_bis;
	int		**grid;
	t_point **final;
}			t_data;

int			my_quit(int keycode);
int			touch_rotate(int keycode, t_data *param);
void		rotate_point(int cx, int cy, t_point *p, t_data *val);
void		tab_pos(t_data *val);
void		ft_suite(char *str, t_data *val);
void		mlx_display(t_data *val);
#endif
