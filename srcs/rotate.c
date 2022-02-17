#include "rotate.h"

static double get_vertical_element(const double magnitude, const double original_sin, const double original_cos, const double additional_radian);
static double get_horizontal_element(const double magnitude, const double original_sin, const double original_cos, const double additional_radian);
static double get_magnitude(const t_vector3 *position);

/**
 * 座標を反時計回りに軸回転させる
 * @param model_vertexes 頂点の座標
 * @param axis 回転軸
 * @param degree 角度
 */
void	rotate(t_vertex *model_vertexes, const t_axis axis, const int degree)
{
	const double magnitude = get_magnitude(model_vertexes);
	const double additional_radian = (((double)degree / 360) * 2 * M_PI);

	if (axis == X_AXIS)
	{
		model_vertexes->position->y = get_vertical_element(magnitude, model_vertexes->position->y, model_vertexes->position->z, additional_radian);
		model_vertexes->position->z = get_horizontal_element(magnitude, model_vertexes->position->y, model_vertexes->position->z, additional_radian);
	}
	else if (axis == Y_AXIS)
	{
		model_vertexes->position->z = get_vertical_element(magnitude, model_vertexes->position->z, model_vertexes->position->x, additional_radian);
		model_vertexes->position->x = get_horizontal_element(magnitude, model_vertexes->position->z, model_vertexes->position->x, additional_radian);
	}
	else if (axis == Z_AXIS)
	{
		model_vertexes->position->y = get_vertical_element(magnitude, model_vertexes->position->y, model_vertexes->position->x, additional_radian);
		model_vertexes->position->x = get_horizontal_element(magnitude, model_vertexes->position->y, model_vertexes->position->x, additional_radian);
	}
	else
	{
		return ;
	}
}

/**
 * 加法定理によって新しい縦座標を取得
 * sin(α + β) = sinαcosβ + cosαsinβ
 */
static double get_vertical_element(const double magnitude, const double original_sin, const double original_cos, const double additional_radian)
{
	return (magnitude * (original_sin * cos(additional_radian) + original_cos * sin(additional_radian)));
}

/**
 * 加法定理によって新しい横座標を取得
 *  cos(α + β) = cosαcosβ − sinαsinβ
 * */
static double get_horizontal_element(const double magnitude, const double original_sin, const double original_cos, const double additional_radian)
{
	return (magnitude * (original_cos * cos(additional_radian) - original_sin * sin(additional_radian)));
}

/* 原点からのベクトルの大きさを取得 */
static double get_magnitude(const t_vector3 *position)
{
	double square_magnitude;

	square_magnitude = position->x * position->x + position->y + position->y;
	return (sqrt(square_magnitude)); 
}
