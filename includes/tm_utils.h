/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tm_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuka < rmatsuka@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 11:45:17 by rmatsuka          #+#    #+#             */
/*   Updated: 2022/02/20 11:45:18 by rmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TM_UTILS_H
# define TM_UTILS_H

# include <stdio.h>
# include <stdlib.h>
# include "term3d.h"

void		free_double_pointer(void **dp);
void		print_error_exit(const char *msg);
char		*tm_strjoin(char *s1, char *s2);
char		**tm_split(char const *s, char c);

/* tm_vector_utils */
t_vector3	*tm_new_vector(const double x, const double y, const double z);
t_vertex	*tm_new_vertex(t_vector3 *vec);
void		tm_vertex_add_back(t_vertex **vt, t_vertex *new);

#endif
