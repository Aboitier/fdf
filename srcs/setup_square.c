/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_square.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 18:55:23 by aboitier          #+#    #+#             */
/*   Updated: 2019/05/17 07:33:18 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head.h"

int     coords_start(t_fdf *head)
{
	int x_center;
	int y_center;

	x_center = WIDTH / 2;
	y_center = HEIGHT / 2;
	head->square_size = sqrt((WIDTH * HEIGHT) / ((head->lines_nb * head->cols_nb) * head->modulator));
	head->square_size = round(head->square_size);

	head->x_start = x_center - ((head->cols_nb / 2) * head->square_size);
	while (head->x_start % head->square_size != 0)
		head->x_start++;
	head->y_start = y_center - ((head->lines_nb / 2) * head->square_size);
	printf("y_start = %d\n", head->y_start);
	while (head->y_start % head->square_size != 0)
		head->y_start++;
	return (0);
}

int     setup_square(t_fdf *head)
{
	if ((head->cols_nb / head->lines_nb) >= 2)
		head->modulator = 7;
	else
		head->modulator = 4;
	coords_start(head);
	//start_square(head);
	//finish_square(head);
	return (0);
}
