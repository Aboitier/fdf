/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 16:12:11 by aboitier          #+#    #+#             */
/*   Updated: 2019/05/31 20:05:53 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int		deal_key(int key, void *params)
{
	if (key == 53)
		exit (1);
	int x_pix = 50;
	int y_pix = 50;
	while (x_pix++ < 200 && y_pix++ < 200)
		mlx_pixel_put(((void**)params)[0], ((void**)params)[1], x_pix, y_pix, 0xffffff);	
	return (0);
}

int		exit_key(void)
{
	exit (1);
	return (0);
}

//int		mouse_move(int x, int y, void *param)
//{
//	mlx_pixel_put(((void**)param)[0], ((void**)param)[1], x, y, 0xFFFFFF);
//	draw_good_line(x, y, );	
//	printf("\tx = %d\n", x);		
//	printf("y = %d\n", y);	
//	return (0);
//}

int		mouse_press(int button, int x, int y, void *params)
{

	//	mlx_loop_hook(((void**)param)[0], mouse_move, param);
	mlx_pixel_put(((void**)params)[0], ((void**)params)[1], x, y, 0xFFFFFF);
	//	mlx_hook(((void**)param)[0], 6, 0, mouse_move, param);
	//	if (x == DESTROYNOTIFY)
	//		exit (1);

	//	draw_line(x, y, params);	
	//	printf("button = %d\n", button);
	button = 1;
	printf("x = %d\n", x);
	printf("y = %d\n\n", y);


	//	mlx_pixel_put(((void**)param)[0], ((void**)param)[1], 400, 400, 0xFFFFFF);

	return (0);
}

//void	line(t_point *data, void *params)
//{
//	//	int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
//	//	int dy = abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
//	int err = (data->dx > data->dy ? data->dx : -data->dy)/2;
//	int e2;
//
//	while (1)
//	{
//		mlx_pixel_put(((void**)params)[0],((void**)params)[1], data->x2, data->y2, 0xFFFFFF);
//		if (data->x2 == data->x3 && data->y2 == data->y3)
//			break ;
//		e2 = err;
//		if (e2 > -data->dx)
//		{
//			err -= data->dy;
//			data->x2 += data->sx;
//		}
//		if (e2 < data->dy)
//		{
//			err += data->dx;
//			data->y2 += data->sy;
//		}
//	}
//}

//void	draw(t_vec *coords, t_fdf *head)
//{
//	int x;
//
//	x = -1;
//	while (coords[++x])
//	{
//		if (x + 1 < head->nb_tvec && coords[x + 1]->z == 0)
//			line_between(coords[x], coords[x + 1], head);
//		if (x + head->cols_nb < head->nb_tvec && (coords[x + head->cols_nb]->z == 0))
//			line_between(coords[x], coords[x + head->cols_nb], head);
//		if (
//	
//	}
//	
//}

void	local_to_world(t_fdf *head)
{
	float	global[4][4];
	int		x;
	int		y;

	get_id_matrix(global);
	mat_translate(global, -(head->lines_nb / 2), -(head->cols_nb / 2), 0);
	mat_scale(global, head->x_scale, head->y_scale, head->z_scale);
	y = -1;
	while (++y < head->lines_nb)
	{
		x = -1;
		while (++x < head->cols_nb)
			mult_vec_matrix(head->points[y][x]->local, global, head->points[y][x]->world);
	}
}

void	world_to_aligned(t_fdf *head)
{
	float	global[4][4];
	int		x;
	int		y;

	get_id_matrix(global);
	mat_rotate(global, head->theta, head->phi, head->psi);
	mat_scale(global, (WIN_WIDTH * head->scale) / head->cols_nb,
			(WIN_HEIGHT * head->scale) / head->lines_nb, head->scale);
	mat_translate(global, (

int		main(int ac, char **av)
{
	t_fdf	head;
	int 	fd;	

	if (ac != 2 || ((fd = open(av[1], O_RDONLY)) == -1))
		return (-1);
	init_head(&head);
	create_image(&head);
	if ((parser(fd, &head) == -1))
	{	
		ft_putstr("Error in file.\n");
		return (-1);
	}
	fill_struct_coords(head.parse_p, &head);
//	printf("x_start = %d\ty_start = %d\n", head.x_start, head.y_start);
	printf("cols_nb = %d\tlines_nb = %d\n\n", head.cols_nb, head.lines_nb);
	local_to_world(&head);
	printf("hello\n");

	//	mlx_put_image_to_window(head.params[0], head.params[1], head.params[2], 0, 0);

	//	mlx_pixel_put(mlx_ptr, win_ptr, x_start, y_start, 0xFF0000);


	mlx_key_hook(head.params[1], deal_key, head.params);
	mlx_hook(head.params[1], 4, 0, mouse_press, head.params);
	mlx_hook(head.params[1], 17, 0, exit_key, head.params);
	//	mlx_hook(win_ptr, 6, 0, mouse_move, param);
	mlx_loop(head.params[0]);

	return (0);
}
