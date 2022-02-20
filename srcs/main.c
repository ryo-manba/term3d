#include "term3d.h"
#include "display.h"
#include "vertex.h"
#include "camera.h"
#include "tm_utils.h"
#include "tm_create_model_vertexes.h"
#include <signal.h>
#define DISABLE_CURSOR "\033[?25l"
#define ENABLE_CURSOR  "\033[?25h"
#define SCREEN_CLEAR   "\033[2J"
#define MOVE_CURSOR    "\033[H"

/**
 * @brief Set the scale of the 3D model to the default value
 */
static void	set_scale(t_vertex **model_vertexes, int nb_models)
{
	int	i;
	int	scale;

	i = 0;
	scale = OBJ_EXPANSION_RATE;
	while (i < nb_models)
	{
		vertex_expandall(model_vertexes[i], scale);
		i += 1;
		scale += 1;
	}
}

/**
 * @brief Rotate the 3D model around the pivot
 */
static void	models_rotate(t_vertex **vertexes, t_vector3 *pivots, int nb_models)
{
	int	i;

	i = 0;
	while (i < nb_models)
	{
		vertex_rotateall(vertexes[i], X_AXIS,
			OBJ_ROTATE_SPEED_X + i, &pivots[i]);
		vertex_rotateall(vertexes[i], Y_AXIS,
			OBJ_ROTATE_SPEED_Y + i, &pivots[i]);
		vertex_rotateall(vertexes[i], Z_AXIS,
			OBJ_ROTATE_SPEED_Z + i, &pivots[i]);
		i += 1;
	}
}

static void	models_print(
		t_vertex **vertexes, t_camera *camera,
		char display[DISPLAY_HEIGHT][DISPLAY_WIDTH], int nb_models)
{
	int	i;

	printf(SCREEN_CLEAR);
	printf(MOVE_CURSOR);
	display_init(display);
	i = 0;
	while (i < nb_models)
	{
		display_draw(display, vertexes[i], camera);
		i += 1;
	}
	display_print(display);
}

static void	signal_off(int signal1, int signal2)
{
	if (signal(signal1, SIG_IGN) == SIG_ERR || \
		signal(signal2, SIG_IGN) == SIG_ERR)
	{
		print_error_exit("Signal error");
	}
}

int	main(int argc, char **argv)
{
	char		display[DISPLAY_HEIGHT][DISPLAY_WIDTH];
	t_vertex	*model_vertexes[MAX_MODEL_SIZE];
	t_vector3	pivots[MAX_MODEL_SIZE];
	t_camera	*camera;

	check_argc_exit_if_invalid(argc);
	init_model_vertexes(model_vertexes, argc - 1, argv + 1);
	init_pivots(pivots, argc - 1);
	camera = camera_init();
	set_scale(model_vertexes, argc - 1);
	signal_off(SIGINT, SIGQUIT);
	printf(DISABLE_CURSOR);
	while (!camera_scanf(camera))
	{
		camera_control(camera);
		models_rotate(model_vertexes, pivots, argc - 1);
		models_print(model_vertexes, camera, display, argc - 1);
		usleep(1000 * 1000 / FRAMES_PER_SECOND);
	}
	destroy_all(model_vertexes, camera);
	printf(ENABLE_CURSOR);
	return (0);
}
