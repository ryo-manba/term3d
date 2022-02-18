#ifndef DRAW_H
# define DRAW_H

# include "term3d.h"

void	display_init(char display[][DISPLAY_WIDTH]);
void	display_draw(char display[][DISPLAY_WIDTH], const t_vertex *model_vertexes, t_camera_mode mode);
double	display_draw_getdepth(t_vertex *index, t_vector3 *camera_position, t_vector3 *camera_rotation);
void	display_print(char display[][DISPLAY_WIDTH]);

#endif
