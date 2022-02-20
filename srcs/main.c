#include "term3d.h"
#include "display.h"
#include "vertex.h"
#include "camera.h"
#include "tm_utils.h"
#include "tm_create_model_vertexes.h"
#include <string.h>
#include <signal.h>
/*
__attribute__((destructor))
static void destructor() {
    system("leaks -q term3d");
}
*/
# define DISABLE_CURSOR "\033[?25l"
# define ENABLE_CURSOR "\033[?25h"

static char	check_file_extensions(const char *filename)
{
	char	*p;

	p = strrchr(filename, '.');
	if (p == NULL)
		print_error_exit("Invalid extension");
	else if (strcmp(p, ".3d") == 0)
		return (FILE_TYPE_THREED);
	else if (strcmp(p, ".obj") == 0)
		return (FILE_TYPE_OBJ);
	print_error_exit("Invalid extension");
	return ('*');
}

static void check_argc_exit_if_invalid(int argc)
{
	if (argc == 2 || argc == 3)
		return ;
	printf("Usage: ./term3d file_path [file_path]\n");
	exit(1);
}

static void	init_model_vertexes(t_vertex *vertexes[3], int nb_models, char **file_paths)
{
	char	*file_data;
	char	*file_name;
	char	file_type;
	int		i;

	i = 0;
	while (i < nb_models)
	{
		file_name = file_paths[i];
		file_type = check_file_extensions(file_name);
		file_data = read_file(file_name);
		vertexes[i] = create_model_vertexes(file_data, file_type);
		free(file_data);
		i += 1;
	}
	vertexes[nb_models] = NULL;
}

static void init_pivots(t_vector3 *pivots, int nb_models)
{
	int	i;
	int	sign;

	sign = 1;
	i = 0;
	while (i < nb_models)
	{
		pivots[i].x = OBJ1_PIVOT_X * sign;
		pivots[i].y = OBJ1_PIVOT_Y * sign;
		pivots[i].z = OBJ1_PIVOT_Z * sign;
		sign *= 1;
		i += 1;
	}
}

static void	vertex_expander(t_vertex **model_vertexes, int nb_models)
{
	int	i;
	int	scale;

	i = 0;
	scale = OBJ1_EXPANSION_RATE;
	while (i < nb_models)
	{
		vertex_expandall(model_vertexes[i], scale);
		i += 1;
		scale += 1;
	}
}

static void	models_rotate(t_vertex **vertexes, t_vector3 *pivots, int nb_models)
{
	int	i;

	i = 0;
	while (i < nb_models)
	{
		vertex_rotateall(vertexes[i], X_AXIS, OBJ1_ROTATE_SPEED_X + i, &pivots[i]);
		vertex_rotateall(vertexes[i], Y_AXIS, OBJ1_ROTATE_SPEED_Y + i, &pivots[i]);
		vertex_rotateall(vertexes[i], Z_AXIS, OBJ1_ROTATE_SPEED_Z + i, &pivots[i]);
		i += 1;
	}
}

void	display_models(t_vertex **vertexes, t_camera *camera, char display[DISPLAY_HEIGHT][DISPLAY_WIDTH], int nb_models)
{
	int	i;

	printf("\033[2J"); // 画面クリア
	printf("\033[H"); // カーソル移動
	// 画面初期化
	display_init(display);
	i = 0;
	while (i < nb_models)
	{
		// 画面に描画
		display_draw(display, vertexes[i], camera);
		i += 1;
	}
	// 画面出力
	display_print(display);
}

void	signal_off(int signal1, int signal2)
{
	if (signal(signal1, SIG_IGN) == SIG_ERR ||
		signal(signal2, SIG_IGN) == SIG_ERR)
	{
		print_error_exit("Signal error");
	}
}

void	destroy_vertexes(t_vertex **vertexes)
{
	t_vertex *vt;
	t_vertex *tmp;
	int	i;

	i = 0;
	while (vertexes[i])
	{
		vt = vertexes[i];
		while (vt)
		{
			tmp = vt;
			vt = vt->next;
			free(tmp->position);
			free(tmp);
		}
		i += 1;
	}
	free(vertexes[i]);
}

void destroy_vector(t_vector3 **vec)
{
	int	i;

	i = 0;
	while (vec[i])
	{
		free(vec[i]);
		i += 1;
	}
	free(vec[i]);
}

static void destroy_all(t_vertex **vertexes, t_camera *camera)
{
	destroy_vertexes(vertexes);
	destroy_camera(camera); // 構造体を解放
}

int main(int argc, char **argv)
{
	char			display[DISPLAY_HEIGHT][DISPLAY_WIDTH];
	t_vertex		*model_vertexes[3]; // 3Dモデルの頂点情報(連結リスト)
	t_vector3		pivots[2];
	t_camera		*camera;
	int				input_c;
	bool			input_flag;

	check_argc_exit_if_invalid(argc); // 引数が 1 or 2 以外ならアウト
	init_model_vertexes(model_vertexes, argc - 1, argv + 1); // コマンドライン引数で渡された 3D file を構造体に格納
	init_pivots(pivots, argc - 1);
	camera = camera_init(); // カメラ初期化
	vertex_expander(model_vertexes, argc - 1); // 3Dモデルのスケールを既定値に
	input_flag = false;  // 入力フラグ初期化

	signal_off(SIGINT, SIGQUIT);
	printf("%s", DISABLE_CURSOR);
	while (!camera_scanf(camera, &input_c, &input_flag))
	{
		camera_control(camera); // カメラ制御
		models_rotate(model_vertexes, pivots, argc - 1); // ピボットを中心に 3D モデルを回転
		display_models(model_vertexes, camera, display, argc - 1);
		usleep(1000 * 1000 / FRAMES_PER_SECOND); // 1フレーム待機
	}
	destroy_all(model_vertexes, camera);
	printf("%s", ENABLE_CURSOR);
	return (0);
}
