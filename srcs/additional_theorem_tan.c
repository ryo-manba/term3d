#include "additional_theorem.h"

double	addition_theorem_tan(const double original_radian, const double additional_radian)
{
	const double	tan_a = tan(original_radian);
	const double	tan_b = tan(additional_radian);

	return ((tan_a + tan_b) / (1 - tan_a * tan_b));
}
