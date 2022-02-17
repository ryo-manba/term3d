#include "draw.h"

/* 画面を描画 */
void	draw(const t_vertex *model_vertexes)
{
	char display[DISPLAY_HEIGHT][DISPLAY_WIDTH];
	int x;
	int y;
	t_vertex *index;

	// displayをスペースで初期化
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

	// モデルの頂点のX, y座標の整数部のdisplayをASCII文字に上書き
	index = (t_vertex *)model_vertexes;
	while (index != NULL)
	{
		x = (int)floor(index->position->x) + DISPLAY_WIDTH / 2;
		y = (int)floor(index->position->y) + DISPLAY_HEIGHT / 2;
		if (y >= DISPLAY_HEIGHT || x >= DISPLAY_WIDTH || y < 0 || x < 0)
		{
			index = index->next;
			continue ;
		}
		display[y][x] = '.';
		index = index->next;
	}

	// displayを出力
	y = 0;
	while (y < DISPLAY_HEIGHT)
	{
		printf("%s\n", display[y]);
		y++;
	}
}
