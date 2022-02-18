#ifndef TERM3D_H
# define TERM3D_H

# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

# define DISPLAY_HEIGHT 40
# define DISPLAY_WIDTH 120
# define EXPANSION_RATE1 3
# define EXPANSION_RATE2 4
# define ANGLE1_X_PER_FRAME 1
# define ANGLE1_Y_PER_FRAME 1
# define ANGLE1_Z_PER_FRAME 0
# define ANGLE2_X_PER_FRAME 0
# define ANGLE2_Y_PER_FRAME 2
# define ANGLE2_Z_PER_FRAME 1
# define FRAMES_PER_SECOND 60
# define CAMERA_POSITION_X 20
# define CAMERA_POSITION_Y -5
# define CAMERA_POSITION_Z -100
# define CAMERA_ANGLE_X 0
# define CAMERA_ANGLE_Y 0
# define CAMERA_ANGLE_Z 0
# define FILE_TYPE_THREED ','
# define FILE_TYPE_OBJ ' '

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

char	*read_file(const char *file_path);

#endif
