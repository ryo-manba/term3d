/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkanzaki <tkanzaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 23:28:01 by tkrm              #+#    #+#             */
/*   Updated: 2022/02/23 03:55:28 by tkanzaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VERTEX_H
# define VERTEX_H

# include "term3d.h"

void	vertex_rotateall(t_vertex *model_vertexes,
			const t_axis axis,
			const int angle,
			const t_vector3 *pivot);
void	vertex_rotate(double *horizontal,
			double *vertical,
			const double additional_radian);
void	vertex_enlarge(t_vertex *model_vertexes,
			const int expansion_rate);

#endif
