/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkanzaki <tkanzaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 23:28:00 by tkrm              #+#    #+#             */
/*   Updated: 2022/02/23 05:59:04 by tkanzaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

void	camera_control(t_camera *camera, int key)
{
	if (key == 'w')
		camera->position.z++;
	else if (key == 'a')
		camera->position.x--;
	else if (key == 's')
		camera->position.z--;
	else if (key == 'd')
		camera->position.x++;
	else if (key == 'q')
		camera->position.y--;
	else if (key == 'e')
		camera->position.y++;
	else if (key == 'j'
		&& camera->horizontal_angle > (-1) * CAMERA_ANGLE_RANGE / 2)
		camera->horizontal_angle--;
	else if (key == 'l'
		&& camera->horizontal_angle < CAMERA_ANGLE_RANGE / 2)
		camera->horizontal_angle++;
}
