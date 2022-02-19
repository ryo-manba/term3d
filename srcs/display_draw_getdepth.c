#include "display.h"

double display_draw_getdepth(t_vertex *index, t_vector3 *camera_position, double horizontal_angle)
{
	double		distance_display;
	double		distance_vertex;
	horizontal_angle = (double)horizontal_angle;

	distance_display = camera_position->z;
	distance_vertex = distance_display - index->position->z;
	
	return (distance_display / distance_vertex);
}
