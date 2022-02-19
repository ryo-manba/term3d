#include "display.h"

static double get_perspective_pos(const t_axis axis, const double real_pos, const t_vertex *index, const t_camera *camera);
static double distance_ratio(const t_camera *camera);

double display_draw_getscreenpos(const t_axis axis, const double real_pos, const t_vertex *index, const t_camera *camera)
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
		screen_pos = get_perspective_pos(axis, real_pos, index, camera);
	}
	screen_pos *= distance_ratio(camera);
	screen_pos = floor(screen_pos);
	return (screen_pos);
}

static double distance_ratio(const t_camera *camera)
{
	const double	view_width = fabs(camera->position->z) * sin(VIEW_ANGLE / 2) * 2;

	return (DISPLAY_WIDTH / view_width);
}

static double get_perspective_pos(const t_axis axis, const double real_pos, const t_vertex *index, const t_camera *camera)
{
	double			perspective_position;
	double			tan_before = real_pos / (camera->position->z - index->position->z);
	double			tan_after =  tan((camera->horizontal_angle / 360) * 2 * M_PI);
	
	if (axis == Y_AXIS)
	{
		tan_after = 0;
	}
	perspective_position = camera->position->z * (tan_before * (1 - tan_after * tan_after) / (1 - tan_after * tan_before) - tan_after);
	return (perspective_position);
}
