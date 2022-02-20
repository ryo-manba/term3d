/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkanzaki <tkanzaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 06:25:11 by tkanzaki          #+#    #+#             */
/*   Updated: 2022/02/20 06:25:12 by tkanzaki         ###   ########.fr       */
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
