#ifndef DRAW_H
# define DRAW_H

# include "term3d.h"

void	draw(const t_vertex *model_vertexes, t_camera_mode mode);
double	draw_getdepth(t_vertex *index, t_vector3 *camera_position, t_vector3 *camera_rotation);

#endif
