#include "camera.h"
#include <termios.h>
#include <fcntl.h>

static void	set_non_blocking_stdin(struct termios *setting);

bool	camera_scanf(t_camera *camera, int *input_char, bool *input_flag)
{
	struct termios setting;

	// 標準入力ノンブロッキング
	set_non_blocking_stdin(&setting);
	*input_char = getchar();
	tcsetattr(STDIN_FILENO, TCSANOW, &setting);
	fcntl(STDIN_FILENO, F_SETFL, setting);
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
		camera->horizontal_angle++;
	else if (*input_char == 'l')
		camera->horizontal_angle--;
	else
		return (false);
	*input_flag = true;
	return (false);
}

/* 標準入力をノンブロッキング */
static void	set_non_blocking_stdin(struct termios *setting)
{
	tcgetattr(STDIN_FILENO, setting);
	setting->c_lflag &= ~(ECHO | ICANON);
	tcsetattr(STDIN_FILENO, TCSANOW, setting);
	fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK);
}
