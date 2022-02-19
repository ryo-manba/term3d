#ifndef DISPLAY_H
# define DISPLAY_H

# include "term3d.h"

void	display_init(char display[][DISPLAY_WIDTH]);
void	display_draw(char display[][DISPLAY_WIDTH], const t_vertex *model_vertexes, const t_camera *camera);
double	display_draw_getscreenpos(const t_axis axis, const double real_pos, const t_vertex *index, const t_camera *camera);
void	display_print(char display[][DISPLAY_WIDTH]);

#endif
