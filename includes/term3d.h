#ifndef TERM3D_H
# define TERM3D_H

# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

# define DISPLAY_HEIGHT 40
# define DISPLAY_WIDTH 120
# define EXPANSION_RATE 5
# define ANGLE_X_PER_FRAME 0
# define ANGLE_Y_PER_FRAME 1
# define ANGLE_Z_PER_FRAME 0
# define FRAMES_PER_SECOND 60
# define CAMERA_POSITION_X 2
# define CAMERA_POSITION_Y -5
# define CAMERA_POSITION_Z -50
# define CAMERA_ANGLE_X 0
# define CAMERA_ANGLE_Y 0
# define CAMERA_ANGLE_Z 0

typedef enum e_axis
{
	X_AXIS,
	Y_AXIS,
	Z_AXIS
}	t_axis;

typedef enum e_camera_mode
{
	PARALLEL,
	PERSPECTIVE
}	t_camera_mode;

typedef struct s_vector3
{
	double	x;
	double	y;
	double	z;
}	t_vector3;

typedef struct s_vertex
{
	struct s_vector3	*position;
	double				magnitude;
	struct s_vertex		*next;
}	t_vertex;

t_vertex	*read_file(const char *file_path);

#endif
