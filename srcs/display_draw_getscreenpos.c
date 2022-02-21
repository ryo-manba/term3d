/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_draw_getscreenpos.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkrm <tkrm@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 23:28:00 by tkrm              #+#    #+#             */
/*   Updated: 2022/02/20 23:28:00 by tkrm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "vertex.h"

static double	get_parallel_pos(const t_axis axis,
					const double real_pos,
					const t_vertex *index,
					const t_camera *camera);
static double	get_perspective_pos(const t_axis axis,
					const double real_pos,
					const t_vertex *index,
					const t_camera *camera);
static double	distance_ratio(const t_camera *camera,
					const t_vertex *index);

double	display_draw_getscreenpos(const t_axis axis,
	const double real_pos,
	const t_vertex *index,
	const t_camera *camera)
{
	double	screen_pos;

	if (camera->mode == PARALLEL)
		screen_pos = get_parallel_pos(axis, real_pos, index, camera);
	else
		screen_pos = get_perspective_pos(axis, real_pos, index, camera);
	screen_pos = floor(screen_pos);
	return (screen_pos);
}

static double	get_parallel_pos(const t_axis axis,
	const	double real_pos,
	const	t_vertex *index,
	const	t_camera *camera)
{
	const double	pararell_1x_pos = (CAMERA_POSITION_Z
			* tan(VIEW_ANGLE_WIDTH / 180 * M_PI))
			/ DISPLAY_WIDTH * CAMERA_POSITION_Z;
	double			additional_radian;
	double			parallel_position;

	if (axis == Y_AXIS)
		additional_radian = 0;
	else
		additional_radian = (camera->horizontal_angle / 360) * 2 * M_PI;
	parallel_position = real_pos
		* cos(additional_radian)
		- (index->position->z)
		* sin(additional_radian);
	parallel_position /= (1 + (pararell_1x_pos - camera->position->z) / 10);
	if (axis == Y_AXIS)
		parallel_position *= -1;
	return (parallel_position);
}

static double	get_perspective_pos(const t_axis axis,
	const	double real_pos,
	const	t_vertex *index,
	const	t_camera *camera)
{
	double	tan_before;
	double	tan_after;
	double	additional_radian;
	double	perspective_position;

	tan_before = real_pos / (camera->position->z - index->position->z);
	if (axis == Y_AXIS)
		tan_after = 0;
	else
	{
		additional_radian = camera->horizontal_angle / 360 * 2 * M_PI;
		tan_after = tan(additional_radian);
	}
	perspective_position = camera->position->z
		* (tan_before
			* (1 - tan_after * tan_after)
			/ (1 - tan_after * tan_before)
			- tan_after);
	perspective_position *= distance_ratio(camera, index);
	if (axis == Y_AXIS)
		perspective_position *= -1;
	return (perspective_position);
}

static double	distance_ratio(const t_camera *camera,
	const t_vertex *index)
{
	double	distance;

	if (index->position->z < camera->position->z)
		return (DISPLAY_WIDTH);
	else
		distance = index->position->z - camera->position->z;
	return (PARSE_LEVEL / distance);
}
