/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   models_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuka < rmatsuka@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 23:33:42 by rmatsuka          #+#    #+#             */
/*   Updated: 2022/02/21 23:33:56 by rmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term3d.h"
#include "vertex.h"
#include "tm_utils.h"

/**
 * @brief Set the scale of the 3D model to the default value
 */
void	set_scale(t_vertex **model_vertexes, int nb_models)
{
	int	i;
	int	scale;

	i = 0;
	scale = OBJ_EXPANSION_RATE;
	while (i < nb_models)
	{
		vertex_expandall(model_vertexes[i], scale);
		i += 1;
		scale += 1;
	}
}

/**
 * @brief Rotate the 3D model around the pivot
 */
void	models_rotate(t_vertex **vertexes, t_vector3 *pivots, int nb_models)
{
	int	i;

	i = 0;
	while (i < nb_models)
	{
		vertex_rotateall(vertexes[i], X_AXIS,
			OBJ_ROTATE_SPEED_X + i, &pivots[i]);
		vertex_rotateall(vertexes[i], Y_AXIS,
			OBJ_ROTATE_SPEED_Y + i, &pivots[i]);
		vertex_rotateall(vertexes[i], Z_AXIS,
			OBJ_ROTATE_SPEED_Z + i, &pivots[i]);
		i += 1;
	}
}
