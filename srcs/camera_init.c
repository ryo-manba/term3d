/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkanzaki <tkanzaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 23:28:00 by tkrm              #+#    #+#             */
/*   Updated: 2022/02/23 06:07:08 by tkanzaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

void	camera_init(t_camera *camera)
{
	camera->position.x = CAMERA_POSITION_X;
	camera->position.y = CAMERA_POSITION_Y;
	camera->position.z = CAMERA_POSITION_Z;
	camera->horizontal_angle = CAMERA_ANGLE_HORIZONTAL;
	camera->mode = DEFAULT_CAMERA_MODE;
}
