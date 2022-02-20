/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tm_print_error_exit.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkrm <tkrm@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 23:28:01 by tkrm              #+#    #+#             */
/*   Updated: 2022/02/20 23:28:01 by tkrm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tm_utils.h"

#define RESET  "\033[0m"
#define YELLOW "\033[33m"

void	print_error_exit(const char *msg)
{
	if (msg)
		fprintf(stderr, "%sError: %s%s\n", YELLOW, msg, RESET);
	else
		perror("Error");
	exit(EXIT_FAILURE);
}
