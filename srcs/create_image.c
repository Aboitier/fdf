/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 18:06:57 by aboitier          #+#    #+#             */
/*   Updated: 2019/05/05 18:41:05 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head.h"

int     create_image(t_fdf *head)
{
	int     bits_per_pixel;
	int     size_line;
	int     endian;

	if (!(head->params[2] = mlx_new_image(head->params[0], WIDTH, HEIGHT)))
		return (-1);
	head->image = mlx_get_data_addr(head->params[2], &bits_per_pixel, &size_line, &endian);
	ft_bzero(head->image, ft_strlen(head->image));
	head->bpp = bits_per_pixel;
	return (0);
}

