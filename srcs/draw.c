#include "draw.h"

static void init(char display[][DISPLAY_WIDTH]);
static void put(char display[][DISPLAY_WIDTH], const t_vertex *model_vertexes, t_camera_mode mode);
static void print(char display[][DISPLAY_WIDTH]);

/* 画面を描画 */
void	draw(const t_vertex *model_vertexes, t_camera_mode mode)
{
	char display[DISPLAY_HEIGHT][DISPLAY_WIDTH];

	// displayをスペースで初期化
	init(display);

	// モデルの頂点のX, y座標の整数部のdisplayをASCII文字に上書き
	put(display, model_vertexes, mode);

	// displayを出力
	print(display);
}

static void init(char display[][DISPLAY_WIDTH])
{
	int x;
	int y;

	y = 0;
	while (y < DISPLAY_HEIGHT)
	{
		x = 0;
		while (x < DISPLAY_WIDTH - 1)
		{
			display[y][x] = ' ';
			x++;
		}
		display[y][x] = '\0';
		y++;
	}
}

static void put(char display[][DISPLAY_WIDTH], const t_vertex *model_vertexes, t_camera_mode mode)
{
	t_vertex *index;
	int x;
	int y;

	index = (t_vertex *)model_vertexes;
	while (index != NULL)
	{
		if (mode == PERSPECTIVE)
		{
			x = (int)floor(index->position->x * CAMERA_POSITION_Z / (CAMERA_POSITION_Z - index->position->z)) + DISPLAY_WIDTH / 2;
			y = (int)floor(index->position->y * CAMERA_POSITION_Z / (CAMERA_POSITION_Z - index->position->z)) + DISPLAY_HEIGHT / 2;
		}
		else
		{
			x = (int)floor(index->position->x) + DISPLAY_WIDTH / 2;
			y = (int)floor(index->position->y) + DISPLAY_HEIGHT / 2;
		}
		if (y >= DISPLAY_HEIGHT || x >= DISPLAY_WIDTH || y < 0 || x < 0)
		{
			index = index->next;
			continue ;
		}
		display[y][x] = '.';
		index = index->next;
	}
}

static void print(char display[][DISPLAY_WIDTH])
{
	int	y;

	y = 0;
	while (y < DISPLAY_HEIGHT)
	{
		printf("%s\n", display[y]);
		y++;
	}
}
