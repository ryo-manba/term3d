#include "normalize.h"

void	normalize(t_vertex *model_vertexes, const int magnification)
{
	t_vertex *index;

	index = model_vertexes;
	while (index != NULL)
	{
		index->position->x *= magnification;
		index->position->y *= magnification;
		index->position->z *= magnification;
		index = index->next;
	}
}
