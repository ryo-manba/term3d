#ifndef TERM3D_H
# define TERM3D_H

# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

# define DISPLAY_HEIGHT 40
# define DISPLAY_WIDTH 120
# define FRAMES_PER_SECOND 60
# define OBJ1_EXPANSION_RATE 3
# define OBJ2_EXPANSION_RATE 4
# define OBJ1_ROTATE_SPEED_X 1
# define OBJ1_ROTATE_SPEED_Y 1
# define OBJ1_ROTATE_SPEED_Z 0
# define OBJ2_ROTATE_SPEED_X 0
# define OBJ2_ROTATE_SPEED_Y 2
# define OBJ2_ROTATE_SPEED_Z 1
# define OBJ1_PIVOT_X -15
# define OBJ1_PIVOT_Y -2
# define OBJ1_PIVOT_Z -1
# define OBJ2_PIVOT_X 15
# define OBJ2_PIVOT_Y 2
# define OBJ2_PIVOT_Z 1
# define CAMERA_POSITION_X 20 // 固定
# define CAMERA_POSITION_Y -5
# define CAMERA_POSITION_Z -100 // 固定
# define CAMERA_ANGLE_HORIZONTAL 0
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

typedef struct s_camera
{
	t_vector3	*position;
	double		horizontal_angle;
}	t_camera;

char	*read_file(const char *file_path);

#endif
