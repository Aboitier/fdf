/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 13:20:28 by aboitier          #+#    #+#             */
/*   Updated: 2019/06/01 16:31:01 by aboitier         ###   ########.fr       */
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
	head->project = 0;
	head->theta = 0.0;
	head->phi = 0.0;
	head->psi = 0.0;
	head->x_shift = 0.0;
	head->y_shift = 0.0;
	head->z_shift = 0.0;
	head->focal_dist = 7;
	head->r = 1;
	head->g = 1;
	head->b = 1;
//	if (!(head->points = (t_vertex **)malloc(sizeof(t_vertex *))))
//		return (-1);
	return (0);

}
