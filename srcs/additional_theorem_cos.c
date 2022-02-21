#include "additional_theorem.h"

double	addition_theorem_cos(const double vector2_x,
	const double vector2_y, const double additional_radian)
{
	return (vector2_x * cos(additional_radian)
		- vector2_y * sin(additional_radian));
}
