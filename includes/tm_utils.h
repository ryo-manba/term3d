/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tm_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuka < rmatsuka@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 23:28:01 by tkrm              #+#    #+#             */
/*   Updated: 2022/02/23 21:32:25 by rmatsuka         ###   ########.fr       */
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

/* models_utils */
void		models_rotate(t_model *models, const int nb_models);
void		models_rescale(t_model *models, int nb_models);

/* tm_destroy */
void		vertexes_destroy(t_vertex *vertexes);
void		models_destroy(t_model *models);

/* tm_check */
char		check_file_extensions(const char *filename);
void		check_argc_exit_if_invalid(const int argc);

/* tm_vector_utils */
t_vertex	*tm_new_vertex(const double x, const double y, const double z);
void		tm_vertex_add_back(t_vertex **vt, t_vertex *new);

/* tm_init */
void		models_init(
				t_model model[],
				const int nb_models, char **file_paths);

#endif
