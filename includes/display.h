#ifndef DISPLAY_H
# define DISPLAY_H

# include "term3d.h"

void	display_init(char display[][DISPLAY_WIDTH]);
void	display_draw(char display[][DISPLAY_WIDTH], const t_vertex *model_vertexes, const t_camera *camera);
double display_draw_getdepth(const t_vertex *index, const t_vector3 *camera_position, const double horizontal_angle);
void	display_print(char display[][DISPLAY_WIDTH]);

#endif
