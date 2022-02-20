#include "tm_utils.h"

char	check_file_extensions(const char *filename)
{
	char	*p;

	p = strrchr(filename, '.');
	if (p == NULL)
		print_error_exit("Invalid extension");
	else if (strcmp(p, ".3d") == 0)
		return (FILE_TYPE_THREED);
	else if (strcmp(p, ".obj") == 0)
		return (FILE_TYPE_OBJ);
	print_error_exit("Invalid extension");
	return ('*');
}

void	check_argc_exit_if_invalid(int argc)
{
	if (argc >= 2)
		return ;
	printf("Usage: ./term3d file_path\n");
	exit(EXIT_FAILURE);
}
