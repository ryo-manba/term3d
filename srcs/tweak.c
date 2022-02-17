#include "tweak.h"

static double	get_magnitude(const t_vector3 *position);

/* 先頭の頂点のベクトルの大きさをみて小さくなってたら全体をリサイズ */
void	tweak(t_vertex *model_vertexies)
{
	t_vertex		*index;
	const double	reduction_rate = model_vertexies->magnitude / get_magnitude(model_vertexies->position);

	if (reduction_rate < 1.1f)
	{
		return ;
	}
	// printf("reduction %f\n", reduction_rate);
	index = model_vertexies;
	while (index != NULL)
	{
		index->position->x *= reduction_rate;
		index->position->y *= reduction_rate;
		index->position->z *= reduction_rate;
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
