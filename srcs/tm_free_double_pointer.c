#include "tm_utils.h"

void	free_double_pointer(void **dp)
{
	size_t	i;

	i = 0;
	while (dp[i])
	{
		free(dp[i]);
		i += 1;
	}
	free(dp[i]);
	free(dp);
}
