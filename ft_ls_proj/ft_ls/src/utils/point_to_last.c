/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_to_last.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 18:14:27 by eterman           #+#    #+#             */
/*   Updated: 2017/01/04 18:39:17 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Given a path, retruns a pointer to the last name:
** /dir1/dir2/name
** /dir1/dir2/name/
** name
*/

char	*point_to_last(char *path)
{
	char	*addr;

	if (path == NULL)
		return (NULL);
	addr = ft_strrchr(path, '/');
	if (addr == NULL)
		return (path);
	if (addr[1] == 0)
	{
		addr--;
		while (*addr != '/' && addr != path)
			addr--;
		if (*addr == '/')
			return (addr + 1);
		else
			return (addr);
	}
	else
		return (addr + 1);
}
