/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 20:24:43 by aboitier          #+#    #+#             */
/*   Updated: 2019/05/21 23:31:47 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcg.h"

/* The cross product is also an operation on two vectors, but to the difference of the dot product which returns a number, the cross product returns a vector. The particularity of this operation is that the vector resulting from the cross product is perpendicular to the other two. 
 * In mathematics, the result of a cross product is called a pseudo vector. The order of the vector in the cross product operation is important when surface normals are computed from the tangent and bitangent at the point where the normal is computed. Depending on this order, the resulting normal can either be pointing towards the interior of the surface (inward-pointing normal) or away from it (outward-pointing normal). */

t_vec	*vec_cross(t_vec *va, t_vec *vb)
{
	t_vec *v_new;
	
	if (!(v_new = (t_vec *)malloc(sizeof(t_vec))))
		return (NULL);
	v_new->x = va->y * vb->z - va->z - vb->y;
	v_new->y = va->z * vb->x - va->x * vb->z;
	v_new->z = va->x * vb->y - va->y * vb->x;

	return (v_new);
}

/* The dot product or scalar product requires two vectors A and B and can be seen as the projection of one vector onto the other. 
 * The dot product between two vectors is an extremely important and common operation in any 3D application because the result of this operation relates to the cosine of the angle between the two vectors.
 * The dot product is a very important operation in 3D. It can be used for many things. As a test of orthogonality. When two vectors are perpendicular to each other (A.B), the result of the dot product between these two vectors is 0. 
* When the two vectors are pointing in opposite directions (A.C), the dot product returns -1. When they are pointing in the exact same direction (A.D), it returns 1.*/

void	vec_dot(t_vec *va, t_vec *vb)
{
	return (va->x * vb->x + va->y * vb->y + va->z * vb->z);
}

/* A normalised vector, is a vector whose length is 1. Such a vector is also called a unit vector (it is a vector which has unit length). */

void    vec_normalize(t_vec *v)
{
	float   inv_len;
	float   v_len;

	v_len = vec_length(v);
	if (v_len > 0)
	{
		inv_len = 1 / v_len;
		v->x *= inv_len;
		v->y *= inv_len;
		v->z *= inv_len;
	}
}

void    vec_length(t_vec *v)
{
	return (sqrt(v->x * v->x + v->y * v->y + v->z * v->z));
}
