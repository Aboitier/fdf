/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libcg.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 17:14:40 by aboitier          #+#    #+#             */
/*   Updated: 2019/05/30 21:56:58 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBCG_H
# define LIBCG_H

# include <math.h>
# include <mlx.h>
# include "libft/libft.h"
# include <string.h>
# include <stdlib.h>

typedef struct	s_vec
{
	float	x;
	float	y;
	float	z;
}				t_vec;

typedef struct	s_vertex
{
	t_vec	*local;
	t_vec	*world;
	t_vec	*aligned;
	t_vec	*projected;
	int		color;
}				t_vertex;

void			mat_bzero(float mat[4][4]);
void			get_id_matrix(float mat[4][4]);
void			mat_mult(float m1[4][4], float m2[4][4], float dst[4][4]);
void			mat_translate(float mat[4][4], float x, float y, float z);
void			mat_scale(float mat[4][4], float x, float y, float z);
void			mat_rotx(float mat[4][4], float theta);
void			mat_roty(float mat[4][4], float phi);
void			mat_rotz(float mat[4][4], float psi);
void			mult_vec_matrix(t_vec *src, float mat[4][4], t_vec *dst);
void			vec_dot(t_vec *va, t_vec *vb);
void			vec_normalize(t_vec *v);
void			vec_length(t_vec *v);

#endif 
