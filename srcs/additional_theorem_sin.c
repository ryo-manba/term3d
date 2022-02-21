/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_theorem_sin.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkanzaki <tkanzaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:05:56 by tkanzaki          #+#    #+#             */
/*   Updated: 2022/02/21 13:05:57 by tkanzaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "additional_theorem.h"

double	addition_theorem_sin(const double vector2_x,
	const double vector2_y, const double additional_radian)
{
	return (vector2_y * cos(additional_radian)
		+ vector2_x * sin(additional_radian));
}
