/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tm_create_model_vertexes.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuka < rmatsuka@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 23:28:01 by tkrm              #+#    #+#             */
/*   Updated: 2022/02/23 14:27:28 by rmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tm_create_model_vertexes.h"
#include "tm_check_file.h"
#include "term3d.h"

#define DELIM_OBJ ' '
#define DELIM_3D  ','
#define DELIM_3D_CNT  2

static void	check_line_exit_if_invalid(const char **split_line, const char file_type)
{
	if (file_type == FILE_TYPE_3D && !check_line_3d(split_line))
		print_error_exit("Invalid `.3d` file format");
	if (file_type == FILE_TYPE_OBJ && !check_line_obj(split_line))
		print_error_exit("Invalid `.obj` file format");
}

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
	if (delim == DELIM_3D && cnt != DELIM_3D_CNT)
		print_error_exit("Invalid number of delimiter");
}

t_vertex	*create_3d(char **lines)
{
	int			i;
	char		**line;
	t_vertex	*vt;

	i = 0;
	vt = NULL;
	while (lines[i])
	{
		delimiter_cnt_exit_if_invalid(lines[i], DELIM_3D);
		line = tm_split(lines[i], DELIM_3D);
		check_line_exit_if_invalid((const char **)line, DELIM_3D);
		tm_vertex_add_back(&vt, tm_new_vertex(
				tm_new_vector(xstrtod(line[0]),
					xstrtod(line[1]), xstrtod(line[2]))));
		free_double_pointer((void **)line);
		i += 1;
	}
	return (vt);
}

t_vertex	*create_obj(char **lines)
{
	int			i;
	char		**line;
	t_vertex	*vt;

	i = 0;
	vt = NULL;
	while (lines[i])
	{
		line = tm_split(lines[i], DELIM_OBJ);
		check_line_exit_if_invalid((const char **)line, FILE_TYPE_OBJ);
		if (strcmp(line[0], "v") == 0)
		{
			tm_vertex_add_back(&vt, tm_new_vertex(
					tm_new_vector(xstrtod(line[1]),
						xstrtod(line[2]), xstrtod(line[3]))));
		}
		free_double_pointer((void **)line);
		i += 1;
	}
	return (vt);
}

/**
 * @brief Create a model vertexes object
 * @param file_data
 * @param delimiter 3d->','  obj->' '
 */
t_vertex	*create_model_vertexes(const char *file_data, const int file_type)
{
	char		**lines;
	t_vertex	*vt;

	lines = tm_split(file_data, '\n');
	if (file_type == FILE_TYPE_3D)
		vt = create_3d(lines);
	if (file_type == FILE_TYPE_OBJ)
		vt = create_obj(lines);
	if (vt == NULL)
		print_error_exit("Invalid file format");
	free_double_pointer((void **)lines);
	return (vt);
}
