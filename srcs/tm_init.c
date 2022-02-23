/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tm_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuka < rmatsuka@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 23:28:01 by tkrm              #+#    #+#             */
/*   Updated: 2022/02/23 21:32:09 by rmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tm_utils.h"
#include "tm_create_model_vertexes.h"

void	models_init(
		t_model models[], const int nb_models, char **file_paths)
{
	char	*file_data;
	char	*file_name;
	char	file_type;
	int		i;

	i = 0;
	while (i < nb_models)
	{
		file_name = file_paths[i];
		file_type = check_file_extensions(file_name);
		file_data = read_file(file_name);
		models[i].vertexes = create_model_vertexes(file_data, file_type);
		models[i].pivot.x = OBJ_PIVOT_X * i;
		models[i].pivot.y = OBJ_PIVOT_Y * i;
		models[i].pivot.z = OBJ_PIVOT_Z * i;
		free(file_data);
		i += 1;
	}
	models[nb_models].vertexes = NULL;
}
