/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_draw_getscreenpos.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkanzaki <tkanzaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 23:28:00 by tkrm              #+#    #+#             */
/*   Updated: 2022/02/23 05:59:04 by tkanzaki         ###   ########.fr       */
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
static bool		out_of_view(const t_axis axis, const double vertex_radian);

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
		parallel_position = addition_theorem_cos(index->position.x,
				index->position.z, (-1) * additional_radian);
	}
	parallel_position *= exp((camera->position.z - CAMERA_POSITION_Z)
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
			/ (index->position.z - camera->position.z));
	if (index->position.z - camera->position.z < 0)
		original_radian = M_PI / 2 - original_radian;
	if (axis == Y_AXIS)
		additional_radian = 0;
	else
		additional_radian = (-1) * camera->horizontal_angle / 360 * 2 * M_PI;
	if (out_of_view(axis, original_radian + additional_radian)
		|| index->position.z - camera->position.z == 0)
		return (DISPLAY_WIDTH);
	perspective_position = DISPLAY_DISTANCE
		* addition_theorem_tan(original_radian, additional_radian);
	if (axis == Y_AXIS)
		perspective_position *= -1;
	return (perspective_position);
}

static bool	out_of_view(const t_axis axis, const double vertex_radian)
{
	double	out_of_view;
	double	view_radian;

	return (false);
	if (axis == X_AXIS)
		view_radian = atan((DISPLAY_WIDTH / 2) / DISPLAY_DISTANCE);
	else
		view_radian = atan((DISPLAY_HEIGHT / 2) / DISPLAY_DISTANCE);
	out_of_view = cos(vertex_radian) - cos(view_radian);
	if (out_of_view < 0)
		return (true);
	else
		return (false);
}
