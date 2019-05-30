/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 18:21:27 by aboitier          #+#    #+#             */
/*   Updated: 2019/05/30 18:46:27 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "utils/X.h"
# include "mlx.h"
# include "libcg/libcg.h"
# include "libft/libft.h"

# define WIDTH 1600
# define HEIGHT 1200

typedef struct			s_point
{
	int 				x0;
	int					y0;
	int					x1;
	int 				y1;
	int					dx;
	int					dy;
	int					sx;
	int					sy;
	t_vec				*points;
	struct s_point		*next;
}						t_point;

typedef struct 	s_fdf
{
	void		**params;
	char		*image;
	char		*line;
	int			**points;
	int		square_size;
	int			cols_nb;
	int			lines_nb;
	int			nb_tvec;
	int			modulator;
	int			bpp;
}				t_fdf;

int				init_head(t_fdf *head);
int				create_image(t_fdf *head);

/***********
 *  PARSER *
 ***********/

int		parser(int fd, t_fdf *head);
int		check_line_size(char *line, t_fdf *head);
int		parse_coords(t_fdf **head, int curr_line, char *line);
int		post_parser(t_fdf *head);
t_vec	*fill_struct_coords(int **data, t_fdf *head);

/************
 *  DRAWING *
 ************/

int				setup_square(t_fdf *head);
int				coords_start(t_fdf *head); 

int				draw_line(int x, int y, void *param);
void			fill_pixel(t_fdf *head, int x, int y, int color);



#endif 