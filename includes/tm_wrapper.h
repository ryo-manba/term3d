/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tm_wrapper.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuka < rmatsuka@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 11:45:13 by rmatsuka          #+#    #+#             */
/*   Updated: 2022/02/20 11:45:14 by rmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TM_WRAPPER_H
# define TM_WRAPPER_H

# include <stdio.h>
# include <stdbool.h>
# include <string.h>
# include <stdlib.h>
# include <errno.h>
# include <ctype.h>
# include <math.h>

void	*xmalloc(size_t size);
char	*xstrdup(const char *s);
FILE	*xfopen(const char *path, const char *mode);
void	xfclose(FILE *stream);
double	xstrtod(char *nptr);

#endif
