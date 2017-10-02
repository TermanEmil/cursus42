/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 15:05:02 by eterman           #+#    #+#             */
/*   Updated: 2017/02/20 18:17:12 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_errors.h"

void		print_proj_name(int fd)
{
	if (ft_err_get_proj_name(NULL))
	{
		ft_putstr_fd(ft_err_get_proj_name(NULL), fd);
		ft_putstr_fd(": ", fd);
	}
}

/*
** Prints a message on stderr
*/

void		ft_err(const char *msg)
{
	ft_putstr_fd(msg, STDERR);
	ft_putchar_fd('\n', STDERR);
}

/*
** After printing a message on stderr, exits.
*/

void		ft_fatal(const char *msg)
{
	ft_err(msg);
	exit(EXIT_FAILURE);
}

/*
** Prints a fatal error about memory alocation.
*/

void		ft_err_mem(int exit_program)
{
	print_proj_name(STDERR);
	ft_err("Cannot allocate memory");
	if (exit_program)
		exit(EXIT_FAILURE);
}

/*
** Prints a message, with the project name in from of the message.
*/

int			ft_proj_err(const char *msg, int exit_program)
{
	print_proj_name(STDERR);
	ft_err(msg);
	if (exit_program)
		exit(EXIT_FAILURE);
	return (-1);
}
