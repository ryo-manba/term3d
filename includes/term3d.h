#ifndef TERM3D_H
# define TERM3D_H

# include <stdbool.h>

typedef enum e_axis
{
	X_AXIS,
	Y_AXIS,
	Z_AXIS
}	t_axis;

typedef struct s_rotation
{
	enum e_axis	axis;
	int			angle;
}	t_rotation;

typedef struct s_vector3
{
	float	x;
	float	y;
	float	z;
}	t_vector3;

typedef struct s_vertex
{
	struct s_vector3	*position;
	struct s_vertex		*next;
}	t_vertex;

#endif
