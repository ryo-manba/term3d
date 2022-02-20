/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tm_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuka < rmatsuka@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 11:45:17 by rmatsuka          #+#    #+#             */
/*   Updated: 2022/02/20 19:55:26 by rmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TM_UTILS_H
# define TM_UTILS_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "term3d.h"

void		free_double_pointer(void **dp);
void		print_error_exit(const char *msg);
char		*tm_strjoin(char *s1, char *s2);
char		**tm_split(char const *s, char c);

/* tm_destroy */
void		vertexes_destroy(t_vertex **vertexes);
void		destroy_all(t_vertex **vertexes, t_camera *camera);

/* tm_check */
char		check_file_extensions(const char *filename);
void		check_argc_exit_if_invalid(int argc);

/* tm_vector_utils */
t_vector3	*tm_new_vector(const double x, const double y, const double z);
t_vertex	*tm_new_vertex(t_vector3 *vec);
void		tm_vertex_add_back(t_vertex **vt, t_vertex *new);

/* tm_init */
void		init_model_vertexes(
				t_vertex *vertexes[MAX_MODEL_SIZE],
				int nb_models, char **file_paths);
void		init_pivots(t_vector3 *pivots, int nb_models);

#endif
