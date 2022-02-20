#ifndef CAMERA_H
# define CAMERA_H

# include "term3d.h"

t_camera	*camera_init(void);
bool		camera_scanf(t_camera *camera, int *input_char,
				bool *input_flag);
void		destroy_camera(t_camera *camera);
void		camera_control(t_camera *camera);

#endif
