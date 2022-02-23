/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   models_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkanzaki <tkanzaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 23:33:42 by rmatsuka          #+#    #+#             */
/*   Updated: 2022/02/23 07:15:00 by tkanzaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term3d.h"
#include "vertex.h"
#include "tm_utils.h"

/**
 * @brief Set the scale of the 3D model to the default value
 */
void	models_rescale(t_model *models, int nb_models)
{
	int	i;
	int	scale;

	i = 0;
	scale = OBJ_EXPANSION_RATE;
	while (i < nb_models)
	{
		vertex_enlarge(models[i].vertexes, scale);
		i += 1;
		scale += 1;
	}
}

/**
 * @brief Rotate the 3D model around the pivot
 */
void	models_rotate(t_model *models, const int nb_models)
{
	int	i;

	i = 0;
	while (i < nb_models)
	{
		vertex_rotateall(models[i].vertexes, X_AXIS,
			OBJ_ROTATE_SPEED_X + i, &models[i].pivot);
		vertex_rotateall(models[i].vertexes, Y_AXIS,
			OBJ_ROTATE_SPEED_Y + i, &models[i].pivot);
		vertex_rotateall(models[i].vertexes, Z_AXIS,
			OBJ_ROTATE_SPEED_Z + i, &models[i].pivot);
		i += 1;
	}
}
