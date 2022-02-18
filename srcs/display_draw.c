#include "display.h"

static void put(char display[][DISPLAY_WIDTH], const t_vertex *model_vertexes, t_camera_mode mode);
static int	get_display_position(const t_axis axis, const t_camera_mode mode, t_vertex *index);

/* 画面を描画 */
void	display_draw(char display[][DISPLAY_WIDTH], const t_vertex *model_vertexes, t_camera_mode mode)
{
	// モデルのパースをかけてから,頂点のX, yの小数点を切り捨ててディスプレイの二次元配列に格納
	put(display, model_vertexes, mode);
}

static void put(char display[][DISPLAY_WIDTH], const t_vertex *model_vertexes, t_camera_mode mode)
{
	t_vertex *index;
	int x;
	int y;

	index = (t_vertex *)model_vertexes;
	while (index != NULL)
	{
		x = get_display_position(X_AXIS, mode, index);
		y = get_display_position(Y_AXIS, mode, index);
		if (y >= DISPLAY_HEIGHT || x >= DISPLAY_WIDTH || y < 0 || x < 0)
		{
			index = index->next;
			continue ;
		}
		display[y][x] = '.';
		index = index->next;
	}
}

static int	get_display_position(const t_axis axis, const t_camera_mode mode, t_vertex *index)
{
	t_vector3 camera_position;
	t_vector3 camera_rotation;

	camera_position.x = CAMERA_POSITION_X;
	camera_position.y = CAMERA_POSITION_Y;
	camera_position.z = CAMERA_POSITION_Z;
	camera_rotation.x = CAMERA_ANGLE_X;
	camera_rotation.y = CAMERA_ANGLE_Y;
	camera_rotation.z = CAMERA_ANGLE_Z;
	if (mode == PERSPECTIVE)
	{
		if (axis == X_AXIS)
			return ((int)floor(index->position->x
					* display_draw_getdepth(index, &camera_position, &camera_rotation))
					+ DISPLAY_WIDTH / 2 // 画面中央に移動
					- CAMERA_POSITION_X); // カメラの分移動
		else
			return ((int)floor(index->position->y
					* display_draw_getdepth(index, &camera_position, &camera_rotation))
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
