/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 20:07:54 by aboitier          #+#    #+#             */
/*   Updated: 2019/05/11 04:47:56 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	fill_pixel(t_fdf *head, int x, int y, int color)
{
	int				pixel;
	int				pix_start;

	pix_start = head->x_start * 4 + 4 * WIDTH * y_start;
	
	while (pix_start <
	pixel = 0;	
	while (x <= 800)
	{
		pixel = x * 4 + 4 * WIDTH * y;
		head->image[pixel + 0] = color >> 16 & 255;
		head->image[pixel + 1] = color >> 8 & 255;
		head->image[pixel + 2] = color & 255;
		head->image[pixel + 3] = 0;
		x++;
	}
	//	printf("color = %d\n", color);
	//	printf("pixel = %d\n", pixel);
	//	printf("%d\n", head->image[pixel]);
	//	printf("%d\n", head->image[pixel + 1]);
	//	printf("%d\n", head->image[pixel + 2]);
	//	printf("%d\n", head->image[pixel + 3]);
}
