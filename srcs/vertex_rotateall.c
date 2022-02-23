/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex_rotateall.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkanzaki <tkanzaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 23:28:01 by tkrm              #+#    #+#             */
/*   Updated: 2022/02/23 10:20:57 by tkanzaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vertex.h"

static void		rotate(t_vertex *index,
				const t_vector3 *rotation);
static double	get_radian(const double angle);

void	vertex_rotateall(t_vertex *model_vertexes,
	const t_vector3 *rotation, const t_vector3 *pivot)
{
	t_vertex		*index;

	index = model_vertexes;
	while (true)
	{
		index->position.x -= pivot->x;
		index->position.y -= pivot->y;
		index->position.z -= pivot->z;
		rotate(index, rotation);
		index->position.x += pivot->x;
		index->position.y += pivot->y;
		index->position.z += pivot->z;
		index = index->next;
		if (index == index->head)
			break ;
	}
}

static void	rotate(t_vertex *index,
	const t_vector3 *rotation)
{
	vertex_rotate(&(index->position.z), &(index->position.y), get_radian(rotation->x));
	vertex_rotate(&(index->position.x), &(index->position.z), get_radian(rotation->y));
	vertex_rotate(&(index->position.x), &(index->position.y), get_radian(rotation->z));
}

static double	get_radian(const double angle)
{
	return ((angle / 360) * 2 * M_PI);
}
