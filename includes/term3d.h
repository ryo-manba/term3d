#ifndef TERM3D_H
# define TERM3D_H

typedef struct s_transform
{
	long	x;
	long	y;
	long	z;
}	t_transform;

typedef struct s_vertex
{
	struct s_transform	*transform;
	struct s_vertex		*next;
	struct s_vertex		*prev;
}	t_vertex;

#endif
