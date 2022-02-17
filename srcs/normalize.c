#include "normalize.h"

static double	get_magnitude(const t_vector3 *position);

void	normalize(t_vertex *model_vertexes, const int expansion_rate)
{
	t_vertex *index;

	index = model_vertexes;
	while (index != NULL)
	{
		index->position->x *= expansion_rate;
		index->position->y *= expansion_rate;
		index->position->z *= expansion_rate;
		index->magnitude = get_magnitude(index->position);
		index = index->next;
	}
}

/* 原点からのベクトルの大きさを取得 */
static double get_magnitude(const t_vector3 *position)
{
	double square_magnitude;

	square_magnitude = position->x * position->x + position->y * position->y;
	return (sqrt(square_magnitude)); 
}
