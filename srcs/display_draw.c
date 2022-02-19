#include "display.h"

static int	get_display_position(const t_axis axis, const t_camera_mode mode, t_vertex *index, t_camera *camera);

/* 画面を描画 */
void	display_draw(char display[][DISPLAY_WIDTH], const t_vertex *model_vertexes, t_camera_mode mode, t_camera *camera)
{
	t_vertex *index;
	int x;
	int y;

	index = (t_vertex *)model_vertexes;
	while (index != NULL)
	{
		x = get_display_position(X_AXIS, mode, index, camera);
		y = get_display_position(Y_AXIS, mode, index, camera);
		if (y >= DISPLAY_HEIGHT || x >= DISPLAY_WIDTH || y < 0 || x < 0)
		{
			index = index->next;
			continue ;
		}
		display[y][x] = '.';
		index = index->next;
	}
}

static int	get_display_position(const t_axis axis, const t_camera_mode mode, t_vertex *index, t_camera *camera)
{
	if (mode == PERSPECTIVE)
	{
		if (axis == X_AXIS)
			return ((int)floor(index->position->x
					* display_draw_getdepth(index, camera->position, camera->horizontal_angle))
					+ DISPLAY_WIDTH / 2 // 画面中央に移動
					- CAMERA_POSITION_X); // カメラの分移動
		else
			return ((int)floor(index->position->y
					* display_draw_getdepth(index, camera->position, camera->horizontal_angle))
					+ DISPLAY_HEIGHT / 2 // 画面中央に移動
					- CAMERA_POSITION_Y); // カメラの分移動
	}
	else
	{
		if (axis == X_AXIS)
			return ((int)floor(index->position->x) + DISPLAY_WIDTH / 2);
		else
			return ((int)floor(index->position->y) + DISPLAY_HEIGHT / 2);
	}
}
