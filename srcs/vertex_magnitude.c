/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex_magnitude.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkanzaki <tkanzaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 06:24:39 by tkanzaki          #+#    #+#             */
/*   Updated: 2022/02/20 06:24:39 by tkanzaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vertex.h"

double	vertex_magnitude(const t_vector3 *position)
{
	double	hypotenuse_xy_squared;
	double	hypotenuse_xyz_squared;

	hypotenuse_xy_squared = position->x * position->x
		+ position->y * position->y;
	hypotenuse_xyz_squared = hypotenuse_xy_squared
		+ position->z * position->z;
	return (sqrt(hypotenuse_xyz_squared));
}
