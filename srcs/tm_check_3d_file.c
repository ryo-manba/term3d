#include "tm_check_file.h"

bool	check_line_3d(const char **lines)
{
	if (lines[0] == NULL || \
		lines[1] == NULL || \
		lines[2] == NULL || \
		lines[3] != NULL)
		return (false);
	return (true);
}
