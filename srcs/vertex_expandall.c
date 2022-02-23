/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex_expandall.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuka < rmatsuka@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 23:28:01 by tkrm              #+#    #+#             */
/*   Updated: 2022/02/23 11:53:04 by rmatsuka         ###   ########.fr       */
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
		index = index->next;
	}
}
