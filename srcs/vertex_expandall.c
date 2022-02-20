/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex_expandall.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkanzaki <tkanzaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 06:24:42 by tkanzaki          #+#    #+#             */
/*   Updated: 2022/02/20 06:24:42 by tkanzaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vertex.h"

void	vertex_expandall(t_vertex *model_vertexes, const int expansion_rate)
{
	t_vertex	*index;

	index = model_vertexes;
	while (index != NULL)
	{
		index->position->x *= expansion_rate;
		index->position->y *= expansion_rate;
		index->position->z *= expansion_rate;
		index->magnitude = vertex_magnitude(index->position);
		index = index->next;
	}
}
