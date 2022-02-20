/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkanzaki <tkanzaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 06:24:50 by tkanzaki          #+#    #+#             */
/*   Updated: 2022/02/20 06:24:51 by tkanzaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

void	display_init(char display[][DISPLAY_WIDTH])
{
	int	x;
	int	y;

	y = 0;
	while (y < DISPLAY_HEIGHT)
	{
		x = 0;
		while (x < DISPLAY_WIDTH - 1)
		{
			display[y][x] = ' ';
			x++;
		}
		display[y][x] = '\0';
		y++;
	}
}
