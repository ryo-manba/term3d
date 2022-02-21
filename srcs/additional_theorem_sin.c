#include "additional_theorem.h"

double	addition_theorem_sin(const double vector2_x,
	const double vector2_y, const double additional_radian)
{
	return (vector2_y * cos(additional_radian)
		+ vector2_x * sin(additional_radian));
}
