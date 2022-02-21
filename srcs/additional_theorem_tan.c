/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_theorem_tan.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkanzaki <tkanzaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:05:53 by tkanzaki          #+#    #+#             */
/*   Updated: 2022/02/21 13:05:53 by tkanzaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "additional_theorem.h"

double	addition_theorem_tan(const double original_radian,
	const double additional_radian)
{
	const double	tan_a = tan(original_radian);
	const double	tan_b = tan(additional_radian);

	return ((tan_a + tan_b) / (1 - tan_a * tan_b));
}
