#include "tm_create_model_vertexes.h"
#include "term3d.h"

#define OBJ_COMMENT 1
#define OBJ_NAME 1
#define OBJ_SMOOTH_SHADING 1
#define OBJ_MTLLIB 1
#define OBJ_GROUP 1
#define OBJ_USEMTL 1
#define OBJ_VERTEX_COORDINATE_VALUE 3
#define OBJ_VERTEX_TEXTURE 2
#define OBJ_VERTEX_NORMAL_VECTOR 3
#define OBJ_POLYGONAL_SUFACE_DATA 3 // ポリゴンデータは三角の場合のみ対応
#define OBJ_NONEXISTENT_KEYWORD -1

static void free_double_pointer(char **dp)
{
	size_t	i;

	i = 0;
	while (dp[i])
	{
		free(dp[i]);
		i += 1;
	}
	free(dp[i]);
	free(dp);
}

/**
 * <objファイル形式>
 * # コメント
 * mtllib マテリアルファイル名
 * g グループ名
 * o オブジェクト名
 * s スムーズシェーディングの切り替え
 * usemtl マテリアル名
 * v  x成分値 y成分値 z成分値
 * vt x成分値 y成分値
 * vn x成分値 y成分値 z成分値
 * f 頂点座標値番号/テクスチャ座標値番号/頂点法線ベクトル番号 (多角形の頂点の数だけ続く）
 * [参考] https://www.hiramine.com/programming/3dmodelfileformat/objfileformat.html
 */
static int	check_obj_type(const char *keyword)
{
	if (strcmp(keyword, "#") == 0)
		return (OBJ_COMMENT);
	if (strcmp(keyword, "o") == 0)
		return (OBJ_NAME);
	if (strcmp(keyword, "s") == 0)
		return (OBJ_SMOOTH_SHADING);
	if (strcmp(keyword, "mtllib") == 0)
		return (OBJ_MTLLIB);
	if (strcmp(keyword, "g") == 0)
		return (OBJ_GROUP);
	if (strcmp(keyword, "usemtl") == 0)
		return (OBJ_USEMTL);
	if (strcmp(keyword, "v") == 0)
		return (OBJ_VERTEX_COORDINATE_VALUE);
	if (strcmp(keyword, "vt") == 0)
		return (OBJ_VERTEX_TEXTURE);
	if (strcmp(keyword, "vn") == 0)
		return (OBJ_VERTEX_NORMAL_VECTOR);
	if (strcmp(keyword, "f") == 0)
		return (OBJ_POLYGONAL_SUFACE_DATA);
	return (OBJ_NONEXISTENT_KEYWORD);
}

static bool	check_line_obj(const char **strs)
{
	int	type;
	int	i;

	if (strs[0] == NULL)
		return (false);
	type = check_obj_type(strs[0]);
	if (type == OBJ_NONEXISTENT_KEYWORD)
		return (false);
	if (type == OBJ_COMMENT) // 後ろに何があってもいい
		return (true);
	i = 0;
	while (i <= type)
	{
		if (strs[i] == NULL)
			return (false);
		i += 1;
	}
	return (strs[i] == NULL);
}

/**
 * @return 要素が3つの場合 true
 */
static bool	check_line_3d(const char **strs)
{
	if (strs[0] == NULL || \
		strs[1] == NULL || \
		strs[2] == NULL || \
		strs[3] != NULL)
		return (false);
	return (true);
}

static void check_line_exit_if_invalid(const char **strs, const char file_type)
{
	if (file_type == FILE_TYPE_THREED && !check_line_3d(strs))
		print_error_exit("Invalid `.3d` file format");
	if (file_type == FILE_TYPE_OBJ && !check_line_obj(strs))
		print_error_exit("Invalid `.obj` file format");
}

/**
 * @brief Create a model vertexes object
 * @param file_data
 * @param delimiter 区切り文字 :.3d->',' .obj->' '
 * @return t_vertex*
 */
t_vertex	*create_model_vertexes(const char *file_data, const char delimiter)
{
	char		**strs;
	char		**newline_delim_data;
	t_vertex	*vt;
	size_t		i;
	int			offset;

	if (file_data == NULL)
		print_error_exit("File is empty");
	newline_delim_data = tm_split(file_data, '\n'); // 改行ごとにsplit
	i = 0;
	offset = (delimiter == FILE_TYPE_OBJ);
    vt = NULL;
	while (newline_delim_data[i])
	{
		strs = tm_split(newline_delim_data[i], delimiter); // 区切り文字ごとにスプリット
		check_line_exit_if_invalid((const char**)strs, delimiter);
		if (strcmp(strs[0], "v") != 0)
 		{
 			i += 1;
 			continue;
 		}
		tm_vertex_add_back(&vt,
			tm_new_vertex(
			tm_new_vector(xstrtod(strs[0 + offset]),
						  xstrtod(strs[1 + offset]),
						  xstrtod(strs[2 + offset]))));
		free_double_pointer(strs);
		i += 1;
	}
	free_double_pointer(newline_delim_data);
	return (vt);
}
