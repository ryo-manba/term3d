/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tm_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkanzaki <tkanzaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 23:28:01 by tkrm              #+#    #+#             */
/*   Updated: 2022/02/23 05:59:59 by tkanzaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tm_utils.h"
#include "camera.h"

void	destroy_all(t_vertex **vertexes)
{
	vertexes_destroy(vertexes);
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
