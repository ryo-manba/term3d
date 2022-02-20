#include "tm_wrapper.h"

char	*tm_strjoin(const char *s1, const char *s2)
{
	char	*joined_str;
	size_t	i;
	size_t	j;

	joined_str = (char *)xmalloc(sizeof(char) * (strlen(s1) + strlen(s2) + 1));
	i = 0;
	while (s1[i])
	{
		joined_str[i] = s1[i];
		i += 1;
	}
	j = 0;
	while (s2[j])
	{
		joined_str[i] = s2[j];
		i += 1;
		j += 1;
	}
	joined_str[i] = '\0';
	return (joined_str);
}
