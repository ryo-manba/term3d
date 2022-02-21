/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_scanf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuka < rmatsuka@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 23:28:00 by tkrm              #+#    #+#             */
/*   Updated: 2022/02/21 22:25:31 by rmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include <termios.h>
#include <fcntl.h>
#include "tm_utils.h"

#define EOT 4

static int	xtcsetattr(
		int fildes, int optional_actions, const struct termios *termios_p)
{
	if (tcsetattr(fildes, optional_actions, termios_p) == -1)
		print_error_exit(NULL);
	return (0);
}

static int	xtcgetattr(int fildes, struct termios *termios_p)
{
	if (tcgetattr(fildes, termios_p) == -1)
		print_error_exit(NULL);
	return (0);
}

static bool	input_handler(t_camera *camera, int input_char)
{
	if (input_char == EOT)
		return (true);
	if (input_char == 'w')
		camera->position->z++;
	else if (input_char == 'a')
		camera->position->x--;
	else if (input_char == 's')
		camera->position->z--;
	else if (input_char == 'd')
		camera->position->x++;
	else if (input_char == 'q')
		camera->position->y--;
	else if (input_char == 'e')
		camera->position->y++;
	else if (input_char == 'j')
		camera->horizontal_angle++;
	else if (input_char == 'l')
		camera->horizontal_angle--;
	return (false);
}

static void	set_non_blocking_stdin(struct termios *setting)
{
	xtcgetattr(STDIN_FILENO, setting);
	setting->c_lflag &= ~(ECHO | ICANON);
	xtcsetattr(STDIN_FILENO, TCSANOW, setting);
	if (fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK) == -1)
		print_error_exit(NULL);
}

bool	camera_scanf(t_camera *camera)
{
	struct termios	setting;
	int				input_char;

	set_non_blocking_stdin(&setting);
	input_char = getchar();
	xtcsetattr(STDIN_FILENO, TCSANOW, &setting);
	if (fcntl(STDIN_FILENO, F_SETFL, setting) == 1)
		print_error_exit(NULL);
	return (input_handler(camera, input_char));
}
