#include "tm_wrapper.h"
#include "tm_utils.h"

void	*xmalloc(size_t size)
{
	void	*p;

	p = malloc(size);
	if (!p)
		print_error_exit(NULL);
	return (p);
}

FILE	*xfopen(const char *path, const char *mode)
{
	FILE	*fp;

	fp = fopen(path, mode);
	if (!fp)
		print_error_exit(NULL);
	return (fp);
}

void	xfclose(FILE *stream)
{
	if (fclose(stream) != 0)
		print_error_exit(NULL);
}

double	xstrtod(char *s)
{
	double	d;
	char	*err;

	if (!s)
		print_error_exit(NULL);
	d = strtod(s, &err);
	if (errno != ERANGE)
	{
		if (*err != '\0')
			print_error_exit(NULL);
	}
	else if (d == HUGE_VAL)
		print_error_exit(NULL);
	return (d);
}

char	*xstrdup(const char *s)
{
	char	*copy;

	copy = strdup(s);
	if (copy == NULL)
		print_error_exit(NULL);
	return (copy);
}
