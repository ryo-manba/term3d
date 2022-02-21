/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_theorem_cos.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkanzaki <tkanzaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:06:00 by tkanzaki          #+#    #+#             */
/*   Updated: 2022/02/21 13:06:00 by tkanzaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "additional_theorem.h"

double	addition_theorem_cos(const double vector2_x,
	const double vector2_y, const double additional_radian)
{
	return (vector2_x * cos(additional_radian)
		- vector2_y * sin(additional_radian));
}
