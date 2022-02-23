/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tm_create_model_vertexes.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuka < rmatsuka@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 23:28:01 by tkrm              #+#    #+#             */
/*   Updated: 2022/02/23 13:13:24 by rmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TM_CREATE_MODEL_VERTEXES_H
# define TM_CREATE_MODEL_VERTEXES_H

# include "tm_wrapper.h"
# include "tm_utils.h"
# include "term3d.h"

t_vertex	*create_model_vertexes(const char *file_data, const char delimiter);

#endif
