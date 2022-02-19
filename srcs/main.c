#include "term3d.h"
#include "display.h"
#include "rotate.h"
#include "normalize.h"
#include "tm_utils.h"
#include "tm_create_model_vertexes.h"
#include <string.h>

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
	t_vector3		pivot1;
	t_vector3		pivot2;
	char display[DISPLAY_HEIGHT][DISPLAY_WIDTH];

	if (argc != 2)
	{
//		file_name = "./models/torus.3d";
		file_name = "./models/torus_triangle.obj";
//		print_error_exit("Wrong arguments");
	}
	else
		file_name = argv[1];

	// 拡張子が obj か 3d 以外ならexitする
	file_type = check_file_extensions(file_name);

	pivot1.x = -15;
	pivot1.y = -2;
	pivot1.z = -1;
	pivot2.x = 15;
	pivot2.y = 2;
	pivot2.z = 1;

	// コマンドライン引数で渡された 3D file のエラーチェック
	file_data = read_file(file_name);

	// コマンドライン引数で渡された 3D file を構造体に格納
	model_vertexes1 = create_model_vertexes(file_data, file_type);
	model_vertexes2 = create_model_vertexes(file_data, file_type);

	normalize(model_vertexes1, EXPANSION_RATE1);
	normalize(model_vertexes2, EXPANSION_RATE2);

	// メインループ
	while (true)
	{
		// 原点を中心に 3D モデルを回転
		rotate(model_vertexes1, X_AXIS, ANGLE1_X_PER_FRAME, &pivot1);
		rotate(model_vertexes1, Y_AXIS, ANGLE1_Y_PER_FRAME, &pivot1);
		rotate(model_vertexes1, Z_AXIS, ANGLE1_Z_PER_FRAME, &pivot1);
		rotate(model_vertexes2, X_AXIS, ANGLE2_X_PER_FRAME, &pivot2);
		rotate(model_vertexes2, Y_AXIS, ANGLE2_Y_PER_FRAME, &pivot2);
		rotate(model_vertexes2, Z_AXIS, ANGLE2_Z_PER_FRAME, &pivot2);

		// 画面クリア
		printf("\x1b[H");

		// 画面初期化
		display_init(display);

		// 画面に描画
		display_draw(display, model_vertexes1, PERSPECTIVE);
		display_draw(display, model_vertexes2, PERSPECTIVE);

		// 画面出力
		display_print(display);

		// 1秒待機
		usleep(1000 * 1000 / FRAMES_PER_SECOND);

		//return (0);
	}
	// ループ終了

	// 構造体を解放
	return (0);
}
