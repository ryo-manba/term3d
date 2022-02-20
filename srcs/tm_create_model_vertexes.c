#include "tm_create_model_vertexes.h"
#include "term3d.h"

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
 * f  頂点座標値番号/テクスチャ座標値番号/頂点法線ベクトル番号 (多角形の頂点の数だけ続く）
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

/**
 * @brief keywordと要素数が正しいかチェックする。
 * @param strs
 */
static bool	check_line_obj(const char **lines)
{
	int	type;
	int	i;

	if (lines[0] == NULL)
		return (false);
	type = check_obj_type(lines[0]);
	if (type == OBJ_NONEXISTENT_KEYWORD)
		return (false);
	if (type == OBJ_COMMENT)
		return (true);
	i = 0;
	while (i <= type)
	{
		if (lines[i] == NULL)
			return (false);
		i += 1;
	}
	return (lines[i] == NULL);
}

/**
 * @return 要素が3つの場合 true
 */
static bool	check_line_3d(const char **lines)
{
	if (lines[0] == NULL || \
		lines[1] == NULL || \
		lines[2] == NULL || \
		lines[3] != NULL)
		return (false);
	return (true);
}

static void	check_line_exit_if_invalid(const char **lines, const char file_type)
{
	if (file_type == FILE_TYPE_THREED && !check_line_3d(lines))
		print_error_exit("Invalid `.3d` file format");
	if (file_type == FILE_TYPE_OBJ && !check_line_obj(lines))
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
	const int	offset = (delimiter == FILE_TYPE_OBJ);
	t_vertex	*vt;
	size_t		i;

	if (file_data == NULL)
		print_error_exit("File is empty");
	newline_delim_data = tm_split(file_data, '\n');
	vt = NULL;
	i = -1;
	while (newline_delim_data[++i])
	{
		strs = tm_split(newline_delim_data[i], delimiter);
		check_line_exit_if_invalid((const char **)strs, delimiter);
		if (!(offset == 1 && strcmp(strs[0], "v") != 0))
		{
			tm_vertex_add_back(&vt, tm_new_vertex(
					tm_new_vector(xstrtod(strs[0 + offset]),
						xstrtod(strs[1 + offset]), xstrtod(strs[2 + offset]))));
		}
		free_double_pointer((void **)strs);
	}
	free_double_pointer((void **)newline_delim_data);
	return (vt);
}
