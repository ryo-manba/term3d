#include "rotate.h"

static void		rotate_vertex(t_vertex *index, const t_axis axis, const double additional_radian);
static double	get_rotatied_x(const double vector2_x, const double vector2_y, const double additional_radian);
static double	get_rotatied_y(const double vector2_x, const double vector2_y, const double additional_radian);
static double vector2_magnitude(const double vector2_x, const double vector2_y);

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
	double before;
	double after;

	if (axis == X_AXIS)
	{
		// z-y平面
		before = vector2_magnitude(index->position->z, index->position->y);
		index->position->z = get_rotatied_x(index->position->z, index->position->y, additional_radian);
		index->position->y = get_rotatied_y(index->position->z, index->position->y, additional_radian);
		after = vector2_magnitude(index->position->z, index->position->y);
		index->position->z *= before / after;
		index->position->y *= before / after;
	}
	else if (axis == Y_AXIS)
	{
		// x-z平面
		before = vector2_magnitude(index->position->x, index->position->z);
		index->position->x = get_rotatied_x(index->position->x, index->position->z, additional_radian);
		index->position->z = get_rotatied_y(index->position->x, index->position->z, additional_radian);
		after = vector2_magnitude(index->position->x, index->position->z);
		index->position->x *= before / after;
		index->position->z *= before / after;
	}
	else
	{
		// x-y平面
		before = vector2_magnitude(index->position->x, index->position->y);
		index->position->x = get_rotatied_x(index->position->x, index->position->y, additional_radian);
		index->position->y = get_rotatied_y(index->position->x, index->position->y, additional_radian);
		after = vector2_magnitude(index->position->x, index->position->y);
		index->position->x *= before / after;
		index->position->y *= before / after;
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
static double vector2_magnitude(const double vector2_x, const double vector2_y)
{
	double square_magnitude;

	square_magnitude = vector2_x * vector2_x + vector2_y * vector2_y;
	return (sqrt(square_magnitude)); 
}
