/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 18:40:26 by fhenri            #+#    #+#             */
/*   Updated: 2016/01/16 19:41:38 by fhenri           ###   ########.fr       */
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

int **ft_transmo(char **grid);
void display(int **grid, int x, int  y);
int mlx_display(int **grid, int x, int y);
void ft_line(void *mlx, void *win, int a, int b);
void ft_collone(void *mlx, void *win, int a, int b);
#endif
