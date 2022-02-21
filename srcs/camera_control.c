/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkrm <tkrm@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 23:28:00 by tkrm              #+#    #+#             */
/*   Updated: 2022/02/20 23:28:00 by tkrm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

void	camera_control(t_camera *camera)
{
	if (camera->horizontal_angle > CAMERA_ANGLE_RANGE / 2)
	{
		camera->horizontal_angle = CAMERA_ANGLE_RANGE / 2;
	}
	else if (camera->horizontal_angle < (-1) * CAMERA_ANGLE_RANGE / 2)
	{
		camera->horizontal_angle = (-1) * CAMERA_ANGLE_RANGE / 2;
	}
	else
	{
		return ;
	}
}
