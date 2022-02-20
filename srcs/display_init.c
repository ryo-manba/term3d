#include "display.h"

void	display_init(char display[][DISPLAY_WIDTH])
{
	int	x;
	int	y;

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
