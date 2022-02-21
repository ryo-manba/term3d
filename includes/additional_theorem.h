/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_theorem.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkanzaki <tkanzaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:06:04 by tkanzaki          #+#    #+#             */
/*   Updated: 2022/02/21 13:07:38 by tkanzaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ADDITIONAL_THEOREM_H
# define ADDITIONAL_THEOREM_H

# include "term3d.h"

double	addition_theorem_sin(const double vector2_x,
			const double vector2_y, const double additional_radian);
double	addition_theorem_cos(const double vector2_x,
			const double vector2_y, const double additional_radian);
double	addition_theorem_tan(const double original_radian,
			const double additional_radian);

#endif
