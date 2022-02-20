/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkrm <tkrm@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 23:28:00 by tkrm              #+#    #+#             */
/*   Updated: 2022/02/20 23:30:05 by tkrm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

t_camera	*camera_init(void)
{
	t_camera	*camera;
	t_vector3	*position;

	position = (t_vector3 *)malloc(sizeof(t_vector3));
	if (position == NULL)
	{
		exit(EXIT_FAILURE);
	}
	position->x = CAMERA_POSITION_X;
	position->y = CAMERA_POSITION_Y;
	position->z = CAMERA_POSITION_Z;
	camera = (t_camera *)malloc(sizeof(t_camera));
	if (camera == NULL)
	{
		exit(EXIT_FAILURE);
	}
	camera->position = position;
	camera->horizontal_angle = CAMERA_ANGLE_HORIZONTAL;
	camera->mode = DEFAULT_CAMERA_MODE;
	return (camera);
}
