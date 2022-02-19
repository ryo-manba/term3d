#include "display.h"

double display_draw_getdepth(const t_vertex *index, const t_vector3 *camera_position, const double horizontal_angle)
{
	double		distance_display;
	double		distance_vertex;
	double		hoge;
	hoge = (double)horizontal_angle;
	hoge = (double)hoge;

	distance_display = camera_position->z;
	distance_vertex = distance_display - index->position->z;
	
	return (distance_display / distance_vertex);
}
