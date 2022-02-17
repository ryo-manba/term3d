#include "rotate.h"

static void		rotate_vertex(t_vertex *index, const t_axis axis, const double additional_radian);
static double	get_rotatied_x(const double vector2_x, const double vector2_y, const double additional_radian);
static double	get_rotatied_y(const double vector2_x, const double vector2_y, const double additional_radian);
// static double	get_magnitude(const t_vector3 *position);

/**
 * 頂点を全て反時計回りに軸回転させる
 * @param model_vertexes 頂点の座標
 * @param axis 回転軸
 * @param degree 角度
 */
void	rotate(t_vertex *model_vertexes, const t_axis axis, const int degree)
{
	t_vertex *index;
	const double additional_radian = (((double)degree / 360) * 2 * M_PI);

	if (degree % 360 == 0)
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

/* 頂点を反時計回りに軸回転させる */
static void rotate_vertex(t_vertex *index, const t_axis axis, const double additional_radian)
{
	if (axis == X_AXIS)
	{
		// z-y平面
		index->position->z = get_rotatied_x(index->position->z, index->position->y, additional_radian);
		index->position->y = get_rotatied_y(index->position->z, index->position->y, additional_radian);
	}
	else if (axis == Y_AXIS)
	{
		// x-z平面
		index->position->x = get_rotatied_x(index->position->x, index->position->z, additional_radian);
		index->position->z = get_rotatied_y(index->position->x, index->position->z, additional_radian);
	}
	else if (axis == Z_AXIS)
	{
		// x-y平面
		index->position->x = get_rotatied_x(index->position->x, index->position->y, additional_radian);
		index->position->y = get_rotatied_y(index->position->x, index->position->y, additional_radian);
	}
	else
	{
		return ;
	}
}

/**
 * 加法定理によって平面上のy座標を取得
 * sin(α + β) = sinαcosβ + cosαsinβ
 * magnitude * sin(α + β) = ycosβ + xsinβ
 */
static double get_rotatied_y(const double vector2_x, const double vector2_y, const double additional_radian)
{
	return (vector2_y * cos(additional_radian) + vector2_x * sin(additional_radian));
}

/**
 * 加法定理によって平面上のx座標を取得
 *  cos(α + β) = cosαcosβ − sinαsinβ
 * magnitude * cos(α + β) = xcosβ + ysinβ
 * */
static double get_rotatied_x(const double vector2_x, const double vector2_y, const double additional_radian)
{
	return (vector2_x * cos(additional_radian) - vector2_y * sin(additional_radian));
}

/* 原点からのベクトルの大きさを取得 */
// static double get_magnitude(const t_vector3 *position)
// {
// 	double square_magnitude;

// 	square_magnitude = position->x * position->x + position->y * position->y;
// 	return (sqrt(square_magnitude)); 
// }
