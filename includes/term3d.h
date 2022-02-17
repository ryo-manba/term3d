#ifndef TERM3D_H
# define TERM3D_H

# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

# define DISPLAY_HEIGHT 30
# define DISPLAY_WIDTH 81
# define EXPANSION_RATE 3
# define DEGREE_X_PER_FRAME 0
# define DEGREE_Y_PER_FRAME 2
# define DEGREE_Z_PER_FRAME 1
# define FRAMES_PER_SECOND 60

typedef enum e_axis
{
	X_AXIS,
	Y_AXIS,
	Z_AXIS
}	t_axis;

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
