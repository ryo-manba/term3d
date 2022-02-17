#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>
#include <math.h>
#include "../includes/tm_wrapper.h"
#include "../includes/tm_utils.h"
#include "../includes/term3d.h"

//__attribute__((destructor))
//static void destructor() {
//    system("leaks -q a.out");
//}

# define BUF_SIZE 10000

void	check_line_exit_ifneed(char **strs)
{
	if (strs[0] == NULL || \
		strs[1] == NULL || \
		strs[2] == NULL)
		print_error_exit("Invalid file format"); // 要素が3つ未満
	if (strs[3] != NULL)
		print_error_exit("Invalid file format"); // 要素が4つ以上
}

void free_strs(char **strs)
{
	size_t	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i += 1;
	}
	free(strs[i]);
	free(strs);
}

// readする
t_vertex	*read_file(const char *file_path)
{
	char		line[10001];
	FILE 		*fp;
	char		**strs;
	char		*p;
	double		x;
	double		y;
	double		z;
	t_vertex	*vt = NULL;

	fp = xfopen(file_path, "r");
	int i = 0;
	while (true)
	{
		if (fgets(line, BUF_SIZE, fp) == NULL)
			break ;
		p = strchr(line, '\n');
		if (p)
			*p = '\0';

		strs = tm_split(line, ',');
		check_line_exit_ifneed(strs);
		x = xstrtod(strs[0]);
		y = xstrtod(strs[1]);
		z = xstrtod(strs[2]);
		free_strs(strs);
		tm_vertex_add_back(&vt,
							tm_new_vertex(
							tm_new_vector(x, y, z)));
		i += 1;
	}
	if (vt == NULL)
		print_error_exit("Invalid file format");
	xfclose(fp);
	return (vt);
}

void vt_all_free(t_vertex *vt)
{
	t_vertex *tmp;
	while (vt)
	{
		tmp = vt;
		vt = vt->next;
		free(tmp->position);
		free(tmp);
	}
}
