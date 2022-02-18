#include "term3d.h"
#include "draw.h"
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
	t_vertex		*model_vertexes; // 3Dモデルの頂点情報(連結リスト)
	char			*file_data;
	char			file_type;

	if (argc != 2)
		print_error_exit("Wrong arguments");
	file_type = check_file_extensions(argv[1]); // .obj or .3d で処理を分岐

	// コマンドライン引数で渡された 3D file のエラーチェック
//	read_file("./models/torus.3d");
	file_data = read_file(argv[1]);

	// コマンドライン引数で渡された 3D file を構造体に格納
	model_vertexes = create_model_vertexes(file_data, file_type);

	normalize(model_vertexes, EXPANSION_RATE);

	// メインループ
	while (true)
	{
		// 原点を中心に 3D モデルを回転
		rotate(model_vertexes, X_AXIS, ANGLE_X_PER_FRAME);
		rotate(model_vertexes, Y_AXIS, ANGLE_Y_PER_FRAME);
		rotate(model_vertexes, Z_AXIS, ANGLE_Z_PER_FRAME);

		// 画面クリア
		printf("\x1b[H");

		// 画面に描画(平面、ボーナスはシェーダー付き)
		draw(model_vertexes, PERSPECTIVE);

		// 1秒待機
		usleep(1000 * 1000 / FRAMES_PER_SECOND);

		//return (0);
	}
	// ループ終了

	// 構造体を解放
	return (0);
}
