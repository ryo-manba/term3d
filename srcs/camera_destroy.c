#include "camera.h"

void	destroy_camera(t_camera *camera)
{
	free(camera->position);
	free(camera);
}
