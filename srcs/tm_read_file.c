/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tm_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuka < rmatsuka@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 23:28:01 by tkrm              #+#    #+#             */
/*   Updated: 2022/02/21 21:29:22 by rmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			file_data = xstrdup(buf);
		else
		{
			tmp = file_data;
			file_data = tm_strjoin(tmp, buf);
			free(tmp);
		}
	}
	if (file_data == NULL)
		print_error_exit("File is empty");
	xfclose(fp);
	return (file_data);
}
