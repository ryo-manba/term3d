#ifndef TERM3D_H
# define TERM3D_H

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
