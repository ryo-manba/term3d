#include "display.h"

static double get_perspective_pos(const double real_pos, const t_vertex *index, const t_camera *camera);

double display_draw_getscreenpos(const double real_pos, const t_vertex *index, const t_camera *camera)
{
	double		screen_pos;

	if (camera->mode == PARALLEL)
	{
		// 平行投影
		screen_pos = real_pos;
	}
	else
	{
		// 透視投影
		screen_pos = get_perspective_pos(real_pos, index, camera);
	}
	screen_pos = floor(screen_pos);
	return (screen_pos);
}

static double get_perspective_pos(const double real_pos, const t_vertex *index, const t_camera *camera)
{
	double		distance_display;
	double		distance_vertex;

	distance_display = camera->position->z;
	distance_vertex = distance_display - index->position->z;
	return (real_pos * distance_display / distance_vertex);
}
