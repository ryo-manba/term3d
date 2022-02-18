#include "normalize.h"
#include "magnitude.h"

void	normalize(t_vertex *model_vertexes, const int expansion_rate)
{
	t_vertex *index;

	index = model_vertexes;
	while (index != NULL)
	{
		index->position->x *= expansion_rate;
		index->position->y *= expansion_rate;
		index->position->z *= expansion_rate;
		index->magnitude = magnitude(index->position);
		index = index->next;
	}
}

