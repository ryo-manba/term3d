/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuka < rmatsuka@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 23:28:00 by tkrm              #+#    #+#             */
/*   Updated: 2022/02/21 23:30:15 by rmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term3d.h"
#include "display.h"
#include "vertex.h"
#include "camera.h"
#include "tm_utils.h"
#include "tm_create_model_vertexes.h"
#include <signal.h>
#define DISABLE_CURSOR       "\033[?25l"
#define ENABLE_CURSOR        "\033[?25h"
#define SCREEN_CLEAR         "\033[2J"
#define RETURN_TO_TOP_CURSOR "\033[H"

static void	signal_off(int signal1, int signal2)
{
	if (signal(signal1, SIG_IGN) == SIG_ERR || \
		signal(signal2, SIG_IGN) == SIG_ERR)
	{
		print_error_exit("Signal error");
	}
}

static void	models_print(
		t_vertex **vertexes, t_camera *camera,
		char display[DISPLAY_HEIGHT][DISPLAY_WIDTH], int nb_models)
{
	int	i;

	printf(RETURN_TO_TOP_CURSOR);
	display_init(display);
	i = 0;
	while (i < nb_models)
	{
		display_draw(display, vertexes[i], camera);
		i += 1;
	}
	display_print(display);
}

static void	print_help_message(void)
{
	printf(""
		"----------------help-----------------\n"
		"|[CTRL+D]       -  Close the window |\n"
		"|[W]            -  Zoom in          |\n"
		"|[S]            -  Zoom out         |\n"
		"|[ADQE]         -  Display moves    |\n"
		"|[JL]           -  Rotate camera    |\n"
		"-------------------------------------\n");
}

static void	main_loop(t_vertex *model_vertexes[MAX_MODEL_SIZE],
					t_vector3 pivots[MAX_MODEL_SIZE],
					t_camera *camera, const int nb_models)
{
	char	display[DISPLAY_HEIGHT][DISPLAY_WIDTH];
	bool	first_time;

	first_time = true;
	while (!camera_scanf(camera))
	{
		camera_control(camera);
		models_rotate(model_vertexes, pivots, nb_models);
		models_print(model_vertexes, camera, display, nb_models);
		if (first_time == true)
		{
			print_help_message();
			first_time = false;
		}
		usleep(1000 * 1000 / FRAMES_PER_SECOND);
	}
}

int	main(int argc, char **argv)
{
	t_vertex	*model_vertexes[MAX_MODEL_SIZE];
	t_vector3	pivots[MAX_MODEL_SIZE];
	t_camera	*camera;
	const int	nb_models = argc - 1;

	check_argc_exit_if_invalid(argc);
	init_model_vertexes(model_vertexes, nb_models, argv + 1);
	init_pivots(pivots, nb_models);
	camera = camera_init();
	set_scale(model_vertexes, nb_models);
	signal_off(SIGINT, SIGQUIT);
	printf("%s%s", DISABLE_CURSOR, SCREEN_CLEAR);
	main_loop(model_vertexes, pivots, camera, nb_models);
	destroy_all(model_vertexes, camera);
	printf(ENABLE_CURSOR);
	return (0);
}
