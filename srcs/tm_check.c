/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tm_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuka < rmatsuka@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 23:28:00 by tkrm              #+#    #+#             */
/*   Updated: 2022/02/23 21:27:06 by rmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tm_utils.h"

char	check_file_extensions(const char *filename)
{
	char	*p;

	p = strrchr(filename, '.');
	if (p == NULL)
		print_error_exit("Invalid extension");
	else if (strcmp(p, ".3d") == 0)
		return (FILE_TYPE_3D);
	else if (strcmp(p, ".obj") == 0)
		return (FILE_TYPE_OBJ);
	print_error_exit("Invalid extension");
	return (FILE_TYPE_INVALID);
}

void	check_argc_exit_if_invalid(const int argc)
{
	if (2 <= argc && argc - 1 <= MAX_MODEL_SIZE)
		return ;
	else
		printf(""
			"Usage: ./term3d file_path (Object max is %d)\n", MAX_MODEL_SIZE);
	exit(EXIT_FAILURE);
}
