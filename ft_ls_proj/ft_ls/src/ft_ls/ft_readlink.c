/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readlink.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 18:24:54 by eterman           #+#    #+#             */
/*   Updated: 2017/01/06 18:49:04 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char	*try_readlink(char *path, ssize_t size)
{
	char	*l_name;
	int		ret;

	errno = 0;
	l_name = ft_strnew_simple(size);
	if (l_name == NULL)
		return (NULL);
	ret = readlink(path, l_name, size);
	if (ret == size)
	{
		free(l_name);
		return (NULL);
	}
	else if (ret == -1)
	{
		free(l_name);
		return (NULL);
	}
	l_name[ret] = 0;
	return (l_name);
}

/*
** When you ls /proc/self, the size may be zero, but it is a link !
** So stat.st_size == 0, so I must try with my own size.
*/

char		*ft_readlink(char *path, ssize_t starting_size)
{
	ssize_t	size;
	char	*result;

	size = starting_size;
	while ((result = try_readlink(path, size)) == NULL)
	{
		if (size > 20480)
		{
			ft_fprintf(FT_STDERR, "{cyan}ls: Failed to readlink\n");
			return (NULL);
		}
		if (errno == ENOMEM)
		{
			print_malloc_err();
			return (NULL);
		}
		else if (errno == EACCES)
		{
			ft_fprintf(FT_STDERR, "{red}ls: cannot read symbolic link"
				"'%s': %s\n", path, strerror(errno));
			return (NULL);
		}
		size += 50;
	}
	return (result);
}
