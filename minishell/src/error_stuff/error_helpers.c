/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 09:40:34 by eterman           #+#    #+#             */
/*   Updated: 2017/01/17 10:07:14 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <errno.h>

/*
** Exits after printing the error
*/

void	ft_big_error(const char *msg)
{
	ft_fprintf(FT_STDERR, "{red}%s\n", msg);
	exit(EXIT_FAILURE);
}

/*
** Because ft_printf uses malloc.
*/

void	ft_error_mem(void)
{
	ft_putstr_fd(strerror(ENOMEM), FT_STDERR);
	ft_putchar_fd('\n', FT_STDERR);
	exit(EXIT_FAILURE);
}
