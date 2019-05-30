/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 13:20:28 by aboitier          #+#    #+#             */
/*   Updated: 2019/05/31 00:25:54 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head.h"

//int		init_data(t_point *data)
//{
//	if (!(data
//	
//	return (0);
//}

int     init_head(t_fdf *head)
{
	if (!(head->params = (void**)malloc(sizeof(void *) * 3)))
		return (-1);
	if (!(head->params[0] = mlx_init()))
		return (-1);
	if (!(head->params[1] = mlx_new_window(head->params[0], WIDTH, HEIGHT, "test")))
		return (-1);
	head->cols_nb = 0;
	head->line = NULL;
	head->x_scale = 1;
	head->y_scale = 1;
	head->z_scale = 1;
	if (!(head->points = (t_vertex *)malloc(sizeof(t_vertex))))
		return (-1);
	return (0);

}
