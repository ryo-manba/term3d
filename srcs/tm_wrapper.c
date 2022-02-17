#include "tm_wrapper.h"
#include "tm_utils.h"

void *xmalloc(size_t size)
{
	void *p;

	p = malloc(size);
	if (!p)
		print_error_exit(NULL);
	return (p);
}

FILE *xfopen(const char * restrict path, const char * restrict mode)
{
	FILE *fp;

	fp = fopen(path, mode);
	if (!fp)
		print_error_exit(NULL);
	return (fp);
}

void xfclose(FILE *stream)
{
	if (fclose(stream) != 0)
		print_error_exit(NULL);
}

double	xstrtod(char *nptr)
{
	double	f;
	char	*endptr;

	printf("nptr = [%s]\n", nptr);
	if (!nptr)
	{
		puts("A");
		print_error_exit(NULL);
	}
	f = strtod(nptr, &endptr);
	if (errno != ERANGE)
	{
		if (*endptr != '\0') // 数値以外の文字が入っている場合
		{
			puts("B");
			print_error_exit(NULL);
		}
	}
	else if (f == HUGE_VAL) // doubleで扱える範囲を超えた場合
	{
		puts("C");
		print_error_exit(NULL);
	}
	return (f);
}
