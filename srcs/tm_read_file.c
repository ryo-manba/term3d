#include "tm_wrapper.h"
#include "tm_utils.h"
#include "term3d.h"

#define BUF_SIZE 10000

char	*read_file(const char *file_path)
{
	char	buf[BUF_SIZE];
	char	*file_data;
	char	*tmp;
	FILE	*fp;

	fp = xfopen(file_path, "r");
	file_data = NULL;
	while (true)
	{
		if (fgets(buf, BUF_SIZE - 1, fp) == NULL)
			break ;
		if (file_data == NULL)
		{
			file_data = xstrdup(buf);
		}
		else
		{
			tmp = file_data;
			file_data = tm_strjoin(tmp, buf);
			free(tmp);
		}
	}
	xfclose(fp);
	return (file_data);
}