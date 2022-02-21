/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tm_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkrm <tkrm@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 23:28:01 by tkrm              #+#    #+#             */
/*   Updated: 2022/02/20 23:28:01 by tkrm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tm_utils.h"
#include "camera.h"

void	destroy_all(t_vertex **vertexes, t_camera *camera)
{
	vertexes_destroy(vertexes);
	camera_destroy(camera);
}

void	vertexes_destroy(t_vertex **vertexes)
{
	t_vertex	*vt;
	t_vertex	*tmp;
	int			i;

	i = 0;
	while (vertexes[i])
	{
		vt = vertexes[i];
		while (vt)
		{
			tmp = vt;
			vt = vt->next;
			free(tmp->position);
			free(tmp);
		}
		i += 1;
	}
	free(vertexes[i]);
}
