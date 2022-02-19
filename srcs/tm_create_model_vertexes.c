#include "tm_create_model_vertexes.h"
#include "term3d.h"

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

static void check_line_exit_ifneed(char **strs)
{
	if (strs[0] == NULL || \
		strs[1] == NULL || \
		strs[2] == NULL)
		print_error_exit("Invalid file format"); // 要素が3つ未満
	if (strs[3] != NULL)
		print_error_exit("Invalid file format"); // 要素が4つ以上
}

/**
 * @brief Create a model vertexes object
 * @param file_data
 * @param delimiter 区切り文字
 * @return t_vertex*
 */
t_vertex	*create_model_vertexes(const char *file_data, const char delimiter)
{
	char		**strs;
	char		**newline_delim_data;
	t_vertex	*vt;
	size_t		i;

	if (file_data == NULL)
		print_error_exit("Invalid file format");
	newline_delim_data = tm_split(file_data, '\n'); // 改行ごとにsplit
	i = 0;
    vt = NULL;
	while (newline_delim_data[i])
	{
		strs = tm_split(newline_delim_data[i], delimiter); // カンマごとにスプリット()
		check_line_exit_ifneed(strs);
		tm_vertex_add_back(&vt,
			tm_new_vertex(
			tm_new_vector(xstrtod(strs[0]), xstrtod(strs[1]), xstrtod(strs[2]))));
		free_double_pointer(strs);
		i += 1;
	}
	free_double_pointer(newline_delim_data);
	return (vt);
}
