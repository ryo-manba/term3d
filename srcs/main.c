#include "term3d.h"
#include "display.h"
#include "rotate.h"
#include "normalize.h"

int main(int argc, char **argv)
{
	t_vertex		*model_vertexes1; // 3Dモデルの頂点情報(連結リスト)
	t_vertex		*model_vertexes2; // 3Dモデルの頂点情報(連結リスト)
	t_vector3		pivot1;
	t_vector3		pivot2;
	char display[DISPLAY_HEIGHT][DISPLAY_WIDTH];

	argc = (int)argc;
	argv = (char **)argv;
	pivot1.x = -15;
	pivot1.y = -2;
	pivot1.z = -1;
	pivot2.x = 15;
	pivot2.y = 2;
	pivot2.z = 1;

	// コマンドライン引数で渡された 3D file のエラーチェック

	// コマンドライン引数で渡された 3D file を構造体に格納
	model_vertexes1 = read_file("./models/torus.3d");
	model_vertexes2 = read_file("./models/torus.3d");

	normalize(model_vertexes1, EXPANSION_RATE);
	normalize(model_vertexes2, EXPANSION_RATE);

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
