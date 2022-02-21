/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkrm <tkrm@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 23:28:01 by tkrm              #+#    #+#             */
/*   Updated: 2022/02/20 23:28:01 by tkrm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vertex.h"
#include "additional_theorem.h"

static double	vector2_magnitude(const double vector2_x,
					const double vector2_y);

void	vertex_rotate(double *horizontal, double *vertical,
	const double additional_radian)
{
	double	before;
	double	after;

	before = vector2_magnitude(*horizontal, *vertical);
	*horizontal = addition_theorem_cos(*horizontal,
			*vertical, additional_radian);
	*vertical = addition_theorem_sin(*horizontal, *vertical, additional_radian);
	after = vector2_magnitude(*horizontal, *vertical);
	*horizontal *= before / after;
	*vertical *= before / after;
}

static double	vector2_magnitude(const double vector2_x,
	const double vector2_y)
{
	double	square_magnitude;

	square_magnitude = vector2_x * vector2_x + vector2_y * vector2_y;
	return (sqrt(square_magnitude));
}
