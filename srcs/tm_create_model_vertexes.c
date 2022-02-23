/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tm_create_model_vertexes.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuka < rmatsuka@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 23:28:01 by tkrm              #+#    #+#             */
/*   Updated: 2022/02/23 12:22:30 by rmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tm_create_model_vertexes.h"
#include "term3d.h"

/**
 * <obj file format>
 * #      : Comments
 * mtllib : material file name
 * g      : group name
 * o      : Object name
 * s      : smooth shading toggle
 * usemtl : material name
 * v      : x-component value y-component value z-component value
 * vt     : x-component value y-component value
 * vn     : x-component value y-component value z-component value
 * f      : vertex coordinate number/
 *          texture coordinate number/
 *          vertex normal vector number
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
 * @brief Check that the keyword and number of elements are correct.
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
	if (file_type == FILE_TYPE_3D && !check_line_3d(lines))
		print_error_exit("Invalid `.3d` file format");
	if (file_type == FILE_TYPE_OBJ && !check_line_obj(lines))
		print_error_exit("Invalid `.obj` file format");
}

#define DELIM_OBJ ' '
#define DELIM_3D  ','
#define DELIM_OBJ_CNT 3
#define DELIM_3D_CNT  2

void	delimiter_cnt_exit_if_invalid(char *line, char delim)
{
	size_t	i;
	size_t	cnt;

	i = 0;
	cnt = 0;
	while (line[i])
	{
		if (line[i] == delim)
			cnt += 1;
		i += 1;
	}
	if (delim == DELIM_OBJ && cnt != DELIM_OBJ_CNT && line[1] == 'v' && line[2] == ' ')
		print_error_exit("Invalid number of delimiter");
	if (delim == DELIM_3D && cnt != DELIM_3D_CNT)
		print_error_exit("Invalid number of delimiter");
}

/**
 * @brief Create a model vertexes object
 * @param file_data
 * @param delimiter 3d->','  obj->' '
 */
t_vertex	*create_model_vertexes(const char *file_data, const char delimiter)
{
	char		**line;
	char		**lines;
	const int	offset = (delimiter == FILE_TYPE_OBJ);
	t_vertex	*vt;
	size_t		i;

	lines = tm_split(file_data, '\n');
	vt = NULL;
	i = -1;
	while (lines[++i])
	{
		delimiter_cnt_exit_if_invalid(lines[i], delimiter);
		line = tm_split(lines[i], delimiter);
		check_line_exit_if_invalid((const char **)line, delimiter);
		if (!(offset == 1 && strcmp(line[0], "v") != 0))
		{
			tm_vertex_add_back(&vt, tm_new_vertex(
					tm_new_vector(xstrtod(line[0 + offset]),
						xstrtod(line[1 + offset]), xstrtod(line[2 + offset]))));
		}
		free_double_pointer((void **)line);
	}
	if (vt == NULL)
		print_error_exit("Invalid file format");
	free_double_pointer((void **)lines);
	return (vt);
}
