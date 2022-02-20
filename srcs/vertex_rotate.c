#include "vertex.h"

static double	vector2_magnitude(const double vector2_x,
										const double vector2_y);
static double	addition_theorem_sin(const double vector2_x,
										const double vector2_y,
										const double additional_radian);
static double	addition_theorem_cos(const double vector2_x,
										const double vector2_y,
										const double additional_radian);

void	vertex_rotate(double *horizontal, double *vertical, const double additional_radian)
{
	double	before;
	double	after;

	before = vector2_magnitude(*horizontal, *vertical);
	*horizontal = addition_theorem_cos(*horizontal, *vertical, additional_radian);
	*vertical = addition_theorem_sin(*horizontal, *vertical, additional_radian);
	after = vector2_magnitude(*horizontal, *vertical);
	*horizontal *= before / after;
	*vertical *= before / after;
}

/**
 * sin(α + β) = sinαcosβ + cosαsinβ
 * magnitude * sin(α + β) = ycosβ + xsinβ
 * cos(α + β) = cosαcosβ − sinαsinβ
 * magnitude * cos(α + β) = xcosβ + ysinβ
 */
static double	addition_theorem_sin(const double vector2_x,
	const double vector2_y, const double additional_radian)
{
	return (vector2_y * cos(additional_radian) + vector2_x * sin(additional_radian));
}

static double addition_theorem_cos(const double vector2_x,
	const double vector2_y, const double additional_radian)
{
	return (vector2_x * cos(additional_radian) - vector2_y * sin(additional_radian));
}

static double	vector2_magnitude(const double vector2_x,
	const double vector2_y)
{
	double	square_magnitude;

	square_magnitude = vector2_x * vector2_x + vector2_y * vector2_y;
	return (sqrt(square_magnitude)); 
}
