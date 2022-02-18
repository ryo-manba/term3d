#ifndef TM_WRAPPER_H
# define TM_WRAPPER_H

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>
#include <math.h>

void    *xmalloc(size_t size);
char	*xstrdup(const char *s);
FILE    *xfopen(const char * restrict path, const char * restrict mode);
void    xfclose(FILE *stream);
double	xstrtod(char *nptr);

#endif
