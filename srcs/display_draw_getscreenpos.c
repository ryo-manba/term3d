#include "display.h"

double display_draw_getscreenpos(const double real_pos, const t_vertex *index, const t_camera *camera)
{
	double		screen_pos;
	double		distance_display;
	double		distance_vertex;

	if (camera->mode == PARALLEL)
	{
		screen_pos = floor(real_pos);
		return (screen_pos);
	}
	else
	{
		distance_display = camera->position->z;
		distance_vertex = distance_display - index->position->z;
		screen_pos = floor(real_pos) * distance_display / distance_vertex;
		return (screen_pos);
	}
}
