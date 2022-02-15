#include "term3d.h"
#include "input.h"
#include "draw.h"
#include "rotate.h"

int main(int argc, char **argv)
{
	t_vertex		*model_vertexes; // 3Dモデルの頂点情報(連結リスト)
	t_rotation		rotation;        // 回転情報(メインループで使う)
	
	argc = (int)argc;
	argv = (char **)argv;
	model_vertexes = NULL;

	// コマンドライン引数で渡された 3D file のエラーチェック

	// コマンドライン引数で渡された 3D file を構造体に格納

	// メインループ
	while (true)
	{
		// キー入力によって原点を中心に 3D モデルを回転
		rotate(model_vertexes, &rotation);

		// 画面に描画(平面、ボーナスはシェーダー付き)
		draw(model_vertexes);
	}
	// ループ終了

	// 構造体を解放
	return (0);
}
