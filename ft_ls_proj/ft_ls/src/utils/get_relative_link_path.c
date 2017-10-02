/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_relative_link_path.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 21:21:33 by eterman           #+#    #+#             */
/*   Updated: 2017/01/06 21:49:13 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	its_full_path(char *path)
{
	return (path != NULL && *path == '/');
}

/*
** First, checks if the target exists.
** Then, checks if paths is at the beggining of target.
*/

static int	its_relative_path(char *target, char *path)
{
	char	*addr;

	if (!ft_file_exists(target))
		return (0);
	if (path == NULL || ft_strlen(path) == 0)
		return (1);
	addr = ft_strstr(target, path);
	return (addr == target);
}

/*
** Carefully concatenates 2 paths. You can't just strjoin them, because you
** can have 'tests' and 'a_path' and the result must be 'tests/a_path'.
*/

static char	*get_relative_path(char *target, char *path)
{
	char	*result;

	if (its_full_path(target))
		return (ft_strdup(target));
	result = ft_strnew_simple(ft_strlen(target) + ft_strlen(path) + 1);
	ft_strcpy(result, path);
	if (result[ft_strlen(result) - 1] != '/' && path != NULL &&
		ft_strlen(path) != 0)
		ft_strcat(result, "/");
	ft_strcat(result, target);
	return (result);
}

/*
** Given a readlink result here, and a the current path, you get a fully
** working path.
** It checks if it's a full path (/home/ ....), then, it checks if it's a
** relative path to path (tests/just_a_dir/dir_a && tests == relative),
** else, it carefully concatenates the 2 paths. Then it checks if the result
** is existent, else, an error is thrown and NULL is returned.
*/

char		*get_relative_link_path(char *l_path, char *path)
{
	char	*result;
	char	*aux;

	if (its_full_path(l_path) || its_relative_path(l_path, path))
		result = ft_strdup(l_path);
	else
	{
		aux = ft_strdup(path);
		*point_to_last(aux) = 0;
		result = get_relative_path(l_path, aux);
		free(aux);
	}
	return (result);
}
