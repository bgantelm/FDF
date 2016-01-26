/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transmo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 10:58:47 by fhenri            #+#    #+#             */
/*   Updated: 2016/01/26 17:43:10 by fhenri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void			ft_remplissage(char **str, t_data *val)
{
	char *tmp;
	int w;

	tmp = ft_strnew(12);
	w  = 0;
	while(str[val->a][val->b] != ' ')
	{
	
		tmp[w] = str[val->a][val->b];
		val->b++;
		w++;
	}
	val->b--;
	tmp[w] = '\0';
	val->grid[val->x][val->y] = ft_atoi(tmp);
	ft_putnbr(val->grid[val->x][val->y]);
	ft_putchar(' ');
	free(tmp);
}

t_data *ft_suite(char **str, t_data *val)
{
	char *tmp;
	int w;

	tmp = ft_strnew(12);
	while (str[val->a] != 0)
	{
		val->b = 0;
		val->y = 0;
		while (str[val->a][val->b] != '\0')
		{
			if (str[val->a][val->b] == ' '
					&& str[val->a][val->b + 1] != '0'
					&& str[val->a][val->b + 2] != ' ' && str[val->a][val->b +2] != '\0')
			{
				val->b++;
				ft_remplissage(str, val);
			}
			else
			{
				if (str[val->a][val->b] == ' ')
					val->b++;
				w = 0;
				tmp[w] = str[val->a][val->b];
				val->grid[val->x][val->y] = ft_atoi(tmp);
				free(tmp);
				tmp = ft_strnew(2);
				ft_putnbr(val->grid[val->x][val->y]);
				ft_putchar(' ');
			} 
			val->y++;
			val->b++;
		}
		ft_putstr("\n");
		val->a++;
		val->x++;
	}
	val = tab_pos(val);
	return(val);
}

t_data		*ft_transmo(char **str)
{
	t_data *val;

	val = malloc(sizeof(t_data));
	val->a = 0;
	val->b = 0;
	val->cte = 1.5;
	val->cte_bis = 0;
	val->droite = 100;
	val->haut = 300;
	val->largeur = 300;
	val->longeur = 150;
	val->rota_droite = 1000;
	val->rota_gauche = 500;
	val->grid = malloc(sizeof(t_data));
	val->grid = (int **)malloc(sizeof(int) *ft_strlen(*str));
	while(str[val->a] != 0)
	{
		val->b = 0;
		while(str[val->a][val->b] != '\0')
			val->b++;
		val->grid[val->a] = (int*)malloc(sizeof(int*) * val->b);
		val->a++;
	}
	val->a = 0;
	return(ft_suite(str,val));
}
