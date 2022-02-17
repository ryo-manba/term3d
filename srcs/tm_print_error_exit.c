#include "../includes/tm_utils.h"

void print_error_exit(const char *msg)
{
	if (msg)
		fprintf(stderr, "Error: %s\n", msg);
	else
		perror("Error");
	exit(EXIT_FAILURE);
}
