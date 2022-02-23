/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tm_check_obj_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuka < rmatsuka@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:06:56 by rmatsuka          #+#    #+#             */
/*   Updated: 2022/02/23 15:06:57 by rmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tm_check_file.h"

/**
 * <obj file format>
 * #      : Comments
 * mtllib : material file name
 * g      : group name
 * o      : Object name
 * s      : smooth shading toggle
 * usemtl : material name
 * v      : x-component value y-component value z-component value
 * vt     : x-component value y-component value
 * vn     : x-component value y-component value z-component value
 * f      : vertex coordinate number/
 *          texture coordinate number/
 *          vertex normal vector number
 */
int	check_obj_type(const char *keyword)
{
	if (strcmp(keyword, "#") == 0)
		return (OBJ_COMMENT);
	if (strcmp(keyword, "o") == 0)
		return (OBJ_NAME);
	if (strcmp(keyword, "s") == 0)
		return (OBJ_SMOOTH_SHADING);
	if (strcmp(keyword, "mtllib") == 0)
		return (OBJ_MTLLIB);
	if (strcmp(keyword, "g") == 0)
		return (OBJ_GROUP);
	if (strcmp(keyword, "usemtl") == 0)
		return (OBJ_USEMTL);
	if (strcmp(keyword, "v") == 0)
		return (OBJ_VERTEX_COORDINATE_VALUE);
	if (strcmp(keyword, "vt") == 0)
		return (OBJ_VERTEX_TEXTURE);
	if (strcmp(keyword, "vn") == 0)
		return (OBJ_VERTEX_NORMAL_VECTOR);
	if (strcmp(keyword, "f") == 0)
		return (OBJ_POLYGONAL_SUFACE_DATA);
	return (OBJ_NONEXISTENT_KEYWORD);
}

/**
 * @brief Check that the keyword and number of elements are correct.
 */
bool	check_line_obj(const char **line)
{
	int	type;
	int	i;

	if (line[0] == NULL)
		return (false);
	type = check_obj_type(line[0]);
	if (type == OBJ_NONEXISTENT_KEYWORD)
		return (false);
	i = 1;
	if (type == OBJ_VERTEX_COORDINATE_VALUE)
	{
		while (i < 4)
		{
			if (line[i] == NULL)
				return (false);
			i += 1;
		}
		if (line[i] != NULL)
			return (false);
	}
	return (true);
}
