#include "camera.h"

void	camera_destory(t_camera *camera)
{
	free(camera->position);
	free(camera);
}
