#include "display.h"

void	display_print(char display[][DISPLAY_WIDTH])
{
	int	y;

	y = 0;
	while (y < DISPLAY_HEIGHT)
	{
		printf("%s\n", display[y]);
		y++;
	}
}
