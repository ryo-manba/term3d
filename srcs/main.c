#include "term3d.h"
#include "display.h"
#include "vertex.h"
#include "camera.h"
#include "tm_utils.h"
#include "tm_create_model_vertexes.h"
#include <string.h>
#include <termios.h>
#include <fcntl.h>

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

int main(int argc, char **argv)
{
	char			*file_data;
	char			file_type;
	char			*file_name;
	t_vertex		*model_vertexes1; // 3Dモデルの頂点情報(連結リスト)
	t_vertex		*model_vertexes2; // 3Dモデルの頂点情報(連結リスト)
	char			display[DISPLAY_HEIGHT][DISPLAY_WIDTH];
	t_vector3		pivot1;
	t_vector3		pivot2;
	t_camera		*camera;
	int				input_c;
	bool			input_flag;

	if (argc != 2)
	{
		//file_name = "./models/torus.3d";
		file_name = "./models/torus_triangle.obj";
//		print_error_exit("Wrong arguments");
	}
	else
		file_name = argv[1];

	// 拡張子が obj か 3d 以外ならexitする
	file_type = check_file_extensions(file_name);

	// コマンドライン引数で渡された 3D file のエラーチェック
	file_data = read_file(file_name);

	// 入力フラグ初期化
	input_flag = false;

	// ピボット初期化
	pivot1.x = OBJ1_PIVOT_X;
	pivot1.y = OBJ1_PIVOT_Y;
	pivot1.z = OBJ1_PIVOT_Z;
	pivot2.x = OBJ2_PIVOT_X;
	pivot2.y = OBJ2_PIVOT_Y;
	pivot2.z = OBJ2_PIVOT_Z;

	// カメラ初期化
	camera = camera_init();

	// コマンドライン引数で渡された 3D file を構造体に格納
	model_vertexes1 = create_model_vertexes(file_data, file_type);
	model_vertexes2 = create_model_vertexes(file_data, file_type);

	// 3Dモデルのスケールを既定値に
	vertex_expandall(model_vertexes1, OBJ1_EXPANSION_RATE);
	vertex_expandall(model_vertexes2, OBJ2_EXPANSION_RATE);

	// メインループ
	while (true)
	{
		// 入力をとってカメラ制御。EOFがきたらbreak
		if (camera_scanf(camera, &input_c, &input_flag))
		{
			break ;
		}

		// ピボットを中心に 3D モデルを回転
		vertex_rotateall(model_vertexes1, X_AXIS, OBJ1_ROTATE_SPEED_X, &pivot1);
		vertex_rotateall(model_vertexes1, Y_AXIS, OBJ1_ROTATE_SPEED_Y, &pivot1);
		vertex_rotateall(model_vertexes1, Z_AXIS, OBJ1_ROTATE_SPEED_Z, &pivot1);
		vertex_rotateall(model_vertexes2, X_AXIS, OBJ2_ROTATE_SPEED_X, &pivot2);
		vertex_rotateall(model_vertexes2, Y_AXIS, OBJ2_ROTATE_SPEED_Y, &pivot2);
		vertex_rotateall(model_vertexes2, Z_AXIS, OBJ2_ROTATE_SPEED_Z, &pivot2);

		// 画面クリア
		printf("\x1b[H");

		// 画面初期化
		display_init(display);

		// 画面に描画
		display_draw(display, model_vertexes1, camera);
		display_draw(display, model_vertexes2, camera);

		// 画面出力
		display_print(display);

		// 1フレーム待機
		usleep(1000 * 1000 / FRAMES_PER_SECOND);
	}
	// ループ終了

	// 構造体を解放
	camera_destory(camera);

	return (0);
}
