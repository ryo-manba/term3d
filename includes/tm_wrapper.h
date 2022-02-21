/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tm_wrapper.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkrm <tkrm@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 23:28:01 by tkrm              #+#    #+#             */
/*   Updated: 2022/02/20 23:29:20 by tkrm             ###   ########.fr       */
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
