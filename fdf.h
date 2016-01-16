/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 18:40:26 by fhenri            #+#    #+#             */
/*   Updated: 2016/01/16 13:06:11 by fhenri           ###   ########.fr       */
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
void display (int **grid, int x, int  y);
#endif
