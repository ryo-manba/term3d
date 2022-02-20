/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_scanf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkrm <tkrm@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 23:28:00 by tkrm              #+#    #+#             */
/*   Updated: 2022/02/20 23:28:00 by tkrm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include <termios.h>
#include <fcntl.h>

#define EOT 4

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
	tcgetattr(STDIN_FILENO, setting);
	setting->c_lflag &= ~(ECHO | ICANON);
	tcsetattr(STDIN_FILENO, TCSANOW, setting);
	fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK);
}

bool	camera_scanf(t_camera *camera)
{
	struct termios	setting;
	int				input_char;

	set_non_blocking_stdin(&setting);
	input_char = getchar();
	tcsetattr(STDIN_FILENO, TCSANOW, &setting);
	fcntl(STDIN_FILENO, F_SETFL, setting);
	return (input_handler(camera, input_char));
}
