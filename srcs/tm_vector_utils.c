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
	t_vertex	*new;

	new = (t_vertex *)xmalloc(sizeof(t_vertex));
	new->position = vec;
	new->next = NULL;
	new->last = new;
	return (new);
}

/**
 *  lst1, lst2, lst3->lst4
 *
 *  add_back(&lst1, lst2)
 *  lst1->last(lst1)->next = lst2
 *  lst1->last = lst2->last(lst2)
 *
 *  add_back(&lst1, lst3)
 *  lst1->last(lst2)->next = lst3
 *  lst1->last = lst3->last(lst4)
 */
void	tm_vertex_add_back(t_vertex **vt, t_vertex *new)
{
	if (*vt == NULL)
		*vt = new;
	else
	{
		(*vt)->last->next = new;
		(*vt)->last = new->last;
	}
}
