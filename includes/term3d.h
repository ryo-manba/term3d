#ifndef TERM3D_H
# define TERM3D_H

# include <stdbool.h>
# include <stdlib.h>
# include <math.h>

# define DISPLAY_HEIGHT 640
# define DISPLAY_WIDTH 480
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
	struct s_vertex		*next;
}	t_vertex;

#endif
