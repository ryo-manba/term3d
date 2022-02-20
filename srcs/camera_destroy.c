#include "camera.h"

void	camera_destroy(t_camera *camera)
{
	free(camera->position);
	free(camera);
}
