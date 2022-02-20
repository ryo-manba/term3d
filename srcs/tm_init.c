#include "tm_utils.h"
#include "tm_create_model_vertexes.h"

void	init_model_vertexes(t_vertex *vertexes[3], int nb_models, char **file_paths)
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
		vertexes[i] = create_model_vertexes(file_data, file_type);
		free(file_data);
		i += 1;
	}
	vertexes[nb_models] = NULL;
}

void init_pivots(t_vector3 *pivots, int nb_models)
{
	int	i;
	int	sign;

	sign = 1;
	i = 0;
	while (i < nb_models)
	{
		pivots[i].x = OBJ1_PIVOT_X * sign;
		pivots[i].y = OBJ1_PIVOT_Y * sign;
		pivots[i].z = OBJ1_PIVOT_Z * sign;
		sign *= 1;
		i += 1;
	}
}
