#include "camera.h"

bool	camera_scanf(t_camera *camera)
{
	int	c;

	return (false);
	c = getchar();
	if (c == EOF)
		return (true);
	else if (c == 'w')
		camera->position->y--;
	else if (c == 'a')
		camera->horizontal_angle--;
	else if (c == 's')
		camera->position->y++;
	else if (c == 'd')
		camera->horizontal_angle--;
	else
		return (false);
	return (false);
}
