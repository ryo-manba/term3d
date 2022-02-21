/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_draw_getscreenpos.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkanzaki <tkanzaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 23:28:00 by tkrm              #+#    #+#             */
/*   Updated: 2022/02/21 15:22:11 by tkanzaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "vertex.h"
#include "additional_theorem.h"

static double	get_parallel_pos(const t_axis axis,
					const double real_pos,
					const t_vertex *index,
					const t_camera *camera);
static double	get_perspective_pos(const t_axis axis,
					const double real_pos,
					const t_vertex *index,
					const t_camera *camera);
static bool		out_of_view(const t_camera *camera,
					const t_vertex *index, const double real_pos,
					const double additional_radian);

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
	double			additional_radian;
	double			parallel_position;

	additional_radian = (camera->horizontal_angle / 360) * 2 * M_PI;
	if (axis == Y_AXIS)
		parallel_position = real_pos;
	else
	{
		parallel_position = addition_theorem_cos(index->position->x,
				index->position->z, additional_radian);
	}
	parallel_position *= exp((camera->position->z - CAMERA_POSITION_Z)
			/ CAMERA_EXPANSION_SMOOTH_RATE);
	if (axis == Y_AXIS)
		parallel_position *= -1;
	return (parallel_position);
}

static double	get_perspective_pos(const t_axis axis,
	const	double real_pos,
	const	t_vertex *index,
	const	t_camera *camera)
{
	double	original_radian;
	double	additional_radian;
	double	perspective_position;

	original_radian = atan(real_pos
			/ (camera->position->z - index->position->z));
	if (axis == Y_AXIS)
	{
		additional_radian = 0;
	}
	else
	{
		additional_radian = camera->horizontal_angle / 360 * 2 * M_PI;
	}
	perspective_position = camera->position->z
		* addition_theorem_tan(original_radian, (-1) * additional_radian);
	if (axis == Y_AXIS)
		perspective_position *= -1;
	if (out_of_view(camera, index, real_pos, additional_radian))
	{
		perspective_position = DISPLAY_WIDTH;
	}
	return (perspective_position);
}

static bool	out_of_view(const t_camera *camera,
	const t_vertex *index, const double real_pos,
	const double additional_radian)
{
	double	out_of_view;

	out_of_view = (index->position->z - camera->position->z)
		* cos(additional_radian)
		- real_pos * sin(additional_radian);
	if (out_of_view < 0)
	{
		return (true);
	}
	else
	{
		return (false);
	}
}
