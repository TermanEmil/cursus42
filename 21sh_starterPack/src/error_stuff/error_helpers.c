/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 09:40:34 by eterman           #+#    #+#             */
/*   Updated: 2017/06/22 18:28:46 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <errno.h>

/*
** Exits after printing the error
*/

void	ft_big_error(const char *msg)
{
	ft_fprintf(STDERR, "{red}%s\n", msg);
	exit(EXIT_FAILURE);
}

/*
** Because ft_printf uses malloc.
*/

void	ft_error_mem(void)
{
	ft_putstr_fd(strerror(ENOMEM), STDERR);
	ft_putchar_fd('\n', STDERR);
	exit(EXIT_FAILURE);
}
