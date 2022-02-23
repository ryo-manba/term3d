/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkanzaki <tkanzaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 23:28:00 by tkrm              #+#    #+#             */
/*   Updated: 2022/02/23 13:39:33 by tkanzaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

static int	get_screen_position(const t_axis axis,
				const t_vertex *index,
				const t_camera *camera);

void	display_draw(char display[][DISPLAY_WIDTH],
	const t_vertex *model_vertexes, const t_camera *camera)
{
	t_vertex	*index;
	int			x;
	int			y;

	index = (t_vertex *)model_vertexes;
	while (true)
	{
		x = get_screen_position(X_AXIS, index, camera);
		y = get_screen_position(Y_AXIS, index, camera);
		if ((0 <= y && y <= DISPLAY_HEIGHT - 1) && \
			(0 <= x && x < DISPLAY_WIDTH - 1))
		{
			display[y][x] = '.';
		}
		index = index->next;
		if (index == index->head)
			break ;
	}
}

static int	get_screen_position(const t_axis axis,
	const t_vertex *index,
	const t_camera *camera)
{
	if (axis == X_AXIS)
		return ((int)display_draw_getscreenpos(axis,
				index->position.x,
				index,
				camera)
			+ DISPLAY_WIDTH / 2
			- camera->position.x);
	else
		return ((int)display_draw_getscreenpos(axis,
				index->position.y,
				index,
				camera)
			+ DISPLAY_HEIGHT / 2
			- camera->position.y);
}
