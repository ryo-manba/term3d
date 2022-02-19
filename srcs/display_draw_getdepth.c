#include "display.h"

double display_draw_getdepth(t_vertex *index, t_vector3 *camera_position, t_vector3 *camera_rotation)
{
	double		distance_display;
	double		distance_vertex;
	camera_rotation = (void *)camera_rotation;

	distance_display = camera_position->z;
	distance_vertex = distance_display - index->position->z;
	
	return (distance_display / distance_vertex);
}
