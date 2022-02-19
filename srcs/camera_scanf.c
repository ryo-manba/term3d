#include "camera.h"

bool	camera_scanf(t_camera *camera, int *input_char, bool *input_flag)
{
	*input_char = getchar();
	// if (*input_char == EOF && *input_flag == true)
	// 	return (true);
	if (*input_char == 'w')
		camera->position->z++;
	else if (*input_char == 'a')
		camera->position->x--;
	else if (*input_char == 's')
		camera->position->z--;
	else if (*input_char == 'd')
		camera->position->x++;
	else if (*input_char == 'q')
		camera->position->y--;
	else if (*input_char == 'e')
		camera->position->y++;
	else if (*input_char == 'j')
		camera->horizontal_angle--;
	else if (*input_char == 'l')
		camera->horizontal_angle++;
	else
		return (false);
	*input_flag = true;
	return (false);
}
