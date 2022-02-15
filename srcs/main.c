#include "term3d.h"
#include "input.h"
#include "draw.h"
#include "rotate.h"

int main(int argc, char **argv)
{
	t_vertex		*model_vertexes; // 3Dモデルの頂点情報(連結リスト)
	t_rotation		rotation;        // 回転情報(メインループで使う)
	t_input_error	input_error;     // 入力エラー

	// コマンドライン引数で渡された 3D file のエラーチェック

	// コマンドライン引数で渡された 3D file を構造体に格納

	// 3D file からピボットポイント( 回転の中心となる点 )を生成

	// ピボットから原点に 3D モデルを平行移動

	// 3Dモデルを正規化

	// メインループ
	while (true)
	{
		// 上下左右のキー入力を取得(キー入力まで待機？？)
		input_error = input(&rotation);
		if (input_error == TERMINATED)
		{
			// 不正な入力は無視
			continue ;
		}
		if (input_error == INVALID)
		{
			// 3Dモデルを解放
			// プログラム終了
			return  ;
		}

		// キー入力によって原点を中心に 3D モデルを回転
		rotate(model_vertexes, &rotation);

		// 画面に描画(平面、ボーナスはシェーダー付き)
		draw(model_vertexes);
	}
	// ループ終了

	// 構造体を解放
	return (0);
}
