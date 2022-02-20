/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkanzaki <tkanzaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 06:24:48 by tkanzaki          #+#    #+#             */
/*   Updated: 2022/02/20 06:24:48 by tkanzaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

void	display_print(char display[][DISPLAY_WIDTH])
{
	int	y;

	y = 0;
	while (y < DISPLAY_HEIGHT)
	{
		printf("%s\n", display[y]);
		y++;
	}
}
