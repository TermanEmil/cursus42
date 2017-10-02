/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dirent_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 20:25:01 by eterman           #+#    #+#             */
/*   Updated: 2017/01/08 20:25:03 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** I suspect that dirent->d_name on mac or on other machines would give full
** path of the file.
*/

char	*get_dirent_name(char *path, char *name)
{
	char	*result;
	char	*addr;

	if ((addr = ft_strchr(name, '/')) != NULL && addr[1] != 0)
		return (ft_strdup(name));
	else
	{
		result = ft_strnew_simple(ft_strlen(path) + ft_strlen(name) + 1);
		if (result == NULL)
			return (NULL);
		ft_strcpy(result, path);
		if (path[ft_strlen(path) - 1] != '/')
			ft_strcat(result, "/");
		ft_strcat(result, name);
		return (result);
	}
}
