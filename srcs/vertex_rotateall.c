#include "vertex.h"

static void	rotate(t_vertex *index, const t_axis axis,
				const double additional_radian,
				const t_vector3 *pivot);
static void	offset_rotate(double *horizontal_position,
				double *vertical_position,
				const double additional_radian,
				const t_vector2 *offset);
static void	set_vector2_position(t_vertex *index,
				double **horizontal_position,
				double **vertical_position,
				const t_axis axis);
static void	set_vector2_offset(const t_vector3 *pivot,
				t_vector2 *offset,
				const t_axis axis);

void	vertex_rotateall(t_vertex *model_vertexes,
	const t_axis axis, const int angle, const t_vector3 *pivot)
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
		rotate(index, axis, additional_radian, pivot);
		index = index->next;
	}
}

static void	rotate(t_vertex *index, const t_axis axis,
	const double additional_radian,
	const t_vector3 *pivot)
{
	double		*horizontal_position;
	double		*vertical_position;
	t_vector2	offset;

	set_vector2_offset(pivot, &offset, axis);
	set_vector2_position(index, &horizontal_position, &vertical_position, axis);
	offset_rotate(horizontal_position, vertical_position,
		additional_radian, &offset);
}

static void	set_vector2_offset(const t_vector3 *pivot,
	t_vector2 *offset, const t_axis axis)
{
	if (axis == X_AXIS)
	{
		offset->x = pivot->z;
		offset->y = pivot->y;
	}
	else if (axis == Y_AXIS)
	{
		offset->x = pivot->x;
		offset->y = pivot->z;
	}
	else
	{
		offset->x = pivot->x;
		offset->y = pivot->y;
	}
}

static void	set_vector2_position(t_vertex *index,
	double **horizontal_position,
	double **vertical_position,
	const t_axis axis)
{
	if (axis == X_AXIS)
	{
		*horizontal_position = &index->position->z;
		*vertical_position = &index->position->y;
	}
	else if (axis == Y_AXIS)
	{
		*horizontal_position = &index->position->x;
		*vertical_position = &index->position->z;
	}
	else
	{
		*horizontal_position = &index->position->x;
		*vertical_position = &index->position->y;
	}
}

static void	offset_rotate(double *horizontal_position,
	double *vertical_position,
	const double additional_radian,
	const t_vector2 *offset)
{
	*horizontal_position -= offset->x;
	*vertical_position -= offset->y;
	vertex_rotate(horizontal_position, vertical_position, additional_radian);
	*horizontal_position += offset->x;
	*vertical_position += offset->y;
}
