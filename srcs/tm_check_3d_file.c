/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tm_check_3d_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuka < rmatsuka@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:07:00 by rmatsuka          #+#    #+#             */
/*   Updated: 2022/02/23 15:07:01 by rmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tm_check_file.h"

bool	check_line_3d(const char **lines)
{
	if (lines[0] == NULL || \
		lines[1] == NULL || \
		lines[2] == NULL || \
		lines[3] != NULL)
		return (false);
	return (true);
}
