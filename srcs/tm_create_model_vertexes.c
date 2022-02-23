/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tm_create_model_vertexes.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuka < rmatsuka@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 23:28:01 by tkrm              #+#    #+#             */
/*   Updated: 2022/02/23 13:24:22 by rmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tm_create_model_vertexes.h"
#include "tm_check_file.h"
#include "term3d.h"

#define DELIM_OBJ ' '
#define DELIM_3D  ','
#define DELIM_3D_CNT  2

static void	check_line_exit_if_invalid(const char **lines, const char file_type)
{
	if (file_type == FILE_TYPE_3D && !check_line_3d(lines))
		print_error_exit("Invalid `.3d` file format");
	if (file_type == FILE_TYPE_OBJ && !check_line_obj(lines))
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
