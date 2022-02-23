/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tm_vector_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkanzaki <tkanzaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 23:28:01 by tkrm              #+#    #+#             */
/*   Updated: 2022/02/23 06:20:28 by tkanzaki         ###   ########.fr       */
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
	new->last = new;
	return (new);
}

/**
 *  lst1, lst2, lst3->lst4
 *
 *  add_back(&lst1, lst2)
 *  lst1->last(lst1)->next = lst2
 *  lst1->last = lst2->last(lst2)
 *
 *  add_back(&lst1, lst3)
 *  lst1->last(lst2)->next = lst3
 *  lst1->last = lst3->last(lst4)
 */
void	tm_vertex_add_back(t_vertex **vt, t_vertex *new)
{
	if (*vt == NULL)
		*vt = new;
	else
	{
		(*vt)->last->next = new;
		(*vt)->last = new->last;
	}
}
