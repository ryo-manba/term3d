/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tm_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkanzaki <tkanzaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 23:28:01 by tkrm              #+#    #+#             */
/*   Updated: 2022/02/23 07:18:18 by tkanzaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tm_utils.h"
#include "camera.h"

void	models_destroy(t_model *models)
{
	int	index;

	index = 0;
	while (models[index].vertexes != NULL)
	{
		vertexes_destroy(models[index].vertexes);
		index++;
	}
}

void	vertexes_destroy(t_vertex *vertexes)
{
	t_vertex	*vt;
	t_vertex	*tmp;

	vt = vertexes;
	while (vt)
	{
		tmp = vt;
		vt = vt->next;
		free(tmp);
	}
}
