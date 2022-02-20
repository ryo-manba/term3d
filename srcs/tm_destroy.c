#include "tm_utils.h"
#include "camera.h"

void destroy_all(t_vertex **vertexes, t_camera *camera)
{
	vertexes_destroy(vertexes);
	camera_destroy(camera); // 構造体を解放
}

void	vertexes_destroy(t_vertex **vertexes)
{
	t_vertex *vt;
	t_vertex *tmp;
	int	i;

	i = 0;
	while (vertexes[i])
	{
		vt = vertexes[i];
		while (vt)
		{
			tmp = vt;
			vt = vt->next;
			free(tmp->position);
			free(tmp);
		}
		i += 1;
	}
	free(vertexes[i]);
}
