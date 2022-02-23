/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tm_vector_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuka < rmatsuka@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 23:28:01 by tkrm              #+#    #+#             */
/*   Updated: 2022/02/23 15:51:01 by rmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tm_utils.h"
#include "../includes/tm_wrapper.h"

t_vertex	*tm_new_vertex(const double x, const double y, const double z)
{
	t_vertex	*new;

	new = (t_vertex *)xmalloc(sizeof(t_vertex));
	new->position.x = x;
	new->position.y = y;
	new->position.z = z;
	new->next = NULL;
	new->prev = new;
	new->head = new;
	return (new);
}

void	tm_vertex_add_back(t_vertex **vt, t_vertex *new)
{
	t_vertex	*last;

	if (*vt == NULL)
		*vt = new;
	else
	{
		last = (*vt)->prev;
		last->next = new;
		new->prev = last;
		new->next = *vt;
		new->head = *vt;
		(*vt)->prev = new;
	}
}
