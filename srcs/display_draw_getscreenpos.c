/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_draw_getscreenpos.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkanzaki <tkanzaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 06:24:56 by tkanzaki          #+#    #+#             */
/*   Updated: 2022/02/20 06:24:56 by tkanzaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

static double	get_parallel_pos(const t_axis axis,
					const double real_pos,
					const t_vertex *index,
					const t_camera *camera);
static double	get_perspective_pos(const t_axis axis,
					const double real_pos,
					const t_vertex *index,
					const t_camera *camera);
static double	distance_ratio(const t_axis axis,
					const t_camera *camera,
					const t_vertex *index);

double	display_draw_getscreenpos(const t_axis axis,
	const double real_pos,
	const t_vertex *index,
	const t_camera *camera)
{
	double		screen_pos;

	if (camera->mode == PARALLEL)
		screen_pos = get_parallel_pos(axis, real_pos, index, camera);
	else
		screen_pos = get_perspective_pos(axis, real_pos, index, camera);
	screen_pos *= distance_ratio(axis, camera, index);
	screen_pos = floor(screen_pos);
	return (screen_pos);
}

static double	distance_ratio(const t_axis axis,
	const t_camera *camera,
	const t_vertex *index)
{
	double	distance;
	double	tan_camera_obj;

	if (index->position->z - camera->position->z < 0)
		distance = 0;
	else
		distance = index->position->z - camera->position->z;
	if (axis == X_AXIS)
	{
		tan_camera_obj = tan(VIEW_ANGLE_WIDTH / 2);
		return (DISPLAY_WIDTH / distance * tan_camera_obj * 2);
	}
	else
	{
		tan_camera_obj = tan(VIEW_ANGLE_HEIGHT / 2);
		return (DISPLAY_HEIGHT / distance * tan_camera_obj * 2);
	}
}

static double	get_parallel_pos(const t_axis axis,
	const	double real_pos,
	const	t_vertex *index,
	const	t_camera *camera)
{
	double	additional_radian;
	double	parallel_position;

	if (axis == Y_AXIS)
		additional_radian = 0;
	else
		additional_radian = (camera->horizontal_angle / 360) * 2 * M_PI;
	parallel_position = real_pos
		* cos(additional_radian)
		- (index->position->z + camera->position->z)
		* sin(additional_radian);
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
	return (perspective_position);
}
