/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 11:49:24 by eterman           #+#    #+#             */
/*   Updated: 2017/01/03 12:08:04 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

#ifndef FT_STDERR
# define FT_STDERR 2
#endif

int		print_malloc_err(void)
{
	ft_fprintf(FT_STDERR, "{bg_red}{black}ls: %s\n", strerror(errno));
	return (-1);
}

int		print_file_doesnt_ex(char *path)
{
	ft_fprintf(FT_STDERR, "{red}ls: cannot access '%s': %s\n",
				path, strerror(errno));
	return (-1);
}

int		print_error(CHR *msg)
{
	char	buff[20];

	ft_putstr_fd(rgb_color(1, 1, buff), FT_STDERR);
	ft_putstr_fd(msg, FT_STDERR);
	ft_putstr_fd(CL_EOC, FT_STDERR);
	ft_putchar_fd('\n', FT_STDERR);
	return (-1);
}
