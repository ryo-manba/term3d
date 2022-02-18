#include "rotate.h"

static void		rotate_vertex(t_vertex *index, const t_axis axis, const double additional_radian);
static double	vector2_magnitude(const double vector2_x, const double vector2_y);
static double	addition_theorem(const t_axis axis, const double vector2_x, const double vector2_y, const double additional_radian);
static void		set_rotatied_vertex(double *horizontal, double *vertical, const double additional_radian);

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
	set_rotatied_vertex(horizontal, vertical, additional_radian);
}

static void	set_rotatied_vertex(double *horizontal, double *vertical, const double additional_radian)
{
	double before;
	double after;

	before = vector2_magnitude(*horizontal, *vertical);

	// 加法定理適用
	*horizontal = addition_theorem(X_AXIS, *horizontal, *vertical, additional_radian);
	*vertical = addition_theorem(Y_AXIS, *horizontal, *vertical, additional_radian);

	after = vector2_magnitude(*horizontal, *vertical);

	// 加法定理後に小さくなった分戻す
	*horizontal *= before / after;
	*vertical *= before / after;
}

/**
 * 加法定理によって平面上の座標を取得
 * sin(α + β) = sinαcosβ + cosαsinβ
 * magnitude * sin(α + β) = ycosβ + xsinβ
 * cos(α + β) = cosαcosβ − sinαsinβ
 * magnitude * cos(α + β) = xcosβ + ysinβ
 */
static double addition_theorem(const t_axis axis, const double vector2_x, const double vector2_y, const double additional_radian)
{
	if (axis == Y_AXIS)
	{
		return (vector2_y * cos(additional_radian) + vector2_x * sin(additional_radian));
	}
	else
	{
		return (vector2_x * cos(additional_radian) - vector2_y * sin(additional_radian));
	}
}

/* 原点からのベクトルの大きさを取得 */
static double vector2_magnitude(const double vector2_x, const double vector2_y)
{
	double square_magnitude;

	square_magnitude = vector2_x * vector2_x + vector2_y * vector2_y;
	return (sqrt(square_magnitude)); 
}
