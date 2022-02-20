#ifndef TERM3D_H
# define TERM3D_H

# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

# define DISPLAY_HEIGHT 40
# define DISPLAY_WIDTH 120
# define VIEW_ANGLE_WIDTH 120 // 視野角
# define VIEW_ANGLE_HEIGHT 80
# define FRAMES_PER_SECOND 60 // FPS
# define DEFAULT_CAMERA_MODE 0 // 0:平行投影 1:透視投影
# define OBJ1_EXPANSION_RATE 3 // スケール
# define OBJ2_EXPANSION_RATE 4
# define OBJ1_ROTATE_SPEED_X 0 // 回転角度
# define OBJ1_ROTATE_SPEED_Y 0
# define OBJ1_ROTATE_SPEED_Z 0
# define OBJ2_ROTATE_SPEED_X 0
# define OBJ2_ROTATE_SPEED_Y 0
# define OBJ2_ROTATE_SPEED_Z 0
# define OBJ1_PIVOT_X -15 // 回転ピボット
# define OBJ1_PIVOT_Y -2
# define OBJ1_PIVOT_Z -1
# define OBJ2_PIVOT_X 15
# define OBJ2_PIVOT_Y 2
# define OBJ2_PIVOT_Z 1
# define CAMERA_POSITION_X 20 // 固定
# define CAMERA_POSITION_Y -5
# define CAMERA_POSITION_Z -140 // 固定
# define CAMERA_ANGLE_HORIZONTAL 0 // 水平回転角度
# define CAMERA_ANGLE_RANGE 60 // カメラ回転の可動域
# define FILE_TYPE_THREED ','
# define FILE_TYPE_OBJ    ' '

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
	struct s_vertex		*last;
}	t_vertex;

typedef struct s_camera
{
	struct s_vector3	*position;
	double		horizontal_angle;
	enum e_camera_mode	mode;
}	t_camera;

char	*read_file(const char *file_path);

#endif
