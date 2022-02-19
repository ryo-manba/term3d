#include "vertex.h"

/* 原点からのベクトルの大きさを取得 */
double vertex_magnitude(const t_vector3 *position)
{
	double hypotenuse_xy_squared;
	double hypotenuse_xyz_squared;

	hypotenuse_xy_squared = position->x * position->x + position->y * position->y;
	hypotenuse_xyz_squared = hypotenuse_xy_squared + position->z * position->z;
	return (sqrt(hypotenuse_xyz_squared)); 
}
