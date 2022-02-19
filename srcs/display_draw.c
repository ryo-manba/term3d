#include "display.h"

static int	get_screen_position(const t_axis axis, const t_vertex *index, const t_camera *camera);

/* 画面を描画 */
void	display_draw(char display[][DISPLAY_WIDTH], const t_vertex *model_vertexes, const t_camera *camera)
{
	t_vertex *index;
	int x;
	int y;

	index = (t_vertex *)model_vertexes;
	while (index != NULL)
	{
		x = get_screen_position(X_AXIS, index, camera);
		y = get_screen_position(Y_AXIS, index, camera);
		if (y >= DISPLAY_HEIGHT || x >= DISPLAY_WIDTH || y < 0 || x < 0)
		{
			index = index->next;
			continue ;
		}
		display[y][x] = '.';
		index = index->next;
	}
}

static int	get_screen_position(const t_axis axis, const t_vertex *index, const t_camera *camera)
{
	if (axis == X_AXIS)
		return ((int)display_draw_getscreenpos(axis,
												index->position->x,
												index,
												camera)
												+ DISPLAY_WIDTH / 2
												- camera->position->x);
	else
		return ((int)display_draw_getscreenpos(axis,
												index->position->y,
												index,
												camera)
												+ DISPLAY_HEIGHT / 2
												- camera->position->y);
}
