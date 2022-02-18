#include <stdlib.h>
#include <string.h>
#include "tm_wrapper.h"

static void	all_free(char **split_strs, size_t i)
{
	while (i)
	{
		free(split_strs[i]);
		i -= 1;
	}
	free(split_strs);
}

static char	*ft_strcpy(char const *s, char c)
{
	char	*dest;
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	dest = (char *)xmalloc(sizeof(char) * (i + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static size_t	get_len(char const *s, char c)
{
	size_t	i;
	size_t	cnt;

	i = 0;
	cnt = 0;
	if (s[i] && s[i] != c)
		cnt++;
	while (i < strlen(s))
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1])
			cnt++;
		i++;
	}
	return (cnt);
}

static void	*get_split(char **split_strs, char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s && *s != c)
		{
			split_strs[i] = ft_strcpy(s, c);
			if (split_strs[i] == NULL)
			{
				all_free(split_strs, i);
				return (NULL);
			}
			i += 1;
			while (*s && *s != c)
				s++;
		}
	}
	split_strs[i] = NULL;
	return (split_strs);
}

char	**tm_split(char const *s, char c)
{
	char	**split_strs;
	size_t	split_len;

	if (s == NULL)
		return (NULL);
	split_len = get_len(s, c);
	split_strs = (char **)xmalloc(sizeof(char *) * (split_len + 1));
	if (split_strs == NULL)
		return (NULL);
	get_split(split_strs, s, c);
	return (split_strs);
}
