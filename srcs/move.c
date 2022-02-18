#include "move.h"

static double	vector2_magnitude(const double vector2_x, const double vector2_y);
static double	addition_theorem(const t_axis axis, const double vector2_x, const double vector2_y, const double additional_radian);

void	move(double *horizontal, double *vertical, const double additional_radian)
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
