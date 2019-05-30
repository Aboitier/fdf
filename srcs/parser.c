/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 21:48:27 by aboitier          #+#    #+#             */
/*   Updated: 2019/05/30 23:54:40 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head.h"

t_vec   *fill_struct_coords(int **data, t_fdf *head)
{
	t_vec   *coords;
	int     y;
	int     x;
	int     index;

	y = -1;
	index = - 1;
	if (!(coords = (t_vec *)malloc(sizeof(t_vec) * (head->nb_tvec))))
		return (NULL);
	while (++y < head->lines_nb)
	{
		x = -1;
		while (++x < head->cols_nb)
		{
			coords[++index].x = x;
			coords[index].y = y;
			coords[index].z = (float)data[y][x];
		}
	}
	return (coords);
}

int		check_line_size(char *line, t_fdf *head)
{
	int i;
	int y_nb;

	i = 0;
	y_nb = 0;
	if (!*line)
		return (-1);
	while (line[i] && (line[i] == ' ' || (line[i] >= '0' && line[i] <= '9')
				|| line[i] == '-'))
	{
		if ((line[i] >= '0' && line[i] <= '9')
				&& !(line[i + 1] >= '0' && line[i + 1] <= '9'))
			y_nb++;
		i++;
	}
	if (head->cols_nb != 0 && head->cols_nb != y_nb)
		return (-1);
	else if (head->cols_nb == 0)
		head->cols_nb = y_nb;
	return (0);
}

int		parse_coords(t_fdf **head, int curr_line, char *line)
{
	int		i;
	int		x;
	char	**pre;

	pre = NULL;
	x = -1;
	i = -1;
	if (!((*head)->parse_p[curr_line] = (int *)malloc(sizeof(int)
					* ((*head)->cols_nb + 1))))
		return (-1);
	(*head)->parse_p[(*head)->cols_nb] = NULL;
	pre = ft_strsplit(line, ' ');
	while (pre[++i] && x < (*head)->cols_nb)
		(*head)->parse_p[curr_line][++x] = ft_atoi(pre[i]);
	free(pre);
	return (0);
}

int		post_parser(t_fdf *head)
{
	int i;
	int curr_line;

	curr_line = 0;
	i = 0;
	if (!(head->parse_p = (int **)malloc(sizeof(int*) * (head->lines_nb + 1))))
		return (-1);
	while (head->line[i])
	{
		if (parse_coords(&head, curr_line, head->line + i) != 0)
			return (-1);
		curr_line++;
		i += get_numbers(head->line + i, head->cols_nb);
	}
	head->nb_tvec = head->cols_nb * head->lines_nb;
	return (0);
}

int		parser(int fd, t_fdf *head)
{
	char	*line;
	int		nb_lines;

	nb_lines = 0;
	while (get_next_line(fd, &line) == 1)
	{
		if ((check_line_size(line, head) == 0))
		{
			if (!head->line)
				head->line = ft_strdup(line);
			else
				head->line = ft_strjoin(head->line, line);
			head->line = ft_addonechar(&(head->line), ' ');
			nb_lines++;
		}
		else
			return (-1);
	}
	free(line);
	head->lines_nb = nb_lines;
	if (post_parser(head) != 0)
		return (-1);
	return (0);
}
