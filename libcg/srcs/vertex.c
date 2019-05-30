/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 21:46:45 by aboitier          #+#    #+#             */
/*   Updated: 2019/05/30 21:59:10 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libcg.h"

t_vec		*get_t_vec(float x, float y, float z)
{
	t_vec 	*new;

	if (!(new = (t_vec *)malloc(sizeof(t_vec))))
		return (NULL);
	new->x = x;
	new->y = y;
	new->z = z;
	return (new);
}

t_vertex	*get_vertex(float x, float y, float z)
{
	t_vertex *new;

	if (!(new = (t_vertex *)malloc(sizeof(t_vertex))))
		return (NULL);
	new->local = get_t_vec(x, y, z);
	new->world = get_t_vec(0, 0, 0);
	new->aligned = get_t_vec(0, 0, 0);
	new->projected = get_t_vec(0, 0, 0);
	new->color = z;
	return (new);
}
