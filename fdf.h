/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 10:59:39 by fhenri            #+#    #+#             */
/*   Updated: 2016/01/25 15:48:48 by fhenri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

# include "libft/libft.h"
# include "mlx.h"
# include <math.h>
# include <stdlib.h>
# include <time.h>
# include <fcntl.h>
# define BUFF_SIZE 4096
# define WIDHT 1000
# define HEIGHT 1000



typedef struct s_poit
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
	int x;
	int y;
	int a;
	int b;
	int		**grid;
	t_point **final;
}			t_data;

int			my_quit(int keycode);
int			touch_rotate(int keycode, t_data *param);
void		rotate_point(int cx, int cy, t_point *p, t_data *val);
t_data		*tab_pos(t_data *val);
t_data      *ft_transmo(char **str);
void		mlx_display(t_data *val);
#endif
