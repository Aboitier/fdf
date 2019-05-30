/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 19:57:36 by aboitier          #+#    #+#             */
/*   Updated: 2019/05/11 05:43:02 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head.h"

int		draw_line(int x, int y, void *param)
{
	static int	x_coor;
	static int	y_coor;
	static int	call_nb = -1;

	if (++call_nb == 0)
	{
		x_coor = x;
		y_coor = y;
		return (0);
	}

	while (x_coor != x || y_coor != y)
	{
		if (x <= x_coor && x != x_coor)
			x_coor--;
		else if (x >= x_coor && x != x_coor)
			x_coor++;
		if (y <= y_coor && y != y_coor)
			y_coor--;
		else if (y >= y_coor && y != y_coor)
			y_coor++;

		mlx_pixel_put(((void**)param)[0], ((void**)param)[1], x_coor, y_coor, 0xFFFFFF);	
	}
	return (0);
}

