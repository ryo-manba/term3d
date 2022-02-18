#include "rotate.h"
#include "move.h"

static void		rotate_vertex(t_vertex *index, const t_axis axis, const double additional_radian);

/**
 * 頂点を全て反時計回りに軸回転させる
 * @param model_vertexes 頂点の座標
 * @param axis 回転軸
 * @param angle 角度
 */
void	rotate(t_vertex *model_vertexes, const t_axis axis, const int angle)
{
	t_vertex		*index;
	const double	additional_radian = (((double)angle / 360) * 2 * M_PI);

	if (angle % 360 == 0)
	{
		return ;
	}
	index = model_vertexes;
	while (index != NULL)
	{
		rotate_vertex(index, axis, additional_radian);
		index = index->next;
	}
}

/* 平面上で頂点を反時計回りに軸回転させる */
static void	rotate_vertex(t_vertex *index, const t_axis axis, const double additional_radian)
{
	double	*horizontal; // 水平方向のポインタ
	double	*vertical; // 垂直方向のポインタ

	if (axis == X_AXIS)
	{
		// z-y平面
		horizontal = &index->position->z;
		vertical = &index->position->y;
	}
	else if (axis == Y_AXIS)
	{
		// x-z平面
		horizontal = &index->position->x;
		vertical = &index->position->z;
	}
	else
	{
		// x-y平面
		horizontal = &index->position->x;
		vertical = &index->position->y;
	}
	// 回転させた値をセット
	move(horizontal, vertical, additional_radian);
}
