#include "../includes/tm_utils.h"

#define RESET  "\033[0m"
#define YELLOW "\033[33m"

void print_error_exit(const char *msg)
{
	if (msg)
		fprintf(stderr, "%sError: %s%s\n", YELLOW, msg, RESET);
	else
		perror("Error");
	exit(EXIT_FAILURE);
}
