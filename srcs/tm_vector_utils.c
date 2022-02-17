#include "../includes/tm_utils.h"
#include "../includes/tm_wrapper.h"

t_vector3	*tm_new_vector(const double x, const double y, const double z)
{
	t_vector3	*new;

	new = (t_vector3 *)xmalloc(sizeof(t_vector3));
	new->x = x;
	new->y = y;
	new->z = z;
	return (new);
}

t_vertex	*tm_new_vertex(t_vector3 *vec)
{
	t_vertex *new;

	new = (t_vertex *)xmalloc(sizeof(t_vertex));
	new->position = vec;
	new->next = NULL;
	return (new);
}

void	tm_vertex_add_back(t_vertex **vt, t_vertex *new)
{
	t_vertex	*last;

	if (*vt == NULL)
		*vt = new;
	else
	{
		last = *vt;
		while (last->next)
			last = last->next;
		last->next = new;
	}
}
