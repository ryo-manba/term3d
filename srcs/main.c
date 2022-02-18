#include "term3d.h"
#include "draw.h"
#include "rotate.h"
#include "normalize.h"

int main(int argc, char **argv)
{
	t_vertex		*model_vertexes; // 3Dモデルの頂点情報(連結リスト)

	argc = (int)argc;
	argv = (char **)argv;

	// コマンドライン引数で渡された 3D file のエラーチェック

	// コマンドライン引数で渡された 3D file を構造体に格納
	model_vertexes = read_file("./models/torus.3d");

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
