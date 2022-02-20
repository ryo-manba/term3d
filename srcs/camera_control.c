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
